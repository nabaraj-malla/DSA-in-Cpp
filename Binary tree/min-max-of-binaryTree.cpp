// Problem statement
// For a given a Binary Tree of type integer, find and return the minimum and the maximum data values.

// Return the output as an object of Pair class, which is already created.
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
#include <limits.h>
pair<int, int> getMinAndMax(BinaryTreeNode<int> *root)
{
    // Write your code here
    if (root == NULL)
    {
        pair<int, int> ans;
        ans.first = INT_MAX;  // max
        ans.second = INT_MIN; // min
        return ans;
    }
    pair<int, int> ans;
    ans.first = root->data;
    ans.second = root->data;
    pair<int, int> leftAns = getMinAndMax(root->left);
    if (leftAns.first != INT_MIN)
    {
        ans.first = min(ans.first, leftAns.first);
        ans.second = max(ans.second, leftAns.second);
    }
    pair<int, int> rightAns = getMinAndMax(root->right);
    if (rightAns.first != INT_MIN)
    {
        ans.first = min(ans.first, rightAns.first);
        ans.second = max(ans.second, rightAns.second);
    }
    return ans;
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
    pair<int, int> ans = getMinAndMax(root);
    cout << ans.first << " " << ans.second;
}