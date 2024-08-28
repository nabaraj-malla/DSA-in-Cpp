// Problem statement
// Given an array with N elements, you need to find the length of the longest subsequence
// in the given array such that all elements of the subsequence are sorted in strictly increasing order.
#include <iostream>
using namespace std;

int longestIncreasingSubsequence(int *arr, int n)
{
    int *dp = new int[n];
    dp[0] = 1;

    for (int i = 1; i < n; i++)
    {
        int ans = 0;
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] < arr[i])
                ans = max(dp[j], ans);
        }

        dp[i] = ans + 1;
    }

    int best = 0;
    for (int i = 0; i < n; i++)
    {
        if (best < dp[i])
        {
            best = dp[i];
        }
    }
    return best;
}
int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << longestIncreasingSubsequence(arr, n);
}