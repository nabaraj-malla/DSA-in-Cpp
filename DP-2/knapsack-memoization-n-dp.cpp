// Problem statement
// A thief is robbing a store and can carry a maximal weight of W into his knapsack. There are N items and ith item weighs wi and is of value vi. Considering the constraints of maximum weight that knapsack can carry,
// you have to find and return the maximum value that thief can generate by stealing items.

// Note
// Space complexity should be O(W).
#include <cstring>
#include <iostream>
using namespace std;

int knapsack_dp(int *wt, int *values, int n, int W)
{
    int dp[n + 1][W + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else
            {
                if (wt[i - 1] > j)
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = max(values[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
            }
        }
    }
    return dp[n][W];
}
int knapsack(int *weight, int *value, int n, int maxWeight)
{
    return knapsack_dp(weight, value, n, maxWeight);
}

/*
int knapsack_mem(int *weight, int *value, int n, int maxWeight, int **output)
{
    if (n == 0 || maxWeight == 0)
    {
        return 0;
    }
    if (output[n][maxWeight] != -1)
    {
        return output[n][maxWeight];
    }

    if (weight[0] > maxWeight)
    {
        output[n][maxWeight] = knapsack_mem(weight + 1, value + 1, n - 1, maxWeight, output);
        return output[n][maxWeight];
    }

    int x = value[0] + knapsack_mem(weight + 1, value + 1, n - 1, maxWeight - weight[0], output);
    int y = knapsack_mem(weight + 1, value + 1, n - 1, maxWeight, output);
    output[n][maxWeight] = max(x, y);
    return output[n][maxWeight];
}
int knapsack(int *weight, int *value, int n, int maxWeight)
{
    int **output = new int *[n + 1];
    for (int i = 0; i <= n; i++)
    {
        output[i] = new int[maxWeight + 1];
        for (int j = 0; j <= maxWeight; j++)
        {
            output[i][j] = -1;
        }
    }

    return knapsack_mem(weight, value, n, maxWeight, output);
}
*/

int main()
{
    int n;
    cin >> n;
    int *wt = new int[n];
    int *val = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> wt[i];
    }

    for (int j = 0; j < n; j++)
    {
        cin >> val[j];
    }

    int w;
    cin >> w;

    cout << knapsack(wt, val, n, w) << "\n";

    delete[] wt;
    delete[] val;
}