#include <iostream>
#include <vector>

using namespace std;

void build_parentheses(int n, vector<string>& a, string s, int closed, int open) 
{
	if (closed < open) 
	{
		build_parentheses(n, a, s + ")", closed + 1, open);
	}
	if ((open == n) && (closed == n)) {
		a.push_back(s);
		return;
	}
	if (open < n) {
		build_parentheses(n, a, s + "(", closed, open + 1);
	}
}

int main() 
{
	int n;
	cin >> n;
	vector<string> a;
	build_parentheses(n, a, "", 0, 0);
	for (auto s : a) 
		cout << s << endl;
	return 0;
}