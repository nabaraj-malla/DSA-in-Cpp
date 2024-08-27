// Problem statement
// Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. Write a program to return the list of all possible codes that can be generated from the given string.

#include <iostream>
using namespace std;
#include <string.h>

int getNum(char c)
{
    return c - '0';
}
char getChar(int num)
{
    return num + 'a' - 1;
}
int getCodes(string input, string output[10000])
{
    /*
    You are given the input text and output string array. Find all possible codes and store in the output string array. DonÃ¢ÂÂt print the codes.
    Also, return the number of codes return to the output string. You do not need to print anything.
    */
    if (input.size() == 0)
    {
        return 1;
    }
    if (input.size() == 1)
    {
        output[0] = output[0] + getChar(getNum(input[0]));
        return 1;
    }
    string output1[10000], output2[10000];
    int size2 = 0;
    int size1 = getCodes(input.substr(1), output1);
    if (input.size() > 1)
    {
        if (getNum(input[0]) * 10 + getNum(input[1]) > 10 && getNum(input[0]) * 10 + getNum(input[1]) < 27)
        {
            size2 = getCodes(input.substr(2), output2);
        }
    }
    for (int i = 0; i < size1; i++)
    {
        output[i] = getChar(getNum(input[0])) + output1[i];
    }
    for (int i = 0; i < size2; i++)
    {
        output[i + size1] = getChar(getNum(input[0]) * 10 + getNum(input[1])) + output2[i];
    }
    return size1 + size2;
}

int main()
{
    string input;
    cin >> input;

    string output[10000];
    int count = getCodes(input, output);
    for (int i = 0; i < count && i < 10000; i++)
        cout << output[i] << endl;
    return 0;
}