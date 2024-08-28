// Problem statement
// You are given an array of integers that contain numbers in random order. Write a program to find and return the number which occurs the maximum times in the given input.

// If two or more elements are having the maximum frequency, return the element which occurs in the array first.
#include <iostream>
using namespace std;

#include <unordered_map>
int highestFrequency(int arr[], int n)
{
    unordered_map<int, int> maxFrequency;
    for (int i = 0; i < n; i++)
    {
        maxFrequency[arr[i]]++;
    }
    int max = 0;
    int value = 0;
    for (int i = 0; i < n; i++)
    {
        if (maxFrequency.at(arr[i]) > max)
        {
            max = maxFrequency.at(arr[i]);
            value = arr[i];
        }
    }
    return value;
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

    cout << highestFrequency(arr, n);

    delete[] arr;
}