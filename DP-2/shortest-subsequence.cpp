// Problem statement
// Gary has two string S and V. Now, Gary wants to know the length shortest subsequence in S, which is not a subsequence in V.

// Note: The input data will be such that there will always be a solution.
#include <iostream>
#include <string>
using namespace std;

int solve(string s, string v)
{
    // Write your code here
    int m = s.size();
    int n = v.size();
    int dp[m + 1][n + 1];
    // t string is empty
    for (int i = 0; i <= m; i++)
    {
        dp[i][0] = 1;
    }

    // s string is empty
    for (int j = 0; j <= n; j++)
    {
        dp[0][j] = 1000;
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            char ch = s[i - 1];
            int k;
            for (k = j - 1; k >= 0; k--)
            {
                if (v[k] == ch)
                {
                    break;
                }
            }
            // char not present in t
            if (k == -1)
            {
                dp[i][j] = 1;
            }
            else
            {
                dp[i][j] = min(dp[i - 1][j], dp[i - 1][k] + 1);
            }
        }
    }

    int ans = dp[m][n];
    if (ans >= 1000)
    {
        return -1;
    }
    else
    {
        return ans;
    }
}

int main()
{
    string s, v;
    cin >> s >> v;
    cout << solve(s, v);
}