// Problem statement
// For a given singly linked list of integers, arrange the nodes such that all the even number nodes are placed after the all odd number nodes. The relative order of the odd and even terms should remain unchanged.

// Note :
// 1. No need to print the linked list, it has already been taken care. Only return the new head to the list.
// 2. Don't create a new linked list.
// 3.  Just change the data, instead rearrange the provided list.

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
Node *evenAfterOdd(Node *head)
{
    // write your code here
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *evenHead = NULL, *evenTail = NULL, *oddHead = NULL, *oddTail = NULL, *temp = head;
    while (temp != NULL)
    {
        if ((temp->data % 2) == 0)
        {
            if (evenHead == NULL)
            {
                evenHead = temp;
                evenTail = temp;
            }
            else
            {
                evenTail->next = temp;
                evenTail = temp;
            }
        }
        else
        {
            if (oddHead == NULL)
            {
                oddHead = temp;
                oddTail = temp;
            }
            else
            {
                oddTail->next = temp;
                oddTail = temp;
            }
        }
        temp = temp->next;
    }
    if (oddHead == NULL)
    {
        return evenHead;
    }
    if (evenHead == NULL)
    {
        return oddHead;
    }
    evenTail->next = NULL;
    oddTail->next = NULL;
    oddTail->next = evenHead;
    return oddHead;
}

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

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Node *head = takeinput();
        head = evenAfterOdd(head);
        print(head);
    }
    return 0;
}