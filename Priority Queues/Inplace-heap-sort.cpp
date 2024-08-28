// Problem statement
// Given an integer array of size N. Sort this array (in decreasing order) using heap sort.

// Note: Space complexity should be O(1).
#include <iostream>
void heapSort(int arr[], int n)
{
    if (n == 0)
    {
        return;
    }
    for (int i = 1; i < n; i++)
    {
        int childIndex = i;
        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;
            if (arr[childIndex] < arr[parentIndex])
            {
                int temp = arr[parentIndex];
                arr[parentIndex] = arr[childIndex];
                arr[childIndex] = temp;
                childIndex = parentIndex;
            }
            else
            {
                break;
            }
        }
    }
    int size = n;
    while (size > 1)
    {
        int ans = arr[0];
        arr[0] = arr[size - 1];
        arr[size - 1] = ans;
        size--;
        int parentIndex = 0;
        // int minIndex;
        int leftChildIndex = 2 * parentIndex + 1;
        int rightChildIndex = 2 * parentIndex + 2;
        while (leftChildIndex < size)
        {
            int minIndex = parentIndex;
            if (arr[minIndex] > arr[leftChildIndex])
            {
                minIndex = leftChildIndex;
            }
            if (rightChildIndex < size && arr[rightChildIndex] < arr[minIndex])
            {
                minIndex = rightChildIndex;
            }
            if (minIndex == parentIndex)
            {
                break;
            }
            int temp = arr[minIndex];
            arr[minIndex] = arr[parentIndex];
            arr[parentIndex] = temp;
            parentIndex = minIndex;
            leftChildIndex = 2 * parentIndex + 1;
            rightChildIndex = 2 * parentIndex + 2;
        }
    }
}

using namespace std;

int main()
{
    int size;
    cin >> size;

    int *input = new int[size];

    for (int i = 0; i < size; i++)
    {
        cin >> input[i];
    }

    heapSort(input, size);

    for (int i = 0; i < size; i++)
    {
        cout << input[i] << " ";
    }

    delete[] input;
}