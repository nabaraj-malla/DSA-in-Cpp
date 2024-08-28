// Problem statement
// You are given a stream of 'N' integers. For every 'i-th' integer added to the running list of integers, print the resulting median.

// Print only the integer part of the median.

#include <iostream>
using namespace std;

#include <queue>
#include <vector>
void findMedian(int *arr, int n)
{
    // Write your code here
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int i = 0; i < n; i++)
    {
        if (maxHeap.empty() && minHeap.empty())
        {
            maxHeap.push(arr[i]);
            cout << maxHeap.top() << " ";
        }
        else if (arr[i] < maxHeap.top())
        {
            maxHeap.push(arr[i]);
            if (maxHeap.size() - minHeap.size() > 1)
            {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                if (maxHeap.size() == minHeap.size())
                {
                    cout << (maxHeap.top() + minHeap.top()) / 2 << " ";
                }
                else if (maxHeap.size() - minHeap.size() == 1)
                {
                    cout << maxHeap.top() << " ";
                }
            }
            else if (maxHeap.size() == minHeap.size())
            {
                cout << (maxHeap.top() + minHeap.top()) / 2 << " ";
            }
            else
            {
                cout << maxHeap.top() << " ";
            }
        }
        else
        {
            minHeap.push(arr[i]);
            if (minHeap.size() - maxHeap.size() > 1)
            {
                maxHeap.push(minHeap.top());
                minHeap.pop();
                if (minHeap.size() == maxHeap.size())
                {
                    cout << (maxHeap.top() + minHeap.top()) / 2 << " ";
                }
                else if (minHeap.size() - maxHeap.size() == 1)
                {
                    cout << minHeap.top() << " ";
                }
            }
            else if (minHeap.size() == maxHeap.size())
            {
                cout << (maxHeap.top() + minHeap.top()) / 2 << " ";
            }
            else
            {
                cout << minHeap.top() << " ";
            }
        }
    }
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

    findMedian(arr, n);

    delete[] arr;
}
