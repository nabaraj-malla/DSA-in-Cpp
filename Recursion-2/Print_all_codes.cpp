// Problem statement
// Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. Write a program to print the list of all possible codes that can be generated from the given string.

// Note : The order of codes are not important. Just print them in different lines.
#include <iostream>
using namespace std;

#include <string.h>
using namespace std;
int getNum(char c)
{
    return c - '0';
}
char getChar(int num)
{
    return num + 'a' - 1;
}
void helper(string input, string output[], int size)
{
    if (input.empty())
    {
        for (int i = 0; i < size; i++)
        {
            cout << output[i];
        }
        cout << endl;
        return;
    }
    if (input.size() < 0)
    {
        return;
    }
    string newOutput[100];
    int i = 0;
    for (; i < size; i++)
    {
        newOutput[i] = output[i];
    }
    newOutput[i] = getChar(getNum(input[0]));
    helper(input.substr(1), newOutput, size + 1);
    if (input.size() > 1)
    {
        if (getNum(input[0]) * 10 + getNum(input[1]) > 10 && getNum(input[0]) * 10 + getNum(input[1]) < 27)
        {
            int i = 0;
            for (; i < size; i++)
            {
                newOutput[i] = output[i];
            }
            newOutput[i] = getChar(getNum(input[0]) * 10 + getNum(input[1]));
            helper(input.substr(2), newOutput, size + 1);
        }
    }
}

void printAllPossibleCodes(string input)
{
    /*
    Given the input as a string, print all its possible combinations. You do not need to return anything.
    */
    string output[100];
    int size = 0;
    helper(input, output, size);
}

int main()
{
    string input;
    cin >> input;

    printAllPossibleCodes(input);
    return 0;
}
