#include <iostream>
#include <vector>
#include <string.h>
#include <string>
using namespace std;

typedef long long ll;

ll safePath(ll n, vector<string> map)
{
	vector<vector<ll>> dp(n, vector<ll>(n, 0));
	dp[0][0] = 1;
	for (ll i = 0; i < n; i++)
	{
		for (ll j = 0; j < n; j++)
		{
			if (i == 0 && j == 0)
				continue;
			if (i == 0)
				dp[i][j] = dp[i][j - 1] * (map[i][j - 1] == '.');
			else if (j == 0)
				dp[i][j] = dp[i - 1][j] * (map[i - 1][j] == '.');
			else
				dp[i][j] = dp[i - 1][j] * (map[i - 1][j] == '.') + dp[i][j - 1] * (map[i][j - 1] == '.');
			dp[i][j] %= (ll(1e9 + 7));
		}
	}
	if (map[n - 1][n - 1] == '.')
		return dp[n - 1][n - 1];
	return 0;
}

int main()
{

	ll n;
	cin >> n;
	vector<string> map(n);
	for (ll i = 0; i < n; i++)
		cin >> map[i];

	cout << safePath(n, map);

	return 0;
}