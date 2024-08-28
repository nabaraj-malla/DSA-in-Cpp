// Problem statement
// You are given a Binary Tree of type integer, a integer value of target node's data, and an integer value K.

// Print the data of all nodes that have a distance K from the target node. The order in which they would be printed will not matter.

// Example:
// For a given input tree(refer to the image below):
// 1. Target Node: 5
// 2. K = 2
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

    ~BinaryTreeNode()
    {
        if (left)
            delete left;
        if (right)
            delete right;
    }
};

using namespace std;
void printNodeAtDepthK(BinaryTreeNode<int> *root, int k)
{
    if (root == NULL || k < 0)
    {
        return;
    }
    if (k == 0)
    {
        cout << root->data << endl;
        return;
    }
    k = k - 1;
    printNodeAtDepthK(root->left, k);
    printNodeAtDepthK(root->right, k);
}
int print(BinaryTreeNode<int> *root, int node, int k)
{
    if (root == NULL)
    {
        return -1;
    }
    if (root->data == node)
    {
        printNodeAtDepthK(root, k);
        return 0;
    }
    int ld = print(root->left, node, k);
    if (ld != -1)
    {
        if (ld + 1 == k)
        {
            cout << root->data << endl;
        }
        else
        {
            printNodeAtDepthK(root->right, k - ld - 2);
        }
        return ld + 1;
    }
    int rd = print(root->right, node, k);
    if (rd != -1)
    {
        if (rd + 1 == k)
        {
            cout << root->data << endl;
        }
        else
        {
            printNodeAtDepthK(root->left, k - rd - 2);
        }
        return rd + 1;
    }
    return -1;
}
void nodesAtDistanceK(BinaryTreeNode<int> *root, int node, int k)
{
    int x = print(root, node, k);
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
            BinaryTreeNode<int> *rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();
    int targetNode, k;
    cin >> targetNode >> k;
    nodesAtDistanceK(root, targetNode, k);
    delete root;
}