// Problem statement
// Given a NxM matrix containing Uppercase English Alphabets only.
// Your task is to tell if there is a path in the given matrix which makes the sentence “CODINGNINJA” .

// There is a path from any cell to all its neighbouring cells.
// For a particular cell, neighbouring cells are those cells that share an edge or a corner with the cell.
#include <iostream>
#include <vector>
using namespace std;
#include <string>

bool dfs(vector<vector<char>> &board, int n, int m, int i, int j, string s, vector<vector<bool>> &visited)
{
    if (s.size() == 0)
    {
        return true;
    }

    visited[i][j] = true;
    bool ans = false;
    if (j - 1 >= 0 && board[i][j - 1] == s[0] && !visited[i][j - 1]) // left
    {
        bool tans = dfs(board, n, m, i, j - 1, s.substr(1), visited);
        if (tans == true)
        {
            return true;
        }
        // if we return false here in case of receiving false from recursion then we
        // cannot mark false to this particular cell and cannot lool for othe possible solution
    }
    if (j + 1 < m && board[i][j + 1] == s[0] && !visited[i][j + 1]) // right
    {
        bool tans = dfs(board, n, m, i, j + 1, s.substr(1), visited);
        if (tans == true)
        {
            return true;
        }
    }
    if (i - 1 >= 0 && board[i - 1][j] == s[0] && !visited[i - 1][j]) // up
    {
        if (dfs(board, n, m, i - 1, j, s.substr(1), visited))
            return true;
    }
    if (i + 1 < n && board[i + 1][j] == s[0] && !visited[i + 1][j]) // down
    {
        bool tans = dfs(board, n, m, i + 1, j, s.substr(1), visited);
        if (tans == true)
        {
            return true;
        }
    }
    if (i + 1 < n && j + 1 < m && board[i + 1][j + 1] == s[0] && !visited[i + 1][j + 1]) // down right
    {
        bool tans = dfs(board, n, m, i + 1, j + 1, s.substr(1), visited);
        if (tans == true)
        {
            return true;
        }
    }
    if (i - 1 >= 0 && j - 1 >= 0 && board[i - 1][j - 1] == s[0] && !visited[i - 1][j - 1]) // up left
    {
        bool tans = dfs(board, n, m, i - 1, j - 1, s.substr(1), visited);
        if (tans == true)
        {
            return true;
        }
    }
    if (i + 1 < n && j - 1 >= 0 && board[i + 1][j - 1] == s[0] && !visited[i + 1][j - 1]) // down left
    {
        bool tans = dfs(board, n, m, i + 1, j - 1, s.substr(1), visited);
        if (tans == true)
        {
            return true;
        }
    }
    if (i - 1 >= 0 && j + 1 < m && board[i - 1][j + 1] == s[0] && !visited[i - 1][j + 1]) // up right
    {
        bool tans = dfs(board, n, m, i - 1, j + 1, s.substr(1), visited);
        if (tans == true)
        {
            return true;
        }
    }

    visited[i][j] = false;
    return ans;
}
bool hasPath(vector<vector<char>> &board, int n, int m)
{
    // Write your code here.
    vector<vector<bool>> visited(n, vector<bool>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            visited[i][j] = false;
        }
    }

    string s = "CODINGNINJA";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 'C')
            {
                // if we don't get answer from currently encountered 'C'
                // we try with next available 'C' so we don't return false when we get false answer from dfs function
                if (dfs(board, n, m, i, j, s.substr(1), visited))
                {
                    return true;
                }
            }
        }
    }

    return false;
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

    cout << (hasPath(board, n, m) ? 1 : 0);
}