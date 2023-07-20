#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <string>
using namespace std;

typedef long long ll;

ll exec(ll x, ll y, char opr)
{
	if (opr == '+')
		return x + y;
	else if (opr == '-')
		return x - y;
	else
		return x * y;
}

void input(string s, vector<ll>& operands, vector<char>& operators)
{
	for (ll i = 0; i < s.size(); i++)
	{
		if (s[i] == '+' || s[i] == '-' || s[i] == '*')
			operators.push_back(s[i]);
		else
		{
			ll j = 0;
			while (i < s.size())
			{
				j = j * 10 + s[i] - '0';
				if (i + 1 < s.size() && s[i + 1] >= '0' && s[i + 1] <= '9')
					i++;
				else
					break;
			}
			operands.push_back(j);
		}
	}
}

void CalculateInMulWays(vector<ll> operands, vector<char> operators)
{
	vector<vector<vector<ll>>> dp;
	ll len_opr = operators.size();
	ll len_opd = operands.size();

	dp.resize(len_opd, vector<vector<ll>>(len_opd));
	for (ll i = 0; i < len_opd; i++)
		dp[i][i].push_back(operands[i]);
	for (ll n = 1; n < len_opd; n++)
		for (ll i = 0; i + n < len_opd; i++)
			for (ll k = i; k < i + n; k++)
				for (ll l_res : dp[i][k])
					for (ll r_res : dp[k + 1][i + n])
						dp[i][i + n].push_back(exec(l_res, r_res, operators[k]));

	sort(dp[0][len_opd - 1].begin(), dp[0][len_opd - 1].end());
	for (ll i : dp[0][len_opd - 1])
		cout << i << endl;
}

int main()
{
	string s;
	vector<ll> operands;
	vector<char> operators;
	cin >> s;
	input(s, operands, operators);
	CalculateInMulWays(operands, operators);
	return 0;
}