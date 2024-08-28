// Problem statement
// A thief robbing a store can carry a maximal weight of W into his knapsack.
// There are N items, and i-th item weigh 'Wi' and the value being 'Vi.' What would be the maximum value V, that the thief can steal?
#include <iostream>
using namespace std;
int knapsack(int *weights, int *values, int n, int maxWeight)
{

    if (n == 0 || maxWeight == 0)
    {
        return 0;
    }

    if (maxWeight - weights[0] < 0)
    {
        return knapsack(weights + 1, values + 1, n - 1, maxWeight);
    }
    else
    {
        int x = values[0] + knapsack(weights + 1, values + 1, n - 1, maxWeight - weights[0]);
        int y = knapsack(weights + 1, values + 1, n - 1, maxWeight);
        return max(x, y);
    }
}

int main()
{
    int n;
    cin >> n;

    int *weights = new int[n];
    int *values = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> weights[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> values[i];
    }

    int maxWeight;
    cin >> maxWeight;

    cout << knapsack(weights, values, n, maxWeight) << endl;

    delete[] weights;
    delete[] values;
}