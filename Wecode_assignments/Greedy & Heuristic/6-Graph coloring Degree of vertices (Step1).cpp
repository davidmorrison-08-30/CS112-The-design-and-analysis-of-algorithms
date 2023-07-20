#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

void print(vector<int> result) 
{
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
}

int main() 
{
    int v, e;
    cin >> v >> e;
    map<string, set<string>> point;
    map<string, set<string>>::iterator pointer;
    vector<string> heads;
    vector<int> result;

    for (int i = 0; i < v; i++) 
    {
        string c;
        cin >> c;
        heads.push_back(c);
    }

    for (int i = 0; i < e; i++) 
    {
        string a, b;
        cin >> a >> b;
        point[a].insert(b);
        point[b].insert(a);
    }

    for (int i = 0; i < v; i++) 
    {
        int count = 0;
        for (pointer = point.begin(); pointer != point.end(); pointer++)
        {
            if (pointer->first == heads[i])
            {
                result.push_back(pointer->second.size());
                count++;
            }
        }
        if (count == 0) 
            result.push_back(0);
    }

    print(result);
    return 0;
}