// Given a string, compute recursively a new string where all appearances of "pi" have been replaced by "3.14".
#include <iostream>
using namespace std;

void replacePi(char input[])
{
    // Write your code here
    if (input[0] == '\0')
    {
        return;
    }
    replacePi(input + 1);
    if (input[0] == 'p' && input[1] == 'i')
    {
        int len = 0;
        for (int i = 0; input[i] != '\0'; i++)
        {
            len++;
        }
        for (int j = len; j >= 2; j--)
        {
            input[j + 2] = input[j];
        }
        input[0] = '3';
        input[1] = '.';
        input[2] = '1';
        input[3] = '4';
    }
}

int main()
{
    char input[10000];
    cin.getline(input, 10000);
    replacePi(input);
    cout << input << endl;
}