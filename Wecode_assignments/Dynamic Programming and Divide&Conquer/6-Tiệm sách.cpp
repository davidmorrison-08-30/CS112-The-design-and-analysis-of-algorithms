#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct book
{
	int no_of_pages;
	int price;
};

int maxPageNum(int n, int x, vector<book> lst_of_books)
{
	vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= x; j++)
		{
			if (i == 0 || j == 0)
				dp[i][j] = 0;
			else if (lst_of_books[i].price > j)
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = max(dp[i - 1][j], 
							lst_of_books[i].no_of_pages + dp[i - 1][j - lst_of_books[i].price]);	
		}
	}
	return dp[n][x];
}

int main()
{
	int n, x;
	cin >> n >> x;
	vector<book> lst_of_books(n + 1);
	for (int i = 1; i < n + 1; i++)
		cin >> lst_of_books[i].price;
	for (int i = 1; i < n + 1; i++)
		cin >> lst_of_books[i].no_of_pages;
	cout << maxPageNum(n, x, lst_of_books);
	return 0;
}