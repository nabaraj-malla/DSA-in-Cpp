// Problem statement
// A child is running up a staircase with n steps and can hop either 1 step, 2 steps or 3 steps at a time. Implement a method to count how many possible ways the child can run up to the stairs. You need to return all possible number of ways.

// Time complexity of your code should be O(n).
// Since the answer can be pretty large soo print the answer with mod(10^9 +7)

#include <iostream>
#include <limits.h>
using namespace std;
long staircase(int n)
{
    long ans[n + 1];

    ans[1] = 1;
    ans[2] = 2;
    ans[3] = 4;
    for (int i = 4; i <= n; i++)
    {
        ans[i] = (ans[i - 1] % (1000000007) + ans[i - 2] % (1000000007) + ans[i - 3] % (1000000007)) % 1000000007;
    }
    return ans[n];
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << staircase(n) << endl;
    }
    return 0;
}