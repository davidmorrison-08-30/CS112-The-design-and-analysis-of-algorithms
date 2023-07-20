#include <iostream>
#include <vector>
#include <string.h>
#include <string>
#include <algorithm>
#include <map>
#include <climits>
using namespace std;

typedef long long ll;

struct subject
{
	ll start;
	ll end;
	ll credit;
};

ll creditNum(vector<subject> subjects)
{
	map<ll, ll> dp;
	dp[0] = 0;
	ll result = LLONG_MIN;
	for (auto s : subjects)
	{
		auto it = dp.lower_bound(s.start);
		it--;
		ll creditTotal = it->second + s.credit;
		result = max(result, creditTotal);
		dp[s.end] = result;
	}
	return result;
}

int main()
{

	ll n;
	cin >> n;
	vector<subject> subjects(n);
	for (ll i = 0; i < n; i++)
		cin >> subjects[i].start >> subjects[i].end >> subjects[i].credit;
	sort(subjects.begin(), subjects.end(), [](subject a, subject b) 
		{
			return a.end < b.end;
		});


	cout << creditNum(subjects);

	return 0;
}