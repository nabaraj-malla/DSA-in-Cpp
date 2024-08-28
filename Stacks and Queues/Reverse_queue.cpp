// Problem statement
// You have been given a queue that can store integers as the data.
// You are required to write a function that reverses the populated queue itself without using any other data structures.
#include <iostream>
using namespace std;

#include <queue>
void reverseQueue(queue<int> &input)
{
    // Write your code here
    if (input.size() <= 1)
    {
        return;
    }
    int front = input.front();
    input.pop();
    reverseQueue(input);
    input.push(front);
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        queue<int> q;
        int size;
        cin >> size;

        for (int i = 0, val; i < size; i++)
        {
            cin >> val;
            q.push(val);
        }

        reverseQueue(q);
        while (!q.empty())
        {
            cout << q.front() << " ";
            q.pop();
        }

        cout << "\n";
    }
}