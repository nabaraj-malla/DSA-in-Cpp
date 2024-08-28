// Problem statement
// You are given with an integer k and an array of integers that contain numbers in random order. Write a program to find k smallest numbers from given array. You need to save them in an array and return it.

// Time complexity should be O(n * logk) and space complexity should not be more than O(k).
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#include <queue>
vector<int> kSmallest(int arr[], int n, int k)
{
    // Write your code here
    priority_queue<int> pq;
    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }
    for (int i = k; i < n; i++)
    {
        int extract = arr[i];
        if (extract < pq.top())
        {
            pq.pop();
            pq.push(extract);
        }
    }
    vector<int> ans;
    while (!pq.empty())
    {
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}

int main()
{
    int size;
    cin >> size;

    int *input = new int[size];

    for (int i = 0; i < size; i++)
    {
        cin >> input[i];
    }

    int k;
    cin >> k;

    vector<int> output = kSmallest(input, size, k);
    sort(output.begin(), output.end());

    for (int i = 0; i < output.size(); i++)
    {
        cout << output[i] << " ";
    }

    delete[] input;
}