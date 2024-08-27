// Problem statement
// Given an array of length N, you need to find and return the sum of all elements of the array.

#include <iostream>
using namespace std;

int sum(int input[], int n)
{
    if (n == 1)
    {
        return input[0];
    }
    int res = sum(input + 1, n - 1);
    return res + input[0];
}

int main()
{
    int n;
    cin >> n;

    int *input = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    cout << sum(input, n) << endl;
}
