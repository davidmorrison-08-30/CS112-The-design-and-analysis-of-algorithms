#include <iostream>
#include <vector>

using namespace std;

void print(vector<vector<string>> res_str)
{
    for (int i = 0; i < res_str.size(); i++)
    {
        for (int j = 0; j < res_str[i].size(); j++)
            cout << res_str[i][j] << " ";
        cout << endl;
    }
}

bool check_palindrome(string& a, int left, int right)
{
    while (left < right)
        if (a[left++] != a[right--])
            return false;
    return true;
}

void backtrack_and_output(vector<vector<string>>& res_str, string& a, vector<string>& temp, int start)
{
    if (start >= a.length())
        res_str.push_back(temp);
    for (int i = start; i < a.length(); i++)
    {
        if (check_palindrome(a, start, i))
        {
            temp.push_back(a.substr(start, i - start + 1));
            backtrack_and_output(res_str, a, temp, i + 1);
            temp.pop_back();
        }
    }
}

int main()
{
    string a;
    cin >> a;
    vector<string> temp;
    vector<vector<string>> res_str;
    backtrack_and_output(res_str, a, temp, 0);
    print(res_str);
}