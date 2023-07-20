#include <iostream>
#include <vector>
#include <string.h>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

typedef long long ll;

struct book
{
	ll page_num;
	ll price;
};

ll pullCards(string s1, string s2)
{
	vector<vector<ll>> dp(s1.length() + 1, vector<ll>(s2.length() + 1, LLONG_MAX));
	dp[0][0] = 0;
	for (ll i = 0; i <= s1.length(); i++)
	{
		for (ll j = 0; j <= s2.length(); j++)
		{
			if (i > 0)
				dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
			if (j > 0)
				dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
			if (i > 0 && j > 0)
				dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (s1[i - 1] != s2[j - 1]));
		}
	}
	return dp[s1.length()][s2.length()];
}

int main()
{

	string s1, s2;
	cin >> s1 >> s2;
	cout << pullCards(s1, s2);

	return 0;
}