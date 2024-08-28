// Problem statement
// Given two integers a and b. You need to find and return the count of possible ways in which we can represent the number a as the sum of unique integers raise to the power b.

// For example: if a = 10 and b = 2, only way to represent 10 as sum of unique integers raised to power 2 is-

// 10 = 1^2 + 3^2
// Hence, answer is 1.

// Note : x^y represents x raise to the power y
#include <iostream>
using namespace std;
#include <cmath>
int helper(int a, int b, int curNo, int *dp)
{
    if (a < 0)
    {
        return 0;
    }

    if (a == 0)
    {
        return 1;
    }

    int ans = 0;

    for (int i = curNo; pow(i, b) <= a; i++)
    {
        ans = ans + helper(a - pow(i, b), b, i + 1, dp);
    }

    dp[a] = ans;
    return ans;
}

int getAllWays(int a, int b)
{
    int *dp = new int[10000];
    for (int i = 0; i < 10000; i++)
    {
        dp[i] = -1;
    }

    return helper(a, b, 1, dp);
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << getAllWays(a, b);
}