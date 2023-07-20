#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int LIS(int n, vector<int> A)
{
    vector<int> f(n + 1), b(n + 1, INT_MAX);
    b[0] = INT_MIN;
    int length = 0;
    for (int x : A)
    {
        int k = lower_bound(b.begin(), b.end(), x) - b.begin();
        b[k] = x;
        length = max(length, k);
    }
    return length;
}

int main() 
{
    int n; 
    cin >> n;
    vector<int> A;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        A.push_back(x);
    }

    cout << LIS(n, A);
    return 0;
}