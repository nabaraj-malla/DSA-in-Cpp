// Problem statement
// Given k, find the geometric sum i.e.
// 1 + 1/2 + 1/4 + 1/8 + ... + 1/(2^k)

#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

double geometricSum(int k)
{
    // Write your code here
    if (k == 0)
    {
        return 1;
    }
    double smallOutput = geometricSum(k - 1);
    return 1 / pow(2, k) + smallOutput;
}

int main()
{
    int k;
    cin >> k;
    cout << fixed << setprecision(5);
    cout << geometricSum(k) << endl;
}