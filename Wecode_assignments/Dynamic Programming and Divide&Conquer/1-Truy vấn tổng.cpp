#include <iostream>
#include <vector>
using namespace std;


void querySum(vector<long>& A, long n)
{
	cin >> A[0];
	for (long i = 1; i < n; i++)
	{
		cin >> A[i];
		A[i] += A[i - 1];
	}
}


int main()
{
	long n, q;
	cin >> n >> q;
	vector<long> A(n, 0);
	querySum(A, n);
	for (long i = 0; i < q; i++)
	{
		long a, b;
		cin >> a >> b;
		if (a > 1)
			cout << A[b - 1] - A[a - 2] << endl;
		else
			cout << A[b - 1] << endl;
	}
	return 0;
}