// Problem statement
// You have been given a head to a singly linked list of integers. Write a function check to whether the list given is a 'Palindrome' or not.
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
Node *reverse(Node *head)
{
    Node *current = head, *prev = NULL, *next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    Node *newHead = prev;
    return newHead;
}
bool isPalindrome(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return true;
    }
    Node *temp = head;
    int len = length(head);
    int mid = len / 2;
    int count = 0;
    while (count < mid - 1)
    {
        temp = temp->next;
        count++;
    }
    Node *newHead = temp->next;
    temp->next = NULL;
    Node *revHead = reverse(newHead);
    while (head != NULL && revHead != NULL)
    {
        if (head->data != revHead->data)
        {
            return false;
        }
        head = head->next;
        revHead = revHead->next;
    }
    return true;
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

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        Node *head = takeinput();
        bool ans = isPalindrome(head);

        if (ans)
            cout << "true";
        else
            cout << "false";

        cout << endl;
    }

    return 0;
}