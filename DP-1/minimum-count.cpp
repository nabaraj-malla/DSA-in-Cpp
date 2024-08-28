// Problem statement
// Given an integer N, find and return the count of minimum numbers required to represent N as a sum of squares.

// That is, if N is 4, then we can represent it as : {1^2 + 1^2 + 1^2 + 1^2} and {2^2}.
// The output will be 1, as 1 is the minimum count of numbers required to represent N as sum of squares.
#include <iostream>
using namespace std;

int minCount(int n)
{
    int ans[n + 1];
    ans[1] = 1;
    ans[2] = 2;
    ans[3] = 3;
    for (int i = 4; i <= n; i++)
    {
        if (sqrt(i) - floor(sqrt(i)) == 0)
        {
            ans[i] = 1;
        }
        else
        {
            int x = sqrt(i);
            int j = 1;
            int res = i;
            while (x--)
            {
                res = min(res, ans[i - j * j]);
                j++;
            }
            ans[i] = 1 + res;
        }
    }
    return ans[n];
}

int main()
{
    int n;
    cin >> n;
    cout << minCount(n);
}