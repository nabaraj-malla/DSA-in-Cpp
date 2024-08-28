// Problem statement
// It's Gary's birthday today and he has ordered his favourite square cake consisting of '0's and '1's .
// But Gary wants the biggest piece of '1's and no '0's . A piece of cake is defined as a part which consist of only '1's,
// and all '1's share an edge with each other on the cake. Given the size of cake N and the cake, can you find the count of '1's in the biggest piece of '1's for Gary ?
#include <iostream>
#include <vector>
using namespace std;

#include <climits>
#include <vector>
int dfs(vector<vector<int>> &cake, int i, int j, int n, vector<vector<bool>> &visited)
{
    int count = 0;
    visited[i][j] = true;
    // left
    if (j - 1 >= 0 && cake[i][j - 1] == 1 && !visited[i][j - 1])
    {
        int leftAns = dfs(cake, i, j - 1, n, visited);
        count = count + leftAns;
    }

    // right
    if (j + 1 < n && cake[i][j + 1] == 1 && !visited[i][j + 1])
    {
        int rightAns = dfs(cake, i, j + 1, n, visited);
        count = count + rightAns;
    }

    // top
    if (i - 1 >= 0 && cake[i - 1][j] == 1 && !visited[i - 1][j])
    {
        int topAns = dfs(cake, i - 1, j, n, visited);
        count = count + topAns;
    }

    // bottom
    if (i + 1 < n && cake[i + 1][j] == 1 && !visited[i + 1][j])
    {
        int downAns = dfs(cake, i + 1, j, n, visited);
        count = count + downAns;
    }

    return 1 + count;
}

int getBiggestPieceSize(vector<vector<int>> &cake, int n)
{
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    int count = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (cake[i][j] == 1 && !visited[i][j])
            {
                int ans = dfs(cake, i, j, n, visited);
                count = max(ans, count);
            }
        }
    }

    return count;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> cake(n, vector<int>(n));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> cake[i][j];
        }
    }

    cout << getBiggestPieceSize(cake, n);
}