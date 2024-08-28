// Problem statement
// Whis and Beerus are playing a new game today. They form a tower of N coins and
// make a move in alternate turns. Beerus plays first. In one step,
// the player can remove either 1, X, or Y coins from the tower.
// The person to make the last move wins the game. Can you find out who wins the game?
#include <iostream>
#include <string>
using namespace std;

#include <string>
string findWinner(int n, int x, int y)
{
    // Write your code here .
    bool dp[n + 1];
    dp[0] = false;
    dp[1] = true;
    for (int i = 2; i <= n; i++)
    {
        if (i - 1 >= 0 && dp[i - 1] != true)
        {
            dp[i] = true;
        }
        else if (i - x >= 0 && dp[i - x] != true)
        {
            dp[i] = true;
        }
        else if (i - y >= 0 && dp[i - y] != true)
        {
            dp[i] = true;
        }
        else
        {
            dp[i] = false;
        }
    }

    if (dp[n] == true)
    {
        return "Beerus";
    }
    else
    {
        return "Whis";
    }
}

int main()
{
    int n, x, y;
    cin >> n >> x >> y;
    cout << findWinner(n, x, y);
}