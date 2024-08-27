// Problem statement
// Given an integer N, count and return the number of zeros that are present in the given integer using recursion.
#include <iostream>
using namespace std;

int countZeros(int n)
{
    if (n < 10)
    {
        if (n % 10 == 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int smallOutput = countZeros(n / 10);
    if (n % 10 == 0)
    {
        return smallOutput + 1;
    }
    else
        return smallOutput;
}
int main()
{
    int n;
    cin >> n;
    cout << countZeros(n) << endl;
}