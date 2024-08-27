// Problem statement
// Given the number 'n', write a code to print numbers from 1 to n in increasing order recursively.
#include <iostream>
using namespace std;

void print(int n)
{
    if (n == 1)
    {
        cout << n << " ";
        return;
    }

    print(n - 1);
    cout << n << " ";
}
int main()
{
    int n;
    cin >> n;

    print(n);
}