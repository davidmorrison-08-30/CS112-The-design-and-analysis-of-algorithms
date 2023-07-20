#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int min(vector<int> sumtime) 
{
    int a = sumtime[0];
    int ind = 0;
    for (int i = 1; i < sumtime.size(); i++)
    {
        if (a > sumtime[i])
        {
            a = sumtime[i];
            ind = i;
        }
    }
    return ind;
}

void task_assignment(vector<int> sumtime, vector<pair<int, int>> tasks, vector<int> sol, int n, int m)
{
    int ind;
    for (int i = 0; i < n; i++) 
    {
        ind = min(sumtime);
        sol[tasks[i].second] = ind;
        sumtime[ind] += tasks[i].first;
    }
    for (int i = 0; i < n; i++) 
        cout << sol[i] << " ";
}

int main() 
{
    int n, m;
    cin >> n >> m;
    vector<int> sumtime(m, 0);
    vector<pair<int, int>> tasks;
    vector<int> sol(n, 0);
    for (int i = 0; i < n; i++) 
    {
        int t;
        cin >> t;
        tasks.push_back(make_pair(t, i));
    }
    sort(tasks.begin(), tasks.end());
    reverse(tasks.begin(), tasks.end());
    task_assignment(sumtime, tasks, sol, n, m);
    return 0;
}