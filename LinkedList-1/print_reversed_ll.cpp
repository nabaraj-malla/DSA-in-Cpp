// Problem statement
// You have been given a singly linked list of integers. Write a function to print the list in a reverse order.

// To explain it further, you need to start printing the data from the tail and move towards the head of the list, printing the head data at the end.
#include <iostream>

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

using namespace std;

Node *takeinput()
{
    int data;
    cin >> data;
    Node *head = NULL, *tail = NULL;
    while (data != -1)
    {
        Node *newnode = new Node(data);
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
        cin >> data;
    }
    return head;
}

void printReverse(Node *head)
{
    // Write your code here
    if (head == NULL)
    {
        return;
    }
    printReverse(head->next);
    cout << head->data << " ";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Node *head = takeinput();
        printReverse(head);
        cout << endl;
    }
    return 0;
}