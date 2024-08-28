// Problem statement
// You are given an array of integers and a target K. You have to find the count of subsets of the given array that sum up to K.

// Note:
// 1. Subset can have duplicate values.
// 2. Empty subset is a valid subset and has sum equal to zero.
#include <iostream>
using namespace std;
int subsetSumToK(int *arr, int size, int index, int k)
{
    // base case
    if (k < 0) // not mandotary
    {
        return 0;
    }
    if (index == size)
    {
        if (k == 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    // recursive call including the element
    int option1 = subsetSumToK(arr, size, index + 1, k - arr[index]);
    // recursive call excluding the element
    int option2 = subsetSumToK(arr, size, index + 1, k);
    // small calculation
    return option1 + option2;
}
int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n, k;
        cin >> n;
        cin >> k;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << subsetSumToK(arr, n, 0, k) << endl;
    }
    return 0;
}