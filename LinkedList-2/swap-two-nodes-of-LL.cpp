// Problem statement
// You have been given a singly linked list of integers along with two integers, 'i,' and 'j.' Swap the nodes that are present at the 'i-th' and 'j-th' positions and return the new head to the list.

// Note :
// 1. Remember, You need to swap the nodes, not only the data.
// 2. Indexing starts from 0.
// 3. No need to print the list, it has already been taken care.
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

Node *swapNodes(Node *head, int i, int j)
{
    // Write your code here
    Node *current1 = NULL, *prev1 = NULL, *current2 = NULL, *prev2 = NULL, *temp = head;
    int count = 0;
    if (head == NULL || head->next == NULL || i == j)
    {
        return head;
    }
    // 0 and 1 case
    if ((i == 0 && j == 1) || (j == 0 && i == 1))
    {
        current1 = temp->next;
        head->next = current1->next;
        //		Node *a=current1->next;
        current1->next = head;
        //		head->next=a;
        head = current1;
        return head;
    }
    // i=0 case
    if (i == 0)
    {
        current1 = head;
        while (temp != NULL && count < j - 1)
        {
            temp = temp->next;
            count++;
        }
        if (temp == NULL)
        {
            return head;
        }
        current2 = temp->next;
        // prev2=temp;
        Node *k = head->next;
        prev2->next = current1;
        current1->next = current2->next;
        head = current2;
        current2->next = k;
        return head;
    }
    // j=0 case
    if (j == 0)
    {
        current1 = head;
        while (temp != NULL && count < i - 1)
        {
            temp = temp->next;
            count++;
        }
        if (temp == NULL)
        {
            return head;
        }
        current2 = temp->next;
        // prev2=temp;
        Node *k = head->next;
        prev2->next = current1;
        current1->next = current2->next;
        head = current2;
        current2->next = k;
        return head;
    }
    // i-j=1 case
    if ((i - j) == 1 || (j - i) == 1)
    {
        while (temp != NULL && count < i - 1)
        {
            temp = temp->next;
            count++;
        }
        if (temp == NULL)
        {
            return head;
        }
        //	prev1=temp;
        current1 = temp->next;
        prev1 = temp;
        temp = head;
        count = 0;
        while (temp != NULL && count < j - 1)
        {
            temp = temp->next;
            count++;
        }
        if (temp == NULL)
        {
            return head;
        }
        current2 = temp->next;
        prev2 = temp;
        //	swap
        if (i < j)
        {
            prev1->next = current2;
            current1->next = current2->next;
            current2->next = current1;
            return head;
        }
        else
        {
            prev2->next = current1;
            current2->next = current1->next;
            current1->next = current2;
            return head;
        }
    }
    // reamaining case
    while (temp != NULL && count < i - 1)
    {
        temp = temp->next;
        count++;
    }
    if (temp == NULL)
    {
        return head;
    }
    current1 = temp->next;
    prev1 = temp;
    temp = head;
    count = 0;
    while (temp != NULL && count < j - 1)
    {
        temp = temp->next;
        count++;
    }
    if (temp == NULL)
    {
        return head;
    }
    current2 = temp->next;
    prev2 = temp;
    Node *a = current2->next;
    prev1->next = current2;
    current2->next = current1->next;
    prev2->next = current1;
    current1->next = a;
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
        int i, j;
        Node *head = takeinput();
        cin >> i;
        cin >> j;
        head = swapNodes(head, i, j);
        print(head);
    }
    return 0;
}