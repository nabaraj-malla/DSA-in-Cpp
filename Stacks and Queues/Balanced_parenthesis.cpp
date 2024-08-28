// Problem statement
// For a given a string expression containing only round brackets or parentheses,
// check if they are balanced or not. Brackets are said to be balanced if the bracket which opens last, closes first.

#include <iostream>
#include <string>
using namespace std;

#include <stack>
bool isBalanced(string expression)
{
    // Write your code here
    stack<char> s;
    int i = 0;
    if (expression.empty())
    {
        return true;
    }
    while (i < expression.length())
    {
        if (expression[i] == '(' || expression[i] == '{' || expression[i] == '[')
        {
            s.push(expression[i]);
        }
        if (expression[i] == ')' || expression[i] == '}' || expression[i] == ']')
        {
            if (s.empty())
            {
                return false;
            }
            else if (expression[i] == ')' && s.top() == '(')
            {
                s.pop();
            }
            else if (expression[i] == '}' && s.top() == '{')
            {
                s.pop();
            }
            else if (expression[i] == ']' && s.top() == '[')
            {
                s.pop();
            }
            else
            {
                return false;
            }
        }
        i++;
    }
    if (s.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    string input;
    cin >> input;
    cout << ((isBalanced(input)) ? "true" : "false");
}