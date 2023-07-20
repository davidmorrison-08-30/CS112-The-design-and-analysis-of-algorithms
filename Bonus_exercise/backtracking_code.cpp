#include <iostream>
#include <vector>
#include <set>
#include <chrono>

using namespace std;
using namespace std::chrono;
set<set<int>> S;
set<int> P;
set<set<int>> result = {};

void printSet(set<set<int>> S)
{
    for (auto s : S)
    {
        cout << '{';
        for (auto i : s)
            cout << ' ' << i;
        cout << '}' << endl;
    }
}

void HoanVi(int i, vector<int> A, set<int> P, set<set<int>> S)
{
    for (int j = i; j < A.size(); j++)
    {
        P.insert(A[j]);
        S.insert(P);
        if (i < A.size() - 1)
            HoanVi(i + 1, A, P, S);
        else
            for (auto r : S)
                result.insert(r);
        S.erase(P);
        P.erase(A[j]);
    }
}

int main()
{
    vector<int> A = {};
    for (int l = 1; l <= 12; l++)
    {
        A.push_back(l);
        S = {}; P = {}; result = {};
        auto start = high_resolution_clock::now();
        HoanVi(0, A, P, S);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(stop - start);
        cout << "n = " << A.size() << "\t\t\t Execution time: " << duration.count() << "ms\t\t\t";
        cout << "A={";
        for (auto j : A)
            cout << j << ", ";
        cout << '}' << endl;
    }
    return 0;
}