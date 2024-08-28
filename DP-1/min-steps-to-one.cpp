// Problem statement
// Given a positive integer 'n', find and return the minimum number of steps that 'n' has to take to get reduced to 1. You can perform any one of the following 3 steps:

// 1.) Subtract 1 from it. (n = n - ­1) ,
// 2.) If its divisible by 2, divide by 2.( if n % 2 == 0, then n = n / 2 ) ,
// 3.) If its divisible by 3, divide by 3. (if n % 3 == 0, then n = n / 3 ).
// Write brute-force recursive solution for this.
#include <iostream>
using namespace std;
#include <climits>
int countMinStepsToOne(int n)
{
    // Write your code here
    if (n == 1)
    {
        return 0;
    }
    int subOne = countMinStepsToOne(n - 1);
    int divideByTwo = INT_MAX;
    int divideByThree = INT_MAX;
    if (n % 2 == 0)
    {
        divideByTwo = countMinStepsToOne(n / 2);
    }

    if (n % 3 == 0)
    {
        divideByThree = countMinStepsToOne(n / 3);
    }
    return 1 + min(subOne, min(divideByTwo, divideByThree));
}

int main()
{
    int n;
    cin >> n;
    cout << countMinStepsToOne(n);
}