// Problem statement
// Write a recursive function that returns the sum of the digits of a given integer

#include <iostream>
using namespace std;

int sumOfDigits(int n)
{
    if (n < 10)
    {
        return n;
    }
    int smallOutput = sumOfDigits(n / 10);
    int lastDigit = n % 10;
    return smallOutput + lastDigit;
}

int main()
{
    int n;
    cin >> n;
    cout << sumOfDigits(n) << endl;
}
