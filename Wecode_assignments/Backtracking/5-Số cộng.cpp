#include <iostream>
#include <string>

using namespace std;

bool isAdditiveNumber(string num, int idx, long long first, long long second) 
{
    if (idx == num.length())
        return true;

    long long sum = first + second;
    string sumStr = to_string(sum);

    if (num.substr(idx, sumStr.length()) == sumStr)
        return isAdditiveNumber(num, idx + sumStr.length(), second, sum);

    return false;
}

bool isAdditive(string num) 
{
    int n = num.length();
    for (int i = 1; i <= n / 2; i++) {
        for (int j = 1; j <= (n - i) / 2; j++) 
        {
            if (num[0] == '0' && i > 1)
                break;
            if (num[i] == '0' && j > 1)
                continue;

            long long first = stoll(num.substr(0, i));
            long long second = stoll(num.substr(i, j));

            if (isAdditiveNumber(num, i + j, first, second))
                return true;
        }
    }

    return false;
}

int main() 
{
    string num;
    cin >> num;

    if (isAdditive(num))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}