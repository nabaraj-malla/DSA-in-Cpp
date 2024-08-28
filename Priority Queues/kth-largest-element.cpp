// Problem statement
// Given an array 'arr' of random integers and an integer 'k', return the kth largest element in the array.

#include <queue>
int kthLargest(int *arr, int n, int k)
{
    // Write your code here
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }
    for (int i = k; i < n; i++)
    {
        int extract = arr[i];
        if (extract > pq.top())
        {
            pq.pop();
            pq.push(extract);
        }
    }
    return pq.top();
}