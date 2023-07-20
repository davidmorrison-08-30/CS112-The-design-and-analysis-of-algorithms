#include <iostream>
#include <vector>
#include <set>
using namespace std;

typedef long long ll;

struct book
{
	ll page_num;
	ll price;
};

void numChromes(vector<ll> chromosomes)
{
	vector<bool> dp(1e9);
	set<ll> chromKinds;
	dp[0] = true;
	ll total = 0;
	for (auto i : chromosomes)
	{
		total += i;
		for (ll len = total; len >= i; len--)
		{
			if (dp[len - i] && !dp[len])
			{
				dp[len] = true;
				chromKinds.insert(len);
			}
		}
	}
	cout << chromKinds.size() << endl;
	for (auto i : chromKinds)
		cout << i << " ";
}

int main()
{

	ll n;
	cin >> n;
	vector<ll> chromosomes(n);
	for (ll i = 0; i < n; i++)
		cin >> chromosomes[i];
	numChromes(chromosomes);

	return 0;
}