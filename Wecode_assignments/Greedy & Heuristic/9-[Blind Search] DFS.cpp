# include <iostream>
# include <vector>
# include <map>
# include <string>
# include <set>
using namespace std;


void input(int v, int n, vector<vector<int>>& adj_matrix, vector<string>& v_names)
{
    for (int i = 0; i < v; i++)
    {
        string name;
        cin >> name;
        v_names.push_back(name);
    }

    adj_matrix = vector<vector<int>>(v, vector<int>(v, 0));

    for (int i = 0; i < v; i++)
    {
        int weight;
        for (int j = 0; j < v; j++)
        {
            cin >> weight;
            adj_matrix[i][j] = weight;
        }
    }
}


bool DFS(int current, int end, vector<vector<int>>& adj_matrix, vector<string>& v_names, set<string>& visited, vector<string>& path, int& length)
{
    if (current == end)
        return true;

    for (int i = v_names.size() - 1; i >= 0; i--)
    {
        if (adj_matrix[current][i] == 0)
            continue;

        auto pos = visited.find(v_names[i]);
        if (pos != visited.end())
            continue;

        length += adj_matrix[current][i];
        visited.insert(v_names[i]);
        path.push_back(v_names[i]);

        DFS(i, end, adj_matrix, v_names, visited, path, length);

        length -= adj_matrix[current][i];
        path.pop_back();
    }
    return false;
}

void findPath(int v, int n, vector<vector<int>>& adj_matrix, vector<string>& v_names)
{
    for (int i = 0; i < n; i++)
    {
        string start, end;
        set<string> visited;
        vector<string> path;
        cin >> start >> end;
        visited.insert(start);
        path.push_back(start);

        int head, tail;
        for (int i = 0; i < v_names.size(); i++)
        {
            if (v_names[i] == start)
                head = i;
            if (v_names[i] == end)
                tail = i;
        }

        int length = 0;

        bool result = DFS(head, tail, adj_matrix, v_names, visited, path, length);

        if (!result)
            cout << "-unreachable-" << endl << visited.size() << " " << length << endl;
        else
        {
            for (int i = 0; i < path.size(); i++)
                cout << path[i] << " ";
            cout << endl << visited.size() << " " << length << endl;
        }
    }
}

int main()
{
    int v, n;
    vector<vector<int>> adj_matrix;
    vector<string> v_names;
    cin >> v >> n;

    input(v, n, adj_matrix, v_names);

    findPath(v, n, adj_matrix, v_names);

    return 0;
}