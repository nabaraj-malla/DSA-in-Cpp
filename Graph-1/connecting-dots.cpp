// Problem statement
// Gary has a board of size NxM. Each cell in the board is a coloured dot. There exist only 26 colours denoted by uppercase Latin characters (i.e. A,B,...,Z). Now Gary is getting bored and wants to play a game. The key of this game is to find a cycle that contain dots of same colour. Formally, we call a sequence of dots d1, d2, ..., dk a cycle if and only if it meets the following condition:

// 1. These k dots are different: if i ≠ j then di is different from dj.
// 2. k is at least 4.
// 3. All dots belong to the same colour.
// 4. For all 1 ≤ i ≤ k - 1: di and di + 1 are adjacent. Also, dk and d1 should also be adjacent. Cells x and y are called adjacent if they share an edge.
// Since Gary is colour blind, he wants your help. Your task is to determine if there exists a cycle on the board.

#include <iostream>
#include <vector>
using namespace std;

#include <vector>
void dfs(vector<vector<char>> &board, vector<vector<bool>> &visited, int x, int y, int fromX, int fromY,
         char needColor, bool &foundCycle, int n, int m)
{
    if (x < 0 || x >= n || y < 0 || y >= m)
    {
        return;
    }

    if (board[x][y] != needColor)
    {
        return;
    }

    if (visited[x][y])
    {
        foundCycle = true;
        return;
    }

    visited[x][y] = true;
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    for (int i = 0; i < 4; i++)
    {
        int nextX = x + dx[i];
        int nextY = y + dy[i];
        if (nextX == fromX && nextY == fromY)
        {
            continue;
        }

        dfs(board, visited, nextX, nextY, x, y, needColor, foundCycle, n, m);
    }
}
bool hasCycle(vector<vector<char>> &board, int n, int m)
{
    // Write your code here.
    bool foundCycle = false;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j])
            {
                dfs(board, visited, i, j, -1, -1, board[i][j], foundCycle, n, m);
            }
        }
    }
    return foundCycle;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<char>> board(n, vector<char>(m));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> board[i][j];
        }
    }

    cout << (hasCycle(board, n, m) ? "true" : "false");
}