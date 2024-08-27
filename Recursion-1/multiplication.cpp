// Problem statement
// Given two integers M & N, calculate and return their multiplication using recursion. You can only use subtraction and addition for your calculation. No other operators are allowed.

#include <iostream>
using namespace std;

int multiplyNumbers(int m, int n)
{
    if (m == 0 || n == 0)
    {
        return 0;
    }
    int smallOutput = multiplyNumbers(n - 1, m);
    return m + smallOutput;
}

int main()
{
    int m, n;
    cin >> m >> n;
    cout << multiplyNumbers(m, n) << endl;
}
