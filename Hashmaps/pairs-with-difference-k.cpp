// Problem statement
// You are given with an array of integers and an integer K. You have to find and print the count of all such pairs which have difference K.

// Note: Take absolute difference between the elements of the array.
#include <iostream>
using namespace std;

#include <unordered_map>
int getPairsWithDifferenceK(int *arr, int n, int k)
{
    unordered_map<int, int> freq;
    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }
    int count = 0;
    if (k == 0)
    {
        for (int i = 0; i < n; i++)
        {
            if (freq[arr[i]] > 1)
            {
                int f = freq[arr[i]] - 1;
                while (f > 0)
                {
                    count = count + f;
                    f = f - 1;
                }
            }
            freq[arr[i]] = 0;
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (freq.find(arr[i] + k) != freq.end())
            {
                count = count + (freq[arr[i]] * freq[arr[i] + k]);
            }
            if (freq.find(arr[i] - k) != freq.end())
            {
                count = count + (freq[arr[i]] * freq[arr[i] - k]);
            }
            freq.erase(arr[i]);
        }
    }

    return count;
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

    int k;
    cin >> k;

    cout << getPairsWithDifferenceK(input, n, k);

    delete[] input;
}