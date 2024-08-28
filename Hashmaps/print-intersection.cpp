// Problem statement
// You have been given two integer arrays/lists (ARR1 and ARR2) of size N and M, respectively.
// You need to print their intersection; An intersection for this problem can be defined when both the arrays/lists contain a particular value or to put it in other words,
// when there is a common value that exists in both the arrays/lists.

// Note :
// Input arrays/lists can contain duplicate elements.

// The intersection elements printed would be in the order they appear in the second array/list (ARR2).
#include <iostream>
using namespace std;

#include <algorithm>
#include <unordered_map>
void printIntersection(int arr1[], int arr2[], int n, int m)
{
    // Write your code here
    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);
    unordered_map<int, int> map1;
    unordered_map<int, int> map2;
    for (int i = 0; i < n; i++)
    {
        map1[arr1[i]]++;
    }
    for (int j = 0; j < m; j++)
    {
        map2[arr2[j]]++;
    }
    int i = 0;
    int j = 0;
    while (i < n && j < m)
    {
        if (arr1[i] == arr2[j])
        {
            int count = 0;
            while (map1[arr1[i]] > 0 && map2[arr2[j]] > 0)
            {
                cout << arr1[i] << endl;
                map1[arr1[i]]--;
                map2[arr2[j]]--;
                count++;
                //				i++;// if we write this statements it won't check whether valuea are same or not
                //				j++;// only check map value;
            }
            i = i + count;
            j = j + count;
        }
        else if (arr1[i] > arr2[j])
        {
            j++;
        }
        else
        {
            i++;
        }
    }
}

int main()
{
    int n;
    cin >> n;

    int *arr1 = new int[n];

    for (int i = 0; i < n; ++i)
    {
        cin >> arr1[i];
    }

    int m;
    cin >> m;

    int *arr2 = new int[m];

    for (int i = 0; i < m; ++i)
    {
        cin >> arr2[i];
    }

    printIntersection(arr1, arr2, n, m);

    delete[] arr1;
    delete[] arr2;
}