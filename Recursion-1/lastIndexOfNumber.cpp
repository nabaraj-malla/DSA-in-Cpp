// Problem statement
// Given an array of length N and an integer x, you need to find and return the last index of integer x present in the array. Return -1 if it is not present in the array.
// Last index means - if x is present multiple times in the array, return the index at which x comes last in the array.
// You should start traversing your array from 0, not from (N - 1).
// Do this recursively. Indexing in the array starts from 0.

#include <iostream>
using namespace std;

int lastIndex(int input[], int size, int x)
{
    //     if(size==0){
    //         return -1;
    //     }
    //     int ans=lastIndex(input+1,size-1,x);
    //     if(ans==-1){
    //         if(input[0]==x){
    //             return 0;
    //         }
    //         else{
    //             return ans;
    //         }
    //     }
    //     else{
    //         return ans+1;
    //     }
    if (size == 0)
    {
        return -1;
    }
    if (input[size - 1] == x)
    {
        return size - 1;
    }
    int smallOutput = lastIndex(input, size - 1, x);
    return smallOutput;
    // 	if(smallOutput==-1){
    // 		return -1;
    // 	}
    // 	else{
    // 		return smallOutput;
    // 	}
}

int main()
{
    int n;
    cin >> n;

    int *input = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    int x;

    cin >> x;

    cout << lastIndex(input, n, x) << endl;
}
