// Problem statement
// Given a singly linked list of integers, reverse the nodes of the linked list 'k' at a time and return its modified list.
//  'k' is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of 'k,' then left-out nodes, in the end, should be reversed as well.
// Example :
// Given this linked list: 1 -> 2 -> 3 -> 4 -> 5
// For k = 2, you should return: 2 -> 1 -> 4 -> 3 -> 5
// For k = 3, you should return: 3 -> 2 -> 1 -> 5 -> 4
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
class Pair
{
public:
    Node *head;
    Node *tail;
};
Pair reverse(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        Pair ans;
        ans.head = head;
        ans.tail = head;
        return ans;
    }
    Pair smallans = reverse(head->next);
    smallans.tail->next = head;
    head->next = NULL;
    Pair ans;
    ans.head = smallans.head;
    ans.tail = head;
    return ans;
}
Node *kReverse(Node *head, int k)
{
    // Write your code here
    if (head == NULL || head->next == NULL || k == 0 || k == 1)
    {
        return head;
    }
    Node *head1 = head, *tail1 = head;
    int count = 1;
    while (count < k && tail1 != NULL)
    {
        tail1 = tail1->next;
        count++;
    }
    if (tail1 == NULL)
    {
        Pair p1 = reverse(head1);
        head1 = p1.head;
        tail1 = p1.tail;
        return head1;
    }
    Node *head2 = tail1->next;
    tail1->next = NULL;
    Pair ans = reverse(head1);
    head1 = ans.head;
    tail1 = ans.tail;
    if (head2 == NULL)
    {
        return head1;
    }
    Node *newHead = kReverse(head2, k);
    tail1->next = newHead;
    return head1;
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
        int k;
        cin >> k;
        head = kReverse(head, k);
        print(head);
    }

    return 0;
}