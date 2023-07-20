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

void task_assignment(vector<int> sumtime, vector<vector<int>> tasks, vector<int> res, int n, int m)
{
    int ind;
    for (int i = 0; i < n; i++) 
    {
        vector<int> temp;
        int temp_sum = 0;
        for (int j = 0; j < m; j++) 
        {
            temp_sum = sumtime[j] + tasks[j][i];
            temp.push_back(temp_sum);
        }
        ind = min(temp);
        res[i] = ind;
        sumtime[ind] += tasks[ind][i];
    }
    for (int i = 0; i < n; i++) 
        cout << res[i] << " ";
}

int main() 
{
    int n, m;
    cin >> n >> m;
    vector<int> sumtime(m, 0);
    vector<vector<int>> tasks;
    vector<int> res(n, 0);
    for (int i = 0; i < m; i++) 
    {
        vector<int> temp;
        for (int j = 0; j < n; j++) 
        {
            int t;
            cin >> t;
            temp.push_back(t);
        }
        tasks.push_back(temp);
    }
    task_assignment(sumtime, tasks, res, n, m);
    return 0;
}