// Given an integer n, using phone keypad find out and print all the possible strings that can be made using digits of input n.
#include <iostream>
#include <string>
using namespace std;

void printHelper(int num, string output)
{
    if (num == 0)
    {
        cout << output << endl;
        return;
    }
    string option[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    int n1 = num % 10;
    string s1 = option[n1];
    int num1 = num / 10;
    for (int i = 0; i < s1.length(); i++)
    {
        printHelper(num1, s1[i] + output);
    }
}
void printKeypad(int num)
{
    /*
    Given an integer number print all the possible combinations of the keypad. You do not need to return anything just print them.
    */
    string output = "";
    printHelper(num, output);
}

int main()
{
    int num;
    cin >> num;

    printKeypad(num);

    return 0;
}
