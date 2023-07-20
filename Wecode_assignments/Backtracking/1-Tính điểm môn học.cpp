#include <iostream>
#include <math.h>
using namespace std;

void nhap(double* weights, int& n, double& grade)
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> weights[i];
    cin >> grade;
}

double avg(double* weights, double* scores, int n_)
{
    double sum = 0.0;
    for (int j = 0; j < n_; j++) 
        sum = sum + weights[j] * scores[j];
    sum = round(sum * 0.1) / 10;
    return sum;
}

void xuat(int i, double* weights, double* scores, double grade, int n)
{
    for (double j = 0.25; j <= 10.0; j = j + 0.25) 
    {
        scores[i] = j;
        if (i < n) 
            xuat(i + 1, weights, scores, grade, n);
        else 
        {
            double average_score = avg(weights, scores, n);
            if (average_score == grade)
            {
                for (int b = 0; b < n; b++)  
                    cout << scores[b] << " ";
                cout << endl;
            }
            break;
        }
        if (avg(weights, scores, i) > grade) 
            break;
    }

}

int main()
{
    int n;
    double grade;
    double* weights = new double[100];
    double* scores = new double[100];
    nhap(weights, n, grade);
    xuat(0, weights, scores, grade, n);
    return 0;
}