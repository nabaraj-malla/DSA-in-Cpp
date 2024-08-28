// Problem statement
// Given a BST, convert it into a sorted linked list. You have to return the head of LL.
#include <iostream>
#include <queue>

template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;
    Node(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;
class Pair
{
public:
    Node<int> *head;
    Node<int> *tail;
};
Pair helper(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        Pair ans;
        ans.head = NULL;
        ans.tail = NULL;
        return ans;
    }
    Pair leftAns = helper(root->left);
    Pair rightAns = helper(root->right);
    Node<int> *rootNode = new Node<int>(root->data);
    Pair output;
    if (leftAns.head != NULL)
    {
        output.head = leftAns.head;
        output.tail = leftAns.tail;
    }
    else
    {
        output.head = rootNode;
        output.tail = rootNode;
    }
    if (leftAns.tail != NULL)
    {
        output.tail->next = rootNode;
        output.tail = rootNode;
    }
    if (rightAns.head != NULL)
    {
        output.tail->next = rightAns.head;
        output.tail = rightAns.tail;
    }
    return output;
}
Node<int> *constructLinkedList(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    return helper(root).head;
}

BinaryTreeNode<int> *takeInput()
{
    int rootData;

    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1)
        {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1)
        {
            BinaryTreeNode<int> *rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();
    Node<int> *head = constructLinkedList(root);

    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}