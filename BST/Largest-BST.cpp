// Problem statement
// Given a Binary tree, find the largest BST subtree. That is, you need to find the BST with maximum height in the given binary tree.
// You have to return the height of largest BST.
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
#include <climits>
class Pair
{
public:
    int min;
    int max;
    int height;
    bool isBSt;
};
Pair helper(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        Pair ans;
        ans.min = INT_MAX;
        ans.max = INT_MIN;
        ans.isBSt = true;
        ans.height = 0;
        return ans;
    }
    Pair leftAns = helper(root->left);
    Pair rightAns = helper(root->right);
    Pair finalAns;
    int minimum = min(root->data, min(leftAns.min, rightAns.min));
    int maximum = max(root->data, max(leftAns.max, rightAns.max));
    bool isBSTfinal = (root->data > leftAns.max) && (root->data < rightAns.min) && leftAns.isBSt && rightAns.isBSt;
    // if(root->data>leftAns.max&&root->data<rightAns.min&&leftAns.isBSt&&rightAns.isBSt){
    //     finalAns.isBSt=true;
    // }else{
    //     finalAns.isBSt=false;
    // }
    finalAns.min = minimum;
    finalAns.max = maximum;
    finalAns.isBSt = isBSTfinal;
    if (isBSTfinal)
    {
        finalAns.height = 1 + max(leftAns.height, rightAns.height);
    }
    else
    {
        finalAns.height = max(leftAns.height, rightAns.height);
    }
    return finalAns;
}
int largestBSTSubtree(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return helper(root).height;
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
    cout << largestBSTSubtree(root);
    delete root;
}