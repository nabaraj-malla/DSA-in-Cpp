// Problem statement
// You have been given two integer arrays/list(ARR1 and ARR2) of size N and M, respectively.
// You need to print their intersection; An intersection for this problem can be defined when both the arrays/lists contain a particular value or to put it in other words,
// when there is a common value that exists in both the arrays/lists.
#include <iostream>
#include <algorithm>
using namespace std;

void mergeSortedArray(int arr[], int start, int mid, int end)
{
    int i = start, j = mid + 1, k = 0, temp[100];
    while (i <= mid && j <= end)
    {
        if (arr[i] < arr[j])
        {
            temp[k] = arr[i];
            i++, k++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }
    while (j <= end)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }
    int p = 0;
    for (int i = start; i <= end; i++)
    {
        arr[i] = temp[p];
        p++;
    }
}
void mergeSort(int arr[], int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int mid = (start + end) / 2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    mergeSortedArray(arr, start, mid, end);
}
void intersection(int *arr1, int *arr2, int n, int m)
{
    int start = 0, end = n - 1;
    mergeSort(arr1, start, end);
    int s = 0, e = m - 1;
    mergeSort(arr2, s, e);
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (arr1[i] == arr2[j])
        {
            cout << arr1[i] << " ";
            i++;
            j++;
        }
        else if (arr1[i] < arr2[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int size1, size2;

        cin >> size1;
        int *input1 = new int[size1];

        for (int i = 0; i < size1; i++)
        {
            cin >> input1[i];
        }

        cin >> size2;
        int *input2 = new int[size2];

        for (int i = 0; i < size2; i++)
        {
            cin >> input2[i];
        }

        intersection(input1, input2, size1, size2);

        delete[] input1;
        delete[] input2;

        cout << endl;
    }

    return 0;
}