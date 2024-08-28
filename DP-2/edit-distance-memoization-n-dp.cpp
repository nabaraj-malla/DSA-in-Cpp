// Problem statement
// You are given two strings S and T of lengths M and N, respectively. Find the 'Edit Distance' between the strings.

// Edit Distance of two strings is the minimum number of steps required to make one string equal to the other. In order to do so, you can perform the following three operations:

// 1. Delete a character
// 2. Replace a character with another one
// 3. Insert a character
#include <iostream>
#include <cstring>
using namespace std;

int editDistanceHelper(string s1, string s2, int **output)
{
    int m = s1.length();
    int n = s2.length();
    if (m == 0 || n == 0)
    {
        return max(m, n);
    }

    if (output[m][n] != -1)
    {
        return output[m][n];
    }
    int ans;
    if (s1[0] == s2[0])
    {
        ans = editDistanceHelper(s1.substr(1), s2.substr(1), output);
        output[m][n] = ans;
        return ans;
    }
    else
    {
        int insertDistance = editDistanceHelper(s1.substr(1), s2, output) + 1;
        int removeDistance = editDistanceHelper(s1, s2.substr(1), output) + 1;
        int replaceDistance = editDistanceHelper(s1.substr(1), s2.substr(1), output) + 1;
        ans = min(insertDistance, min(removeDistance, replaceDistance));
        output[m][n] = ans;
        return ans;
    }
    return output[m][n];
}
int editDistance(string s1, string s2)
{
    int m = s1.length();
    int n = s2.length();
    int **output = new int *[m + 1];
    for (int i = 0; i <= m; i++)
    {
        output[i] = new int[n + 1];
        for (int j = 0; j <= n; j++)
        {
            output[i][j] = -1;
        }
    }

    return editDistanceHelper(s1, s2, output);
}

int main()
{
    string s1;
    string s2;

    cin >> s1;
    cin >> s2;

    cout << editDistance(s1, s2) << endl;
}