// Problem statement
// An integer matrix of size (M x N) has been given. Find out the minimum cost to reach from the cell (0, 0) to (M - 1, N - 1).

// From a cell (i, j), you can move in three directions:

// 1. ((i + 1),  j) which is, "down"
// 2. (i, (j + 1)) which is, "to the right"
// 3. ((i+1), (j+1)) which is, "to the diagonal"
// The cost of a path is defined as the sum of each cell's values through which the route passes.
#include <iostream>
#include <climits>
using namespace std;

int minCostPath(int **input, int m, int n)
{
    int **output = new int *[m];
    for (int i = 0; i < m; i++)
    {
        output[i] = new int[n];
    }

    // fill the last cel i.e destination
    output[m - 1][n - 1] = input[m - 1][n - 1];

    // fill the last row
    for (int j = n - 2; j >= 0; j--)
    {
        output[m - 1][j] = output[m - 1][j + 1] + input[m - 1][j];
    }

    // fill the remaining cells
    for (int i = m - 2; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            if (j == n - 1)
            {
                output[i][j] = output[i + 1][j] + input[i][j];
            }
            else
            {
                output[i][j] = min(output[i + 1][j], min(output[i][j + 1], output[i + 1][j + 1])) + input[i][j];
            }
        }
    }

    return output[0][0];
}

int main()
{
    int **arr, n, m;
    cin >> n >> m;
    arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[m];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << minCostPath(arr, n, m) << endl;
}