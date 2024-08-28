// Problem statement
// Given a binary search tree and an integer S, find pair of nodes in the BST which sum to S. You can use extra space of the order of O(log n).

// Note:
// 1. Assume BST contains all unique elements.
// 2. In a pair, print the smaller element first.
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
#include <stack>
int getSize(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + getSize(root->left) + getSize(root->right);
}
void printNodesSumToS(BinaryTreeNode<int> *root, int s)
{
    if (root == NULL)
    {
        return;
    }
    int size = getSize(root);
    BinaryTreeNode<int> *temp1 = root;
    BinaryTreeNode<int> *temp2 = root;
    stack<BinaryTreeNode<int> *> in;
    stack<BinaryTreeNode<int> *> revIn;
    while (temp1 != NULL)
    {
        in.push(temp1);
        temp1 = temp1->left;
    }
    while (temp2 != NULL)
    {
        revIn.push(temp2);
        temp2 = temp2->right;
    }
    int k = 0;
    while (k < size - 1)
    {
        if (in.top()->data + revIn.top()->data == s)
        {
            temp1 = in.top()->right;
            temp2 = revIn.top()->left;
            cout << in.top()->data << " " << revIn.top()->data << endl;
            in.pop();
            k++;
            revIn.pop();
            k++;
            while (temp1 != NULL)
            {
                in.push(temp1);
                temp1 = temp1->left;
            }
            while (temp2 != NULL)
            {
                revIn.push(temp2);
                temp2 = temp2->right;
            }
        }
        else if (in.top()->data + revIn.top()->data > s)
        {
            temp2 = revIn.top()->left;
            revIn.pop();
            k++;
            while (temp2 != NULL)
            {
                revIn.push(temp2);
                temp2 = temp2->right;
            }
        }
        else
        {
            temp1 = in.top()->right;
            in.pop();
            k++;
            while (temp1 != NULL)
            {
                in.push(temp1);
                temp1 = temp1->left;
            }
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

void printLevelATNewLine(BinaryTreeNode<int> *root)
{
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        BinaryTreeNode<int> *first = q.front();
        q.pop();
        if (first == NULL)
        {
            if (q.empty())
            {
                break;
            }
            cout << endl;
            q.push(NULL);
            continue;
        }
        cout << first->data << " ";
        if (first->left != NULL)
        {
            q.push(first->left);
        }
        if (first->right != NULL)
        {
            q.push(first->right);
        }
    }
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();
    int s;
    cin >> s;
    printNodesSumToS(root, s);
    delete root;
}