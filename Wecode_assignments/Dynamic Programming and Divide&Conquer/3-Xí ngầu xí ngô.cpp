#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

ll countWays(ll s)
{
	vector<ll> dp(s + 1, 0);  // Dynamic programming table

	// Base case
	dp[0] = 1;

	// Fill the table in a bottom-up manner
	for (ll i = 1; i <= s; i++)
	{
		for (ll j = 1; j <= 6 && j <= i; j++)
			if (i - j >= 0)
			{
				dp[i] += dp[i - j];
				dp[i] %= (ll(1e9 + 7));
			}
	}

	return dp[s];
}

int main()
{

	ll s;
	cin >> s;

	cout << countWays(s) << endl;

	return 0;
}