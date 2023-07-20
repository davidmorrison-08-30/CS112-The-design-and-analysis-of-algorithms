#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

int main() 
{
    int e = 0, num_of_vertices = 0;
    map<string, set<string>> adj_list;
    map<string, set<string>>::iterator pointer;

    cin >> e;
    for (int i = 0; i < e; i++) 
    {
        string v1, v2;
        cin >> v1 >> v2;
        if (adj_list[v1].empty())
            num_of_vertices++;
        adj_list[v1].insert(v2);
    }

    for (pointer = adj_list.begin(); pointer != adj_list.end(); pointer++)
    {
        if (num_of_vertices != (pointer->second.size() + 1))
        {
            cout << "FALSE";
            return 0;
        }
    }
    cout << "TRUE";
    return 0;
}