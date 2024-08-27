// Given a string, compute recursively a new string where all 'x' chars have been removed.
#include <iostream>
using namespace std;

void removeX(char input[])
{
    // Write your code here
    if (input[0] == '\0')
    {
        return;
    }
    removeX(input + 1);
    if (input[0] == 'x')
    {
        int len = 0;
        for (int i = 0; input[i] != '\0'; i++)
        {
            len++;
        }
        for (int i = 0; i <= len; i++)
        {
            input[i] = input[i + 1];
        }
    }
}

int main()
{
    char input[100];
    cin.getline(input, 100);
    removeX(input);
    cout << input << endl;
}