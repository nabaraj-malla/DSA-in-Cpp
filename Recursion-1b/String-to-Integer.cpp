// Write a recursive function to convert a given string into the number it represents.
// That is input will be a numeric string that contains only numbers,
// you need to convert the string into corresponding integer and return the answer.
#include <iostream>
using namespace std;

int stringLength(char input[])
{
    int len = 0;
    for (int i = 0; input[i] != '\0'; i++)
    {
        len++;
    }
    return len;
}
int stringToNumber(char input[])
{
    // Write your code here
    if (stringLength(input) == 1)
    {
        return input[0] - '0';
    }
    int smallOutput = stringToNumber(input + 1);
    int b = input[0] - '0';
    int power = 1;
    for (int i = 1; i <= stringLength(input) - 1; i++)
    {
        power = power * 10;
    }
    return b * power + smallOutput;
}

int main()
{
    char input[50];
    cin >> input;
    cout << stringToNumber(input) << endl;
}
