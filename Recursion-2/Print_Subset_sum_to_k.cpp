// Problem statement
// Given an array A and an integer K, print all subsets of A which sum to K.

// Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.
#include <iostream>
using namespace std;

void helper(int input[], int size, int k, int output[], int m)
{
    if (size == 0)
    {
        if (k == 0)
        {
            for (int i = 0; i < m; i++)
            {
                cout << output[i] << " ";
            }
            cout << endl;
            return;
        }
        else
        {
            return;
        }
    }
    // helper(input+1,size-1,k,output,m);
    // int newOutput[m];
    int i = 0;
    for (; i < m; i++)
    {
        output[i] = output[i];
    }
    output[i] = input[0];
    helper(input + 1, size - 1, k - input[0], output, m + 1);
    helper(input + 1, size - 1, k, output, m);
}
void printSubsetSumToK(int input[], int size, int k)
{
    // Write your code here
    int m = 0;
    int *output = new int[m];
    helper(input, size, k, output, m);
}

int main()
{
    int input[1000], length, k;
    cin >> length;
    for (int i = 0; i < length; i++)
        cin >> input[i];
    cin >> k;
    printSubsetSumToK(input, length, k);
}