// Problem statement
// A thief wants to loot houses. He knows the amount of money in each house. He cannot loot two consecutive houses.
// Find the maximum amount of money he can loot.
#include <iostream>
using namespace std;

int maxMoneyLooted(int *arr, int n)
{
    // Write your code here
    int *dp = new int[n];
    dp[0] = arr[0];

    // if (n > 1)
    dp[1] = max(arr[0], arr[1]);

    for (int i = 2; i < n; i++)
    {
        dp[i] = max(arr[i] + dp[i - 2], dp[i - 1]);
    }

    return dp[n - 1];
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

    cout << maxMoneyLooted(arr, n);

    delete[] arr;
}