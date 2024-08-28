// Problem statement
// Given two strings s and t of lengths m and n respectively, find the edit distance between the strings.

// Edit Distance
// Edit Distance of two strings is minimum number of operations required to make one string equal to other. In order to do so you can perform any of the following three operations only :
// 1. Delete a character
// 2. Replace a character with another one
// 3. Insert a character
// Note
// Strings don't contain spaces
// You need to find the edit distance from input string1 to input string2.
#include <cstring>
#include <iostream>
using namespace std;

int editDistance(string s1, string s2)
{
    // Write your code here
    if (s1.length() == 0 || s2.length() == 0)
    {
        return max(s1.length(), s2.length());
    }

    if (s1[0] == s2[0])
    {
        return editDistance(s1.substr(1), s2.substr(1));
    }
    else
    {
        int insertDistance = editDistance(s1.substr(1), s2) + 1;
        int removeDistance = editDistance(s1, s2.substr(1)) + 1;
        int replaceDistance = editDistance(s1.substr(1), s2.substr(1)) + 1;
        return min(insertDistance, min(removeDistance, replaceDistance));
    }
}

int main()
{
    string s1;
    string s2;

    cin >> s1;
    cin >> s2;

    cout << editDistance(s1, s2);
}