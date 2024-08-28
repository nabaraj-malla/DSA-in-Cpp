// Problem statement
// Coding Ninjas has provided you a crossword of 10*10 grid. The grid contains '+' or '-' as its cell values. Now, you are also provided with a word list that needs to placed accurately in the grid. Cells marked with '-' are to be filled with word list.

// For example, The following is an example for the input crossword grid and the word list.

// +-++++++++
// +-++-+++++
// +-------++
// +-++-+++++
// +-++-+++++
// +-++-+++++
// ++++-+++++
// ++++-+++++
// ++++++++++
// ----------
// CALIFORNIA;NIGERIA;CANADA;TELAVIV
// Output for the given input should be:

// +C++++++++
// +A++T+++++
// +NIGERIA++
// +A++L+++++
// +D++A+++++
// +A++V+++++
// ++++I+++++
// ++++V+++++
// ++++++++++
// CALIFORNIA
// Note: We have provided such test cases that there is only one solution for the given input.
#include <iostream>
// #include<bits/stdc++.h>
#include <vector>
#include <string>
#define n 10
using namespace std;
bool isValidVertical(char grid[][n], string s, int row, int col)
{
    // if (row > 9) {
    //     return false;
    // }
    for (int i = 0; i < s.size(); i++)
    {
        if (grid[i + row][col] == '+')
        {
            return false;
        }
        else if (grid[i + row][col] != '-' && grid[row + i][col] != s[i])
        {
            return false;
        }
    }
    return true;
}
void setVertical(char grid[n][n], string s, int row, int col, vector<bool> &markVertical)
{
    for (int i = 0; i < s.size(); i++)
    {
        if (grid[i + row][col] == '-')
        {
            grid[i + row][col] = s[i];
            markVertical.push_back(true);
        }
    }
}
void resetVertical(char grid[][n], int row, int col, vector<bool> &markVertical)
{
    for (int i = 0; i < markVertical.size(); i++)
    {
        if (markVertical[i] == true)
        {
            grid[i + row][col] = '-';
            // markVertical.push_back(false);
        }
    }
}
bool isValidHorizontal(char grid[][n], string s, int row, int col)
{
    // if (col > 9) {
    //     return false;
    // }
    for (int i = 0; i < s.size(); i++)
    {
        if (grid[row][i + col] == '+')
        {
            return false;
        }
        else if (grid[row][i + col] != '-' && grid[row][i + col] != s[i])
        {
            return false;
        }
    }
    return true;
}
void setHorizontal(char grid[][n], string s, int row, int col, vector<bool> &markHorizontal)
{
    for (int i = 0; i < s.size(); i++)
    {
        if (grid[row][i + col] == '-')
        {
            grid[row][i + col] = s[i];
            markHorizontal.push_back(true);
        }
    }
}
void resetHorizontal(char grid[][n], int row, int col, vector<bool> &markHorizontal)
{
    for (int i = 0; i < markHorizontal.size(); i++)
    {
        if (markHorizontal[i] == true)
        {
            grid[row][i + col] = '-';
            // markHorizontal.push_back(false);
        }
    }
}
bool crossword(char grid[n][n], vector<string> words, int index)
{
    if (index >= words.size())
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << grid[i][j];
            }
            cout << endl;
        }
        return true;
    }
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (grid[row][col] == '-' || grid[row][col] == words[index][0])
            {
                if (isValidVertical(grid, words[index], row, col))
                {
                    vector<bool> markVertical;
                    setVertical(grid, words[index], row, col, markVertical);
                    if (crossword(grid, words, index + 1))
                    {
                        return true;
                    }
                    resetVertical(grid, row, col, markVertical);
                }
                if (isValidHorizontal(grid, words[index], row, col))
                {
                    vector<bool> markHorizontal;
                    setHorizontal(grid, words[index], row, col, markHorizontal);
                    if (crossword(grid, words, index + 1))
                    {
                        return true;
                    }
                    resetHorizontal(grid, row, col, markHorizontal);
                }
            }
        }
    }
    return false;
}
int main()
{
    char grid[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }
    string s;
    cin >> s; //   1 ------ california 2 nigeria
    vector<string> words;
    for (int i = 0; i < s.length(); i++)
    {
        int j = i;
        while (s[j] != ';' && j < s.length())
        {
            j++;
        }
        words.push_back(s.substr(i, j - i));
        i = j;
        j++;
    }
    bool x = crossword(grid, words, 0);
}