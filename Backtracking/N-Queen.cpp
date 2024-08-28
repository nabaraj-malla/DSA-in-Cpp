// Problem statement
// You are given 'N', and for a given 'N x N' chessboard. Find a configuration of 'N' queens such that no queen can attack any other queen on the chess board.

// A queen can be killed when it lies in the same row, or same column, or the same diagonal of any of the other queens. You have to return all such configurations.
#include <iostream>
using namespace std;
bool isPossible(int n, int row, int column, int board[][10])
{
    // checking vertically if we can place queen or not
    for (int i = row - 1; i >= 0; i--)
    {
        if (board[i][column] == 1)
        {
            return false;
        }
    }

    // checking left diagonal
    for (int i = row - 1, j = column - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }

    // checking right diagonal
    for (int i = row - 1, j = column + 1; i >= 0 && j < n; i--, j++)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }
    // if all above condition are failed then we can insert the queen
    return true;
}
void queenHelper(int n, int row, int board[][10])
{
    if (n == row)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << board[i][j] << " ";
            }
        }
        cout << endl;
        return;
    }
    // j = column
    for (int j = 0; j < n; j++)
    {
        if (isPossible(n, row, j, board))
        {
            board[row][j] = 1;
            queenHelper(n, row + 1, board);
            board[row][j] = 0;
        }
    }
    return;
}
void placeQueens(int n, int board[][10])
{
    queenHelper(n, 0, board);
}
int main()
{
    int n, board[10][10] = {0};
    cin >> n;
    placeQueens(n, board);
    return 0;
}