// Problem statement
// Given a binary tree and data of two nodes, find 'LCA' (Lowest Common Ancestor) of the given two nodes in the binary tree.

// LCA
// LCA of two nodes A and B is the lowest or deepest node which has both A and B as its descendants.
#include <iostream>
#include <queue>

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

int getLCA(BinaryTreeNode<int> *root, int a, int b)
{
    // Write your code here
    if (root == NULL)
    {
        return -1;
    }
    if (root->data == a || root->data == b)
    {
        return root->data;
    }
    int leftAns = getLCA(root->left, a, b);
    int rightAns = getLCA(root->right, a, b);
    if (leftAns != -1 && rightAns != -1)
    {
        return root->data;
    }
    else if (leftAns != -1 && rightAns == -1)
    {
        return leftAns;
    }
    else if (rightAns != -1 && leftAns == -1)
    {
        return rightAns;
    }
    else
    {
        return -1;
    }
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
    int a, b;
    cin >> a >> b;
    cout << getLCA(root, a, b);
    delete root;
}