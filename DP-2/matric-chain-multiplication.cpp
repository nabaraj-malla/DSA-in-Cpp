// Problem statement
// Given a chain of matrices A1, A2, A3,.....An, you have to figure out the most efficient way to multiply these matrices.
// In other words, determine where to place parentheses to minimize the number of multiplications.

// You will be given an array p[] of size n + 1. Dimension of matrix Ai is p[i - 1]*p[i]. You need to find minimum number of multiplications needed to multiply the chain.
#include <iostream>
using namespace std;

#include <climits>
int matrixChainMultiplication(int *arr, int n)
{
    // Write your code here
    int dp[n + 1][n + 1];
    for (int i = 1; i <= n; i++)
    {
        dp[i][i] = 0;
    }

    for (int l = 2; l <= n; l++)
    {
        for (int i = 1; i <= n - l + 1; i++)
        {
            int j = i + l - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++)
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j]);
            }
        }
    }

    return dp[1][n];
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n + 1];

    for (int i = 0; i <= n; i++)
    {
        cin >> arr[i];
    }

    cout << matrixChainMultiplication(arr, n);

    delete[] arr;
}