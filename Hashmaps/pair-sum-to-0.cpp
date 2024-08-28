// Problem statement
// Given a random integer array A of size N. Find and print the count of pair of elements in the array which sum up to 0.
#include <iostream>
using namespace std;

#include <unordered_map>
int pairSum(int *arr, int n)
{
    unordered_map<int, int> freq;
    int num = 0;
    for (int i = 0; i < n; i++)
    {
        if (freq.find(-arr[i]) != freq.end())
        {
            int count = freq[-arr[i]];
            num = num + count;
            freq[arr[i]]++;
        }
        else
        {
            freq[arr[i]]++;
        }
    }
    return num;
}

int main()
{
    int n;
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    cout << pairSum(arr, n);

    delete[] arr;
}