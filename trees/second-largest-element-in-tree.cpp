// Problem statement
// Given a generic tree, find and return the node with second largest value in given tree.

// Note: Return NULL if no node with required value is present.
#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode<T> *> children;

    TreeNode(T data) { this->data = data; }

    ~TreeNode()
    {
        for (int i = 0; i < children.size(); i++)
        {
            delete children[i];
        }
    }
};

template <typename T>
class Pair
{
public:
    TreeNode<T> *max;
    TreeNode<T> *secondMax;
};
Pair<int> helper(TreeNode<int> *root)
{
    Pair<int> ans;
    ans.max = root;
    ans.secondMax = NULL;
    for (int i = 0; i < root->children.size(); i++)
    {
        Pair<int> temp = helper(root->children[i]);
        if (temp.max->data > ans.max->data)
        {
            TreeNode<int> *discard = ans.max;
            ans.max = temp.max;
            if (temp.secondMax != NULL)
            {
                if (temp.secondMax->data > discard->data)
                {
                    ans.secondMax = temp.secondMax;
                }
            }
            ans.secondMax = discard;
        }
        if (ans.max->data > temp.max->data)
        {
            if (ans.secondMax != NULL)
            {
                if (temp.max->data > ans.secondMax->data)
                {
                    ans.secondMax = temp.max;
                }
            }
            else
            {
                ans.secondMax = temp.max;
            }
        }
        if (ans.max->data == temp.max->data)
        {
            if (ans.secondMax != NULL && temp.secondMax != NULL)
            {
                if (temp.secondMax->data > ans.secondMax->data)
                {
                    ans.secondMax = temp.secondMax;
                }
            }
            if (ans.secondMax == NULL)
            {
                ans.secondMax = temp.secondMax;
            }
        }
    }
    return ans;
}
TreeNode<int> *getSecondLargestNode(TreeNode<int> *root)
{
    // Write your code here
    return helper(root).secondMax;
}

TreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);

    queue<TreeNode<int> *> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++)
        {
            int childData;
            cin >> childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}

int main()
{
    TreeNode<int> *root = takeInputLevelWise();

    TreeNode<int> *ans = getSecondLargestNode(root);

    if (ans != NULL)
    {
        cout << ans->data;
    }
    else
    {
        cout << INT_MIN;
    }
}