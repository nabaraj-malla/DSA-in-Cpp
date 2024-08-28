// Problem statement
// Given an array of integers, check whether it represents max-heap or not.
//  Return true if the given array represents max-heap, else return false.
#include <iostream>
using namespace std;

bool helper(int arr[], int n, int parent)
{
    if (n == 0 || parent >= n)
    {
        return true;
    }
    int leftChildIndex = 2 * parent + 1;
    int rightChildIndex = 2 * parent + 2;
    if (leftChildIndex >= n)
    {
        return true;
    }
    if (leftChildIndex < n && arr[parent] < arr[leftChildIndex])
    {
        return false;
    }
    if (rightChildIndex >= n)
    {
        return true;
    }
    if (rightChildIndex < n && arr[parent] < arr[rightChildIndex])
    {
        return false;
    }
    bool ans1 = helper(arr, n, leftChildIndex);
    bool ans2 = helper(arr, n, rightChildIndex);
    return ans1 && ans2;
}
bool isMaxHeap(int arr[], int n)
{
    return helper(arr, n, 0);
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << (isMaxHeap(arr, n) ? "true\n" : "false\n");

    delete[] arr;
}