// Problem statement
// Given a generic tree, find and return the node with maximum data. You need to return the node which is having maximum data.

// Return null if tree is empty.
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

TreeNode<int> *maxDataNode(TreeNode<int> *root)
{
    // Write your code here
    // stack <TreeNode<int>*> maxNode;
    // queue <TreeNode<int>*> pendingNodes;
    // pendingNodes.push(root);
    // while(!pendingNodes.empty()){
    // TreeNode<int> *front=pendingNodes.front();
    // pendingNodes.pop();
    // if(maxNode.empty()){
    // maxNode.push(front);
    // 	}
    // 	for(int i=0;i<front->children.size();i++){
    // 		if(front->children[i]->data>maxNode.top()->data){
    // 			maxNode.pop();
    // 			maxNode.push(front->children[i]);
    // 		}
    // 		pendingNodes.push(front->children[i]);
    // 	}
    // }
    // return maxNode.top();
    if (root == NULL)
    {
        return root;
    }
    TreeNode<int> *max = root;
    for (int i = 0; i < root->children.size(); i++)
    {
        TreeNode<int> *maxChild = maxDataNode(root->children[i]);
        if (maxChild->data > max->data)
        {
            max = maxChild;
        }
    }
    return max;
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
    TreeNode<int> *ans = maxDataNode(root);

    if (root != NULL)
    {
        cout << ans->data;
    }
}