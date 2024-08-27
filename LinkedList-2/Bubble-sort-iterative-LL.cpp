// Problem statement
// Given a singly linked list of integers, sort it using 'Bubble Sort.'
// bubble sort iterative
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

Node *bubbleSort(Node *head)
{
    // Write your code here
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *t1 = NULL, *t2 = NULL;
    for (t1 = head; t1->next != NULL; t1 = t1->next)
    {
        for (t2 = head; t2->next != NULL; t2 = t2->next)
        {
            if (t2->data > t2->next->data)
            {
                int t = t2->data;
                t2->data = t2->next->data;
                t2->next->data = t;
            }
        }
    }
    return head;
}

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
    Node *head = takeinput();
    head = bubbleSort(head);
    print(head);
}