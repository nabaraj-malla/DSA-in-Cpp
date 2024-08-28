// Problem statement
// Given an array consisting of positive and negative integers, find the length of the longest subarray whose sum is zero.
#include <iostream>
using namespace std;

#include <unordered_map>
int lengthOfLongestSubsetWithZeroSum(int *arr, int n)
{
    // Write your code here
    unordered_map<int, int> map;
    int val = 0;
    int maxlen = 0, len = 0;
    for (int i = 0; i < n; i++)
    {
        val = val + arr[i];
        if (arr[i] == 0 && maxlen == 0)
            maxlen = 1;
        if (val == 0)
            maxlen = i + 1;
        if (map.find(val) == map.end())
        {
            map[val] = i;
        }
        else if (map.find(val) != map.end())
        {
            // unordered_map<int, int>:: iterator it = map.find(val);
            // len = i - it->second;
            // maxlen = max(len, maxlen);
            maxlen = max(i - map[val], maxlen);
        }
    }
    return maxlen;
}

int main()
{
    int size;
    cin >> size;

    int *arr = new int[size];

    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    cout << lengthOfLongestSubsetWithZeroSum(arr, size);

    delete[] arr;
}