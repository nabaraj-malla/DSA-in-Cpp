// Problem statement
// Given an input string (STR), print all possible permutations of the input string.

// Note:
// The input string may contain the same characters, so there will also be the same permutations.
// The order of permutations doesn’t matter.
#include <iostream>
#include <string>
using namespace std;
void helper(string input, string output[], int m)
{
    if (input.size() == 0)
    {
        for (int i = 0; i < m; i++)
        {
            cout << output[i];
        }
        cout << endl;
        // int m=0;
        return;
    }
    for (int i = 1; i <= input.size(); i++)
    {
        char ch = input[i - 1];
        string output1[1000];
        int j = 0;
        for (; j < m; j++)
        {
            output1[j] = output[j];
        }
        output1[j] = ch;
        helper(input.substr(0, i - 1) + input.substr(i, input.size() - 1), output1, m + 1);
    }
}
void printPermutations(string input)
{

    /* Don't write main() function.
     * Don't read input, it is passed as function argument.
     * Print output as specified in the question
     */
    string output[100];
    int m = 0;
    helper(input, output, m);
}

int main()
{
    string input;
    cin >> input;
    printPermutations(input);
    return 0;
}
