#include <iostream>
#include <vector>

using namespace std;

int mark(vector<int>& arr, int& left, int& right)
{
    int p = left - 1;
    int T = arr[right];
    for (int i = left; i < right; i++)
        if (arr[i] < T)
        {
            p = p + 1;
            swap(arr[p], arr[i]);
        }
    swap(arr[p + 1], arr[right]);
    return p + 1;
}

int max_at_k(vector<int>& arr, int k, int left, int right)
{
    while (right >= left) 
    {
        int T = mark(arr, left, right);
        if (k <= T)
            right = T - 1;
        else 
            left = T + 1;
        if (T == k)
            return arr[T];
    }
    return -1;
}

int main() 
{
    int n, k;
    vector<int> arr;
    cin >> n >> k;
    for (int i = 0; i < n; i++) 
    {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    cout << max_at_k(arr, n - k, 0, n - 1);
    return 0;
}