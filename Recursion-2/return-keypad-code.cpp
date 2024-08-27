// Problem statement
// Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.

// Return empty string for numbers 0 and 1.

// Note :
// 1. The order of strings are not important.
// 2. Input and output has already been managed for you. You just have to populate the output array and return the count of elements populated in the output array.
#include <iostream>
#include <string>
using namespace std;

int keypad(int num, string output[])
{
    /* Insert all the possible combinations of the integer number into the output string array. You do not need to
    print anything, just return the number of strings inserted into the array.
    */
    if (num == 0)
    {
        // output[0]="";
        return 1;
    }
    int size = keypad(num / 10, output);
    string option[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    int n1 = num % 10;
    string s1 = option[n1];
    string temp[10000];
    int k = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < s1.length(); j++)
        {
            temp[k] = output[i] + s1[j];
            k++;
        }
    }
    int ansSize = size * s1.length();
    for (int i = 0; i < ansSize; i++)
    {
        output[i] = temp[i];
    }
    return ansSize;
}

int main()
{
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for (int i = 0; i < count && i < 10000; i++)
    {
        cout << output[i] << endl;
    }
    return 0;
}