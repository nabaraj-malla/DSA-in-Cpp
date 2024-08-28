// Problem statement
// Given a binary tree, check if it is balanced. Return true if given binary tree is balanced, false otherwise.

// Balanced Binary Tree:
// A empty binary tree or binary tree with zero nodes is always balanced. For a non empty binary tree to be balanced, following conditions must be met:
// 1. The left and right subtrees must be balanced.
// 2. |hL - hR| <= 1, where hL is the height or depth of left subtree and hR is the height or depth of right subtree.
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
#include <math.h>
// int getHeight(BinaryTreeNode<int>* root) {
//     if (root == NULL) {
//         return 0;
//     }
//     int leftHeight = getHeight(root->left);
//     int rightheight = getHeight(root->right);
//     return 1 + max(leftHeight, rightheight);
// }

// bool isBalanced(BinaryTreeNode<int> *root) {
//     if (root == NULL) {
//         return true;
//     }

//     if(abs(getHeight(root->left) - getHeight(root->right)) > 1) {
//         return false;
//     }

//     bool leftAns = isBalanced(root->left);
//     bool rightAns = isBalanced(root->right);
//     if (leftAns && rightAns) {
//         return true;
//     } else {
//         return false;
//     }
// }

pair<int, bool> isBalancedHelper(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        pair<int, bool> ans;
        ans.first = 0;
        ans.second = true;
        return ans;
    }

    pair<int, bool> leftAns = isBalancedHelper(root->left);
    pair<int, bool> rightAns = isBalancedHelper(root->right);
    int lh = leftAns.first;
    bool lc = leftAns.second;
    int rh = rightAns.first;
    bool rc = rightAns.second;
    int height = 1 + max(lh, rh);
    bool check = false;
    if ((abs(lh - rh) <= 1) && (lc && rc))
    {
        check = true;
    }
    pair<int, bool> ans;
    ans.first = height;
    ans.second = check;
    return ans;
}
bool isBalanced(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return true;
    }

    return isBalancedHelper(root).second;
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
    cout << (isBalanced(root) ? "true" : "false");
}