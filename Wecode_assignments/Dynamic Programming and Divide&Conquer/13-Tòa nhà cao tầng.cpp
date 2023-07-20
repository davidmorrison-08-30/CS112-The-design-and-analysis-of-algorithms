#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <string>
using namespace std;

typedef long long ll;

struct building
{
	ll l, r, h;
};

void endPoints(vector<building> buildings)
{
	vector<ll> gram(1e6);
	for (auto bd : buildings)
		for (ll j = bd.l; j <= bd.r; j++)
			gram[j] = max(gram[j], bd.h);

	if (gram[0])
		cout << 0 << " " << gram[0] << endl;
	for (ll i = 0; i < 1e6 - 1; i++)
	{
		if (gram[i + 1] > gram[i])
			cout << i + 1 << " " << gram[i + 1] << endl;
		if (gram[i + 1] < gram[i])
			cout << i << " " << gram[i + 1] << endl;
	}
}

int main()
{
	ll n;
	vector<building> buildings;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		building X;
		cin >> X.l >> X.r >> X.h;
		buildings.push_back(X);
	}
	endPoints(buildings);
	return 0;
}