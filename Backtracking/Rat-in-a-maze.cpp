// Problem statement
// You are given an integer N and a binary 2D array of size N*N. The given binary matrix represents a maze and a rat starts from the top left cell and has to reach to the bottom right cell of the maze. The rat can move in all the four directions: up, down, left and right.

// In the given binary matrix, 0 signifies the cell is a dead end and 1 signifies the cell can be used to move from source to destination cell.

// You have to print all the paths, following which rat can move from the top left cell to the bottom right cell of the given binary matrix.
// #include <bits/stdc++.h>
#include <iostream>
using namespace std;
bool isValid(int maze[][18], int solution[][18], int n, int x, int y)
{
    if (x < 0 || x >= n || y < 0 || y >= n || maze[x][y] == 0 || solution[x][y] == 1)
    {
        return false;
    }
    return true;
}
void ratMazeHelper(int maze[][18], int solution[][18], int n, int x, int y)
{
    if (x == n - 1 && y == n - 1)
    {
        solution[x][y] = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << solution[i][j] << " ";
            }
        }
        solution[x][y] = 0;
        cout << endl;
        return;
    }
    if (isValid(maze, solution, n, x, y))
    {
        solution[x][y] = 1;
        ratMazeHelper(maze, solution, n, x - 1, y); // up
        ratMazeHelper(maze, solution, n, x + 1, y); // down
        ratMazeHelper(maze, solution, n, x, y - 1); // left
        ratMazeHelper(maze, solution, n, x, y + 1); // right
        solution[x][y] = 0;                         // backtrack if there is no any possible move for any cell
    }
}
void ratMaze(int maze[][18], int solution[][18], int n, int x, int y)
{
    ratMazeHelper(maze, solution, n, x, y);
}
int main()
{
    int maze[18][18];
    int solution[18][18] = {0};
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> maze[i][j];
        }
    }
    ratMaze(maze, solution, n, 0, 0);
    return 0;
}