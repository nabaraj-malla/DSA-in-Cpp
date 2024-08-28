// Problem statement
// Coding Ninjas has provided you a 9*9 sudoku board. The board contains non zero and zero values.
// Non zero values lie in the range: [1, 9]. Cells with zero value indicate that the particular cell is empty and can be replaced by non zero values.

// You need to find out whether the sudoku board can be solved. If the sudoku board can be solved, then print true, otherwise print false.
#include <iostream>
using namespace std;
bool isEmptyLocation(int grid[9][9], int &row, int &col)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (grid[i][j] == 0)
            {
                row = i;
                col = j;
                return true;
            }
        }
    }
    return false;
}
bool isSafeInRow(int grid[9][9], int row, int num)
{
    for (int i = 0; i < 9; i++)
    {
        if (grid[row][i] == num)
        {
            return false;
        }
    }
    return true;
}
bool isSafeInColumn(int grid[9][9], int col, int num)
{
    for (int i = 0; i < 9; i++)
    {
        if (grid[i][col] == num)
        {
            return false;
        }
    }
    return true;
}
bool isSafeInGrid(int grid[9][9], int row, int col, int num)
{
    int rowFactor = row - (row % 3);
    int colFactor = col - (col % 3);
    // int i;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (grid[i + rowFactor][j + colFactor] == num)
            {
                return false;
            }
        }
    }
    return true;
}
bool isSafe(int grid[9][9], int row, int col, int num)
{
    if (isSafeInRow(grid, row, num) && isSafeInColumn(grid, col, num) && isSafeInGrid(grid, row, col, num))
    {
        return true;
    }
    return false;
}
bool solveSudoku(int grid[9][9])
{
    int row, col;
    // finding the empty location
    if (!isEmptyLocation(grid, row, col))
    {
        return true;
    }
    // checking for every possible values
    for (int i = 1; i <= 9; i++)
    {
        if (isSafe(grid, row, col, i))
        {
            grid[row][col] = i;
            if (solveSudoku(grid))
            {
                return true;
            } // if we get false frome this statement we backtrack
            grid[row][col] = 0; // backtracking my making previously initialized value to zero
        }
    }
    return false;
}
int main()
{
    int grid[9][9];
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> grid[i][j];
        }
    }
    if (solveSudoku(grid))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
    return 0;
}