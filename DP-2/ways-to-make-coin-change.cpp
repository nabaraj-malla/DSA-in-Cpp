// Problem statement
// For the given infinite supply of coins of each of denominations, D = {D0, D1, D2, D3, ...... Dn-1}.
// You need to figure out the total number of ways W, in which you can make the change for Value V using coins of denominations D.

// Return 0 if the change isn't possible.
#include <iostream>
using namespace std;

int countWaysToMakeChangeHelper(int denominations[], int numDenominations, int value, int **output)
{
    // if there is no coin then no solution exist
    if (numDenominations <= 0)
    {
        return 0;
    }

    // if value is 0 then there is 1 solution
    //(do not include any coin)
    if (value == 0)
    {
        return 1;
    }

    // if value is less than 0 then
    // no solution exist
    if (value < 0)
    {
        return 0;
    }

    if (output[numDenominations][value] != -1)
    {
        return output[numDenominations][value];
    }

    // include denominations[i]
    // here we don't do denominations + 1 and numDenominations - 1 because we have infinite number of coins
    int x = countWaysToMakeChangeHelper(denominations, numDenominations, value - denominations[0], output);

    // exclude denominations[i]
    int y = countWaysToMakeChangeHelper(denominations + 1, numDenominations - 1, value, output);

    int ans = x + y;
    output[numDenominations][value] = ans;
    return ans;
}

int countWaysToMakeChange(int denominations[], int numDenominations, int value)
{
    int **output = new int *[numDenominations + 1];
    for (int i = 0; i <= numDenominations; i++)
    {
        output[i] = new int[value + 1];
        for (int j = 0; j <= value; j++)
        {
            output[i][j] = -1;
        }
    }

    return countWaysToMakeChangeHelper(denominations, numDenominations, value, output);
}

int main()
{

    int numDenominations;
    cin >> numDenominations;

    int *denominations = new int[numDenominations];

    for (int i = 0; i < numDenominations; i++)
    {
        cin >> denominations[i];
    }

    int value;
    cin >> value;

    cout << countWaysToMakeChange(denominations, numDenominations, value);

    delete[] denominations;
}