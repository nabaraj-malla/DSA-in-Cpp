// Problem statement
// Given a binary tree and an integer S, print all the pair of nodes whose sum equals S.

// Note:

// 1. Assume the given binary tree contains all unique elements.
// 2. In a pair, print the smaller element first. Order of different pairs doesn't matter.
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
void makeArray(BinaryTreeNode<int> *root, vector<int> &v)
{
    if (root == NULL)
    {
        return;
    }
    v.push_back(root->data);
    makeArray(root->left, v);
    makeArray(root->right, v);
}
void pairSum(BinaryTreeNode<int> *root, int sum)
{
    vector<int> v;
    makeArray(root, v);
    sort(v.begin(), v.end());
    int i = 0;
    int j = v.size() - 1;
    while (i < j)
    {
        if (v[i] + v[j] == sum)
        {
            cout << v[i] << " " << v[j] << endl;
            i++;
            j--;
        }
        else if (v[i] + v[j] > sum)
        {
            j--;
        }
        else
        {
            i++;
        }
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
    int sum;
    cin >> sum;
    pairSum(root, sum);
    delete root;
}