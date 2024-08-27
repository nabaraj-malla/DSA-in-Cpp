// You have been given an integer array/list(ARR) and a number 'num'. Find and return the total number of pairs in the array/list which sum to 'num'.

// Note: Given array/list can contain duplicate elements.
#include <iostream>
#include <algorithm>
using namespace std;

int pairSum(int *arr, int n, int num)
{
    // int start=0,end=n-1;
    // mergeSort(arr,start,end);
    sort(arr, arr + n);
    int pairSum = 0;
    int startIndex = 0, endIndex = n - 1;
    while (startIndex < endIndex)
    {
        if (arr[startIndex] + arr[endIndex] > num)
        {
            endIndex--;
        }
        else if (arr[startIndex] + arr[endIndex] < num)
        {
            startIndex++;
        }
        else
        {
            if (arr[startIndex] == arr[endIndex])
            {
                int countElement = (endIndex - startIndex) + 1;
                int totalCount = ((countElement) * (countElement - 1)) / 2;
                return pairSum = pairSum + totalCount;
                // startIndex=countElement+startIndex;
                // endIndex=endIndex-countElement;
            }
            else
            {
                int count1 = 0, count2 = 0;
                for (int k = startIndex; k <= endIndex; k++)
                {
                    if (arr[k] == arr[startIndex])
                    {
                        count1++;
                    }
                }
                for (int k = endIndex; k >= startIndex; k--)
                {
                    if (arr[k] == arr[endIndex])
                    {
                        count2++;
                    }
                }
                pairSum = pairSum + (count1 * count2);
                startIndex = startIndex + count1;
                endIndex = endIndex - count2;
            }
        }
    }
    return pairSum;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int size;
        int x;

        cin >> size;
        int *input = new int[size];

        for (int i = 0; i < size; i++)
        {
            cin >> input[i];
        }

        cin >> x;

        cout << pairSum(input, size, x) << endl;

        delete[] input;
    }

    return 0;
}