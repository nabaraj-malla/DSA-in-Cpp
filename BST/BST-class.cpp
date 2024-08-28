// Problem statement
// Implement the BST class which includes following functions -

// 1. insert -
// Given an element, insert that element in the BST at the correct position. If element is equal to the data of the node, insert it in the left subtree.

// 2. search
// Given an element, find if that is present in BST or not. Return true or false.

// 3. delete -
// Given an element, remove that element from the BST. If the element which is to be deleted has both children, replace that with the minimum element from right sub-tree.

// 4. printTree (recursive) -
// Print the BST in in the following format -

// For printing a node with data N, you need to follow the exact format -

// N:L:x,R:y
// where, N is data of any node present in the binary tree. x and y are the values of left and right child of node N. Print the children only if it is not null.

// There is no space in between.

// You need to print all nodes in the recursive format in different lines.
#include <iostream>
using namespace std;

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

class BST
{
    // Define the data members
    BinaryTreeNode<int> *root;
    BinaryTreeNode<int> *insert(BinaryTreeNode<int> *node, int data)
    {
        if (node == NULL)
        {
            BinaryTreeNode<int> *newNode = new BinaryTreeNode<int>(data);
            return newNode;
        }
        if (data > node->data)
        {
            node->right = insert(node->right, data);
        }
        else
        {
            node->left = insert(node->left, data);
        }
        return node;
    }
    // print function()
    void print(BinaryTreeNode<int> *node)
    {
        if (node == NULL)
        {
            return;
        }
        cout << node->data << ":";
        if (node->left != NULL)
        {
            cout << "L" << ":" << node->left->data << ",";
        }
        if (node->right != NULL)
        {
            cout << "R" << ":" << node->right->data;
        }
        cout << endl;
        print(node->left);
        print(node->right);
    }
    // delete function()
    BinaryTreeNode<int> *remove(BinaryTreeNode<int> *node, int data)
    {
        if (node == NULL)
        {
            return NULL;
        }
        if (data > node->data)
        {
            node->right = remove(node->right, data);
            return node;
        }
        else if (data < node->data)
        {
            node->left = remove(node->left, data);
            return node;
        }
        else
        {
            if (node->left == NULL && node->right == NULL)
            {
                delete node;
                return NULL;
            }
            else if (node->left == NULL)
            {
                BinaryTreeNode<int> *temp = node->right;
                node->right = NULL;
                delete node;
                return temp;
            }
            else if (node->right == NULL)
            {
                BinaryTreeNode<int> *temp = node->left;
                node->left = NULL;
                delete node;
                return temp;
            }
            else
            {
                BinaryTreeNode<int> *minNode = node->right;
                while (minNode->left != NULL)
                {
                    minNode = minNode->left;
                }
                int rightMin = minNode->data;
                node->data = rightMin;
                node->right = remove(node->right, rightMin);
                return node;
            }
        }
    }
    bool search(BinaryTreeNode<int> *root, int data)
    {
        if (root == NULL)
        {
            return NULL;
        }
        if (root->data == data)
        {
            return true;
        }
        else if (root->data <= data)
        {
            return search(root->left, data);
        }
        else
        {
            return search(root->right, data);
        }
    }

public:
    BST()
    {
        // Implement the Constructor
        root = NULL;
    }

    /*----------------- Public Functions of BST -----------------*/

    void remove(int data)
    {
        // Implement the remove() function
        this->root = remove(root, data);
    }

    void print()
    {
        // Implement the print() function
        print(root);
    }

    void insert(int data)
    {
        // Implement the insert() function
        this->root = insert(root, data);
    }

    bool search(int data)
    {
        // Implement the search() function
        return search(root, data);
    }
};

int main()
{
    BST *tree = new BST();
    int choice, input, q;
    cin >> q;
    while (q--)
    {
        cin >> choice;
        switch (choice)
        {
        case 1:
            cin >> input;
            tree->insert(input);
            break;
        case 2:
            cin >> input;
            tree->remove(input);
            break;
        case 3:
            cin >> input;
            cout << ((tree->search(input)) ? "true\n" : "false\n");
            break;
        default:
            tree->print();
            break;
        }
    }
}