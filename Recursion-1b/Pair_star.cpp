// Given a string S, compute recursively a new string where identical chars that are adjacent in the original string are separated from each other by a "*".
#include <iostream>
using namespace std;

int length(char input[])
{
    int len = 0;
    for (int i = 0; input[i] != '\0'; i++)
    {
        len++;
    }
    return len;
}
void pairStar(char input[], int start)
{
    if (input[start] == '\0')
    {
        return;
    }
    pairStar(input, start + 1);
    if (input[start] == input[start + 1])
    {
        int len = length(input);
        input[len + 1] = '\0';
        int i;
        for (i = len - 1; i >= start + 1; i--)
        {
            input[i + 1] = input[i];
        }
        input[i + 1] = '*';
    }
}
void pairStar(char input[])
{
    pairStar(input, 0);
}

int main()
{
    char input[100];
    cin.getline(input, 100);
    pairStar(input);
    cout << input << endl;
}