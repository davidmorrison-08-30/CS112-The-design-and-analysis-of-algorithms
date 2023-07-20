#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

ll BitOff(ll mask, ll i)
{
	return (mask & ~(1LL << i));
}

ll crashBalloon(ll n, vector<ll> balloons)
{
	ll config_num = 1LL << n;
	vector<vector<ll>> dp(config_num, vector<ll>(n, 0));
	vector<ll> result(config_num, 0);
	for (ll config = 0; config < config_num; config++)
	{
		for (ll bal = 0; bal < n; bal++)
		{
			if (config != 0 && BitOff(config, bal) == 0)
				dp[config][bal] = balloons[bal];
			else if (BitOff(config, bal) == config)
				dp[config][bal] = 0;
			else
			{
				ll w = 1;
				for (ll i = bal + 1; i < n; i++)
				{
					if (((1LL << i) & config) != 0)
					{
						w *= balloons[i];
						break;
					}
				}
				for (ll i = bal - 1; i >= 0; i--)
				{
					if (((1LL << i) & config) != 0)
					{
						w *= balloons[i];
						break;
					}
				}
				w *= balloons[bal];
				dp[config][bal] = w + result[BitOff(config, bal)];
			}
			result[config] = max(result[config], dp[config][bal]);
		}
	}
	return result[config_num - 1];
}

int main()
{
	ll n;
	cin >> n;
	vector<ll> balloons(n, 0);
	for (ll i = 0; i < n; i++)
		cin >> balloons[i];
	cout << crashBalloon(n, balloons);
	return 0;
}