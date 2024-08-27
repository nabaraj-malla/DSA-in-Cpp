// Problem statement
// Given a string S, find and return all the possible permutations of the input string.

// Note 1 : The order of permutations is not important. Note 2 : If original string contains duplicate characters, permutations will also be duplicates.
#include <iostream>
#include <string>
using namespace std;

int returnPermutations(string input, string output[])
{

    if (input.size() == 1)
    {
        output[0] = input[0];
        return 1;
    }
    int r = 0;
    for (int i = 1; i <= input.size(); i++)
    {
        string output1[10000];
        char ch = input[i - 1];
        int size = returnPermutations(input.substr(0, i - 1) + input.substr(i, input.size() - 1), output1);
        for (int i = 0; i < size; i++)
        {
            output[r++] = ch + output1[i];
        }
    }
    return r;
}

int main()
{
    string input;
    cin >> input;
    string output[10000];
    int count = returnPermutations(input, output);
    for (int i = 0; i < count && i < 10000; i++)
    {
        cout << output[i] << endl;
    }
    return 0;
}