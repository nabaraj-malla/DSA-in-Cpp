// Problem statement
// You have been given a singly linked list of integers along with an integer 'N'.
// Write a function to append the last 'N' nodes towards the front of the singly linked list and returns the new head to the list.
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

int length(Node *head)
{
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

Node *appendLastNToFirst(Node *head, int n)
{
    if (n == 0)
    {
        return head;
    }
    int len = length(head);
    if (n > len)
    {
        return head;
    }
    int m = len - n;
    int count = 0;
    Node *temp = head;
    while (count < m - 1)
    {
        count++;
        temp = temp->next;
    }
    Node *newHead = temp->next;
    temp->next = NULL;
    Node *newtemp = newHead;
    while (newtemp->next != NULL)
    {
        newtemp = newtemp->next;
    }
    newtemp->next = head;
    return newHead;
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
        int n;
        cin >> n;
        head = appendLastNToFirst(head, n);
        print(head);
    }
    return 0;
}
