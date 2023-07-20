#include <iostream>
#include <vector>
#include <map>

using namespace std;

bool check(vector<string> result, string s)
{
    for (int i = 0; i < result.size(); i++)
        if (result[i] == s)
            return true;
    return false;
}

void print(vector<string> result)
{
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
}

int main() 
{
    int e, x;
    string s, head, bottom;
    map<string, map<string, int>> graph;
    map<string, map<string, int>>::iterator itr;
    map<string, int>::iterator itr_2;
    vector<string> result;
    vector<string> point;
    int min = 10000;
    string z;

    cin >> e >> s;

    for (int i = 0; i < e; i++) 
    {
        cin >> head >> bottom >> x;
        graph[head][bottom] = x;
    }

    result.push_back(s);

    for (itr = graph.begin(); itr != graph.end(); itr++) 
        point.push_back(itr->first);

    for (int j = 0; j < point.size() - 1; j++) 
    {
        string y;
        min = 10000;
        for (int i = 0; i < point.size(); i++) 
        {
            if (check(result, point[i]) == 0)
            {
                y = point[i];
                if (min > graph[s][y]) 
                {
                    min = graph[s][y];
                    z = y;
                }
            }
        }
        result.push_back(z);
        s = z;
    }
    result.push_back(result[0]);
    print(result);
    return 0;
}