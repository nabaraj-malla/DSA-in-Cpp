// Problem statement
// Given a string S, you need to remove all the duplicates.
// That means, the output string should contain each character only once.
// The respective order of characters should remain same, as in the input string.
#include <iostream>
#include <string>
using namespace std;

#include <unordered_map>
string uniqueChar(string str)
{
    // Write your code here
    unordered_map<char, int> freq;
    string output;
    for (int i = 0; i < str.length(); i++)
    {
        if (freq[str[i]] > 0)
        {
            continue;
        }
        freq[str[i]] = true;
        output += str[i];
    }
    return output;
}

int main()
{
    string str;
    cin >> str;
    cout << uniqueChar(str);
}