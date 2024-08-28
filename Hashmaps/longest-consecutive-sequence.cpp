// Problem statement
// You are given an array of unique integers that contain numbers in random order.
// You have to find the longest possible sequence of consecutive numbers using the numbers from given array.

// You need to return the output array which contains starting and ending element.
// If the length of the longest possible sequence is one, then the output array must contain only single element.
#include <iostream>
#include <vector>
using namespace std;

#include <vector>
#include <unordered_map>
vector<int> longestConsecutiveIncreasingSequence(int *arr, int n)
{
    unordered_map<int, int> map;
    vector<int> output;
    for (int i = 0; i < n; i++)
    {
        map[arr[i]] = true;
    }
    int maxlength = 0;
    int start, end, cStart, smallerLen, greaterLen, smaller, greater;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == false)
        {
            continue;
        }
        cStart = arr[i];
        map[arr[i]] = false;
        smaller = cStart - 1;
        smallerLen = 0;
        greaterLen = 0;
        while ((map.find(smaller) != map.end()) && map[smaller] != false)
        {
            smaller--;
            smallerLen++;
        }
        greater = cStart + 1;
        while ((map.find(greater) != map.end()) && map[greater] != false)
        {
            greater++;
            greaterLen++;
        }
        if (1 + smallerLen + greaterLen > maxlength)
        {
            maxlength = 1 + smallerLen + greaterLen;
            start = cStart - smallerLen;
            end = cStart + greaterLen;
        }
        else if (1 + smallerLen + greaterLen == maxlength)
        {
            int val;
            for (int i = 0; i < n; i++)
            {
                if (arr[i] == start || arr[i] == cStart - smallerLen)
                {
                    val = arr[i];
                    break;
                }
            }
            if (val == cStart - smallerLen)
            {
                maxlength = 1 + smallerLen + greaterLen;
                start = cStart - smallerLen;
                end = cStart + greaterLen;
            }
        }
    }
    if (maxlength > 1)
    {
        output.push_back(start);
        output.push_back(end);
    }
    else
    {
        output.push_back(arr[0]);
    }
    return output;
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

    vector<int> ans = longestConsecutiveIncreasingSequence(arr, size);

    for (auto i = ans.begin(); i != ans.end(); ++i)
        cout << *i << " ";

    delete[] arr;
}
