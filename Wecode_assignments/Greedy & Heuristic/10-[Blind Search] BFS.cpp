#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

vector<string> getInputVertices(int numVertices) {
    vector<string> vertices(numVertices);
    for (int i = 0; i < numVertices; i++) {
        cin >> vertices[i];
    }
    return vertices;
}

vector<vector<int>> getInputGraph(int numVertices) {
    vector<vector<int>> graph(numVertices, vector<int>(numVertices));
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            cin >> graph[i][j];
        }
    }
    return graph;
}

bool isNodeFound(int currNode, int endNode) {
    return currNode == endNode;
}

void markNodeAsVisited(int node, vector<bool>& visitedNodes) {
    visitedNodes[node] = true;
}

void enqueueNode(int node, queue<int>& nodeQueue) {
    nodeQueue.push(node);
}

void updateParentNode(int childNode, int parentNode, vector<int>& parentNodes) {
    parentNodes[childNode] = parentNode;
}

bool bfsTraversal(const vector<vector<int>>& adjacencyMatrix, int startNode, int endNode, vector<bool>& visitedNodes, vector<int>& parentNodes, int& expandedNodes) {
    queue<int> nodeQueue;
    nodeQueue.push(startNode);
    visitedNodes[startNode] = true;
    parentNodes[startNode] = -1;
    expandedNodes = 0;

    while (!nodeQueue.empty()) {
        int currNode = nodeQueue.front();
        nodeQueue.pop();
        expandedNodes++;
        if (isNodeFound(currNode, endNode)) {
            return true;
        }
        for (int j = 0; j < adjacencyMatrix.size(); j++) {
            if (adjacencyMatrix[currNode][j] != 0 && !visitedNodes[j]) {
                enqueueNode(j, nodeQueue);
                markNodeAsVisited(j, visitedNodes);
                updateParentNode(j, currNode, parentNodes);
            }
        }
    }

    return false;
}

void printPath(const vector<string>& nodeNames, const vector<int>& path) {
    for (int j = path.size() - 1; j >= 0; j--) {
        cout << nodeNames[path[j]] << " ";
    }
    cout << endl;
}

int calculateDistance(const vector<vector<int>>& adjacencyMatrix, const vector<int>& parentNodes, int endNode) {
    int distance = 0;
    int currNode = endNode;
    while (currNode != -1) {
        if (parentNodes[currNode] != -1) {
            distance += adjacencyMatrix[parentNodes[currNode]][currNode];
        }
        currNode = parentNodes[currNode];
    }
    return distance;
}

void processGraph() {
    int numVertices, numQueries;
    cin >> numVertices >> numQueries;

    vector<string> nodeNames = getInputVertices(numVertices);
    vector<vector<int>> adjacencyMatrix = getInputGraph(numVertices);

    for (int i = 0; i < numQueries; i++) {
        string startNodeName, endNodeName;
        cin >> startNodeName >> endNodeName;
        int startNode = -1, endNode = -1;
        for (int j = 0; j < numVertices; j++) {
            if (nodeNames[j] == startNodeName) {
                startNode = j;
            }
            if (nodeNames[j] == endNodeName) {
                endNode = j;
            }
        }
        if (startNode == -1 || endNode == -1) {
            cout << "-unreachable-" << endl << "0 0" << endl;
            continue;
        }

        vector<bool> visitedNodes(numVertices, false);
        vector<int> parentNodes(numVertices);
        int expandedNodes = 0;

        if (!bfsTraversal(adjacencyMatrix, startNode, endNode, visitedNodes, parentNodes, expandedNodes)) {
            cout << "-unreachable-" << endl << expandedNodes << " 0" << endl;
            continue;
        }

        vector<int> path;
        int currNode = endNode;
        while (currNode != -1) {
            path.push_back(currNode);
            currNode = parentNodes[currNode];
        }
        printPath(nodeNames, path);

        int distance = calculateDistance(adjacencyMatrix, parentNodes, endNode);
        cout << expandedNodes << " " << distance << endl;
    }
}

int main() {
    processGraph();
    return 0;
}