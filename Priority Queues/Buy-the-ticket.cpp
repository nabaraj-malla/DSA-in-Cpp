// 2. If there is another person present in the queue who has higher priority than pi,
//    then ask pi to move at end of the queue without giving him the ticket.
// 3. Otherwise, give him the ticket (and don't make him stand in queue again).
// Giving a ticket to a person takes exactly 1 minutes and it takes no time for removing and adding a person to the queue.
// And you can assume that no new person joins the queue.
// Given a list of priorities of N persons standing in the queue and the index of your priority (indexing starts from 0).
// Find and return the time it will take until you get the ticket.

// Input Format :
// Line 1 : Integer N (Total number of people standing in queue)
// Line 2 : Priorities of every person (n space separated integers)
// Line 3 : Integer k (index of your priority)
// Output Format :
// Time required
// Sample Input 1 :
// 3
// 3 9 4
// 2
// Sample Output 1 :
// 2
// Sample Output 1 Explanation :
// Person with priority 3 comes out. But there is a person with higher priority than him. So he goes and then stands in the queue at the end. Queue's status : {9, 4, 3}. Time : 0 secs.
// Next, the person with priority 9 comes out. And there is no person with higher priority than him. So he'll get the ticket. Queue's status : {4, 3}. Time : 1 secs.
// Next, the person with priority 4 comes out (which is you). And there is no person with higher priority than you. So you'll get the ticket. Time : 2 secs.
// Sample Input 2 :
// 5
// 2 3 2 2 4
// 3
// Sample Output 2 :
// 4
#include <iostream>
#include <vector>
using namespace std;

#include <queue>
int buyTicket(int *arr, int n, int k)
{
    // Write your code here
    priority_queue<int> maxHeap;
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        q.push(i);
        maxHeap.push(arr[i]);
    }
    int extract = q.front();
    int time = 0;
    while (extract != k || arr[extract] != maxHeap.top())
    {
        if (arr[extract] == maxHeap.top())
        {
            time = time + 1;
            q.pop();
            maxHeap.pop();
        }
        else
        {
            q.pop();
            q.push(extract);
        }
        extract = q.front();
    }
    return time + 1;
}

int main()
{
    int n;
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    cout << buyTicket(arr, n, k);

    delete[] arr;
}