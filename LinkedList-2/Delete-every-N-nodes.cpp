// Problem statement
// You have been given a singly linked list of integers along with two integers, 'M,' and 'N.' Traverse the linked list such that you retain the 'M' nodes, then delete the next 'N' nodes. Continue the same until the end of the linked list. Indexing starts from 1.

// To put it in other words, in the given linked list, you need to delete N nodes after every M nodes.
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
Node *skipMdeleteN(Node *head, int M, int N)
{
    // Write your code here
    if (N == 0)
    {
        return head;
    }
    if (M == 0)
    {
        return NULL;
    }
    if (head == NULL)
    {
        return head;
    }
    Node *temp = head;
    while (temp != NULL)
    {
        int count1 = 0;
        while (count1 < M - 1 && temp != NULL)
        {
            temp = temp->next;
            count1++;
        }
        Node *a = temp;
        if (temp == NULL)
        {
            return head;
        }
        temp = temp->next;
        int count2 = 0;
        while (count2 < N && temp != NULL)
        {
            Node *d = temp;
            temp = temp->next;
            count2++;
            delete d;
        }
        a->next = temp;
    }
    return head;
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
        int m, n;
        cin >> m >> n;
        head = skipMdeleteN(head, m, n);
        print(head);
    }
    return 0;
}