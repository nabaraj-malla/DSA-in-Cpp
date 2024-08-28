// Problem statement
// Given a positive integer 'n', find and return the minimum number of steps that 'n' has to take to get reduced to 1. You can perform any one of the following 3 steps:

// 1.) Subtract 1 from it. (n = n - ­1) ,
// 2.) If n is divisible by 2, divide by 2.( if n % 2 == 0, then n = n / 2 ) ,
// 3.) If n is divisible by 3, divide by 3. (if n % 3 == 0, then n = n / 3 ).
#include <iostream>
using namespace std;
int countStepsToOne(int n)
{
    int *ans = new int[n + 1];
    ans[0] = 0;
    ans[1] = 0;
    int divideByTwo, divideByThree;
    for (int i = 2; i <= n; i++)
    {
        int sub = i - 1;
        if (i % 2 == 0 && i % 3 == 0)
        {
            divideByTwo = i / 2;
            divideByThree = i / 3;
            ans[i] = 1 + min(ans[sub], min(ans[divideByTwo], ans[divideByThree]));
        }
        else if (i % 2 == 0 && i % 3 != 0)
        {
            divideByTwo = i / 2;
            ans[i] = 1 + min(ans[sub], ans[divideByTwo]);
        }
        else if (i % 2 != 0 && i % 3 == 0)
        {
            divideByThree = i / 3;
            ans[i] = 1 + min(ans[sub], ans[divideByThree]);
        }
        else
        {
            ans[i] = 1 + ans[sub];
        }
    }
    return ans[n];
}

int main()
{
    int n;
    cin >> n;
    cout << countStepsToOne(n);
}