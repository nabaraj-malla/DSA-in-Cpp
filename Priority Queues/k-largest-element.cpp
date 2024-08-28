// Problem statement
// You are given with an integer k and an array of integers that contain numbers in random order. Write a program to find k largest numbers from given array. You need to save them in an array and return it.

// Time complexity should be O(nlogk) and space complexity should be not more than O(k).
#include <iostream>
#include <vector>
using namespace std;
#include <queue>
vector<int> kLargest(int input[], int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> p;
    for (int i = 0; i < k; i++)
    {
        p.push(input[i]);
    }
    for (int i = k; i < n; i++)
    {
        int extract = input[i];
        if (extract > p.top())
        {
            p.pop();
            p.push(extract);
        }
    }
    vector<int> output;
    while (!p.empty())
    {
        output.push_back(p.top());
        p.pop();
    }
    return output;
}

int main()
{

    int size;
    cin >> size;
    int *input = new int[1 + size];

    for (int i = 0; i < size; i++)
        cin >> input[i];

    int k;
    cin >> k;

    vector<int> output = kLargest(input, size, k);
    for (int i = 0; i < output.size(); i++)
        cout << output[i] << endl;

    return 0;
}