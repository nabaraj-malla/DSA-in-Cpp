// Problem statement
// Implement the class for Max Priority Queue which includes following functions -
// 1. getSize -
// Return the size of priority queue i.e. number of elements present in the priority queue.
// 2. isEmpty -

// Check if priority queue is empty or not. Return true or false accordingly.
// 3. insert -

// Given an element, insert that element in the priority queue at the correct position.
// 4. getMax -

// Return the maximum element present in the priority queue without deleting. Return -Infinity if priority queue is empty.

// 5. removeMax -
// Delete and return the maximum element present in the priority queue. Return -Infinity if priority queue is empty.
#include <iostream>
using namespace std;

#include <vector>
#include <math.h>
class PriorityQueue
{
    // Declare the data members here
    vector<int> pq;

public:
    PriorityQueue()
    {
        // Implement the constructor here
    }

    /**************** Implement all the public functions here ***************/

    void insert(int element)
    {
        // Implement the insert() function here
        pq.push_back(element);
        int childIndex = pq.size() - 1;
        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;
            if (pq[childIndex] > pq[parentIndex])
            {
                swap(pq[childIndex], pq[parentIndex]);
                childIndex = parentIndex;
            }
            else
            {
                break;
            }
        }
    }

    int getMax()
    {
        // Implement the getMax() function here
        if (isEmpty())
        {
            return INFINITY;
        }
        else
        {
            return pq[0];
        }
    }

    int removeMax()
    {
        // Implement the removeMax() function here
        if (isEmpty())
        {
            return INFINITY;
        }
        int ans = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();
        int parentIndex = 0;
        int maxIndex = 0;
        int leftChildIndex = 2 * parentIndex + 1;
        int rightChildIndex = 2 * parentIndex + 2;
        while (leftChildIndex < pq.size())
        {
            if (rightChildIndex < pq.size())
            {
                if (pq[leftChildIndex] > pq[rightChildIndex])
                {
                    maxIndex = leftChildIndex;
                }
                else
                {
                    maxIndex = rightChildIndex;
                }
                if (pq[maxIndex] > pq[parentIndex])
                {
                    swap(pq[maxIndex], pq[parentIndex]);
                    parentIndex = maxIndex;
                }
            }
            else if (rightChildIndex >= pq.size())
            {
                if (pq[leftChildIndex] > pq[parentIndex])
                {
                    maxIndex = leftChildIndex;
                    swap(pq[maxIndex], pq[parentIndex]);
                    parentIndex = maxIndex;
                }
                else
                {
                    break;
                }
            }
            leftChildIndex = 2 * parentIndex + 1;
            rightChildIndex = 2 * parentIndex + 2;
        }
        return ans;
    }

    int getSize()
    {
        // Implement the getSize() function here
        return pq.size();
    }

    bool isEmpty()
    {
        // Implement the isEmpty() function here
        return pq.size() == 0;
    }
};

int main()
{
    PriorityQueue pq;
    int choice;
    cin >> choice;

    while (choice != -1)
    {
        switch (choice)
        {
        case 1: // insert
            int element;
            cin >> element;
            pq.insert(element);
            break;
        case 2: // getMax
            cout << pq.getMax() << "\n";
            break;
        case 3: // removeMax
            cout << pq.removeMax() << "\n";
            break;
        case 4: // size
            cout << pq.getSize() << "\n";
            break;
        case 5: // isEmpty
            cout << (pq.isEmpty() ? "true\n" : "false\n");
        default:
            return 0;
        }

        cin >> choice;
    }
}