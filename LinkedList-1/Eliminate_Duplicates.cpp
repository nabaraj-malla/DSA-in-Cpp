// Problem statement
// You have been given a singly linked list of integers where the elements are sorted in ascending order.
// Write a function that removes the consecutive duplicate values such that the given list
// only contains unique elements and returns the head to the updated list.

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

Node *removeDuplicates(Node *head)
{
    if (head == NULL)
    {
        return head;
    }
    Node *temp1 = head, *temp2 = head->next;
    while (temp2 != NULL)
    {
        if (temp1->data == temp2->data)
        {
            temp1->next = temp2->next;
            temp2 = temp2->next;
        }
        else if (temp1->data != temp2->data)
        {
            temp1 = temp2;
            temp2 = temp2->next;
        }
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
        head = removeDuplicates(head);
        print(head);
    }
    return 0;
}