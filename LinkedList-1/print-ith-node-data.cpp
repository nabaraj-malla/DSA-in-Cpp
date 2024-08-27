// Problem statement
// For a given a singly linked list of integers and a position 'i', print the node data at the 'i-th' position.

//  Note :
// Assume that the Indexing for the singly linked list always starts from 0.

// If the given position 'i',  is greater than the length of the given singly linked list, then don't print anything.
#include <iostream>
using namespace std;

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

Node *takeinput()
{
    int data;
    cin >> data;
    Node *head = NULL, *tail = NULL;
    while (data != -1)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

void printIthNode(Node *head, int i)
{
    // Write your code here
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        if (count == i)
        {
            cout << temp->data;
            break;
        }
        count++;
        temp = temp->next;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Node *head = takeinput();
        int pos;
        cin >> pos;
        printIthNode(head, pos);
        cout << endl;
    }
    return 0;
}