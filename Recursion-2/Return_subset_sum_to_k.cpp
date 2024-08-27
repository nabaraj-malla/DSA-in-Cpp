// Problem statement
// Given an array A of size n and an integer K, return all subsets of A which sum to K.

#include <iostream>
using namespace std;

int subsetSumToK(int input[], int n, int output[][50], int k)
{
    // Write your code here
    if (n == 0)
    {
        if (k == 0)
        {
            // output[0][0]=0;
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int output1[1000][50];
    int output2[1000][50];
    int size1 = subsetSumToK(input + 1, n - 1, output2, k);
    int size2 = subsetSumToK(input + 1, n - 1, output1, k - input[0]);
    for (int i = 0; i < size2; i++)
    {
        int output1Column = output1[i][0] + 1;
        output[i][0] = output1Column;
        output[i][1] = input[0];
        for (int j = 2; j <= output1Column; j++)
        {
            output[i][j] = output1[i][j - 1];
        }
    }
    for (int i = size2; i < size2 + size1; i++)
    {
        // output[i][0]=output2[i-size1][0];
        for (int j = 0; j <= output2[i - size2][0]; j++)
        {
            output[i][j] = output2[i - size2][j];
        }
    }
    return size1 + size2;
}

int main()
{
    int input[20], length, output[10000][50], k;
    cin >> length;
    for (int i = 0; i < length; i++)
        cin >> input[i];

    cin >> k;

    int size = subsetSumToK(input, length, output, k);

    for (int i = 0; i < size; i++)
    {
        for (int j = 1; j <= output[i][0]; j++)
        {
            cout << output[i][j] << " ";
        }
        cout << endl;
    }
}