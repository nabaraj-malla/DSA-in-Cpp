// Problem statement
// Given a generic tree, find and return the node for which sum of its data and
// data of all its child nodes is maximum. In the sum, data of the node and data of its immediate child nodes has to be taken.
#include <iostream>
#include <queue>
#include <vector>
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
    TreeNode<T> *maxNode;
    T maxSum;
};
Pair<int> maxSumNodeHelper(TreeNode<int> *root)
{
    Pair<int> ans;
    ans.maxSum = root->data;
    ans.maxNode = root;
    for (int i = 0; i < root->children.size(); i++)
    {
        ans.maxSum += root->children[i]->data;
    }
    // ans.maxSum=sum;
    for (int i = 0; i < root->children.size(); i++)
    {
        Pair<int> childAns = maxSumNodeHelper(root->children[i]);
        if (childAns.maxSum > ans.maxSum)
        {
            ans = childAns;
        }
    }
    return ans;
}
TreeNode<int> *maxSumNode(TreeNode<int> *root)
{
    return maxSumNodeHelper(root).maxNode;
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

    TreeNode<int> *ans = maxSumNode(root);

    if (ans != NULL)
    {
        cout << ans->data;
    }
}