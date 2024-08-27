// Problem statement
//  Given a singly linked list of integers, sort it using 'Merge Sort.'
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

Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2)
{
    Node *finalHead = NULL, *finalTail = NULL;
    if (head1 == NULL)
    {
        return head2;
    }
    else if (head2 == NULL)
    {
        return head1;
    }
    else
    {
        while (head1 != NULL && head2 != NULL)
        {
            if (head1->data < head2->data)
            {
                if (finalHead == NULL)
                {
                    finalHead = head1;
                    finalTail = head1;
                    head1 = head1->next;
                }
                else
                {
                    finalTail->next = head1;
                    finalTail = head1;
                    head1 = head1->next;
                }
            }
            else
            {
                if (finalHead == NULL)
                {
                    finalHead = head2;
                    finalTail = head2;
                    head2 = head2->next;
                }
                else
                {
                    finalTail->next = head2;
                    finalTail = head2;
                    head2 = head2->next;
                }
            }
        }
        if (head1 != NULL)
        {
            finalTail->next = head1;
        }
        else
        {
            finalTail->next = head2;
        }
    }
    return finalHead;
}
Node *midPoint(Node *head)
{
    if (head == NULL)
    {                // if we don't write this statement it throws segmentation fault error when there is no data
        return head; // becase we are trying to access the NULL->next.
    }
    Node *slow = head, *fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
Node *mergeSort(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *mid = midPoint(head);
    Node *secondHead = mid->next;
    mid->next = NULL;
    Node *h1 = mergeSort(head);
    Node *h2 = mergeSort(secondHead);
    Node *finalHead = mergeTwoSortedLinkedLists(h1, h2);
    return finalHead;
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
        head = mergeSort(head);
        print(head);
    }

    return 0;
}