#include <iostream>
using namespace std;

void merge(int input[], int si, int ei)
{
    int mid = (si + ei) / 2;
    int i = si, j = mid + 1, k = 0;
    int *temp = new int[ei - si + 1];
    while (i <= mid && j <= ei)
    {
        if (input[i] < input[j])
        {
            temp[k] = input[i];
            i++;
            k++;
        }
        else
        {
            temp[k] = input[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        temp[k] = input[i];
        i++;
        k++;
    }
    while (j <= ei)
    {
        temp[k] = input[j];
        j++;
        k++;
    }
    int p = 0;
    for (int i = si; i <= ei; i++)
    {
        input[i] = temp[p];
        p++;
    }
}
void helper(int input[], int si, int ei)
{
    if (si >= ei)
    {
        return;
    }
    int mid = (si + ei) / 2;
    helper(input, si, mid);
    helper(input, mid + 1, ei);
    merge(input, si, ei);
}
void mergeSort(int input[], int size)
{
    // Write your code here
    if (size == 1 || size == 0)
    {
        return;
    }
    int si = 0, ei = size - 1;
    helper(input, si, ei);
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, arr_size - 1);

    for (int i = 0; i < arr_size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}