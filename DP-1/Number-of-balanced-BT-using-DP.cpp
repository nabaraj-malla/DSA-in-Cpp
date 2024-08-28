// Problem statement
// Given an integer h, find the possible number of balanced binary trees of height h. You just need to return the count of possible binary trees which are balanced.

// This number can be huge, so, return output modulus 10^9 + 7.

// Time complexity should be O(h).
#include <iostream>
using namespace std;

#include <cmath>
int balancedBTs(int n)
{
    int *ans = new int[n + 1];
    ans[0] = 1;
    ans[1] = 1;
    ans[2] = 3;
    int mod = (int)(pow(10, 9)) + 7;
    for (int i = 3; i <= n; i++)
    {
        int x = ans[i - 1];
        int y = ans[i - 2];

        int temp1 = (int)(((long)(x)*x) % mod);
        int temp2 = (int)((2 * (long)(x)*y) % mod);
        int res = (temp1 + temp2) % mod;
        ans[i] = res;
    }
    return ans[n];
}

int main()
{
    int n;
    cin >> n;
    cout << balancedBTs(n);
}