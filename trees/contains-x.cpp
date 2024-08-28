// Problem statement
// Given a generic tree and an integer x, check if x is present in the given tree or not.
// Return true if x is present, return false otherwise.

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

bool isPresent(TreeNode<int> *root, int x)
{
    // Write your code here
    // bool ans=false;
    // if(root->data==x){
    // ans=true;
    // }
    // for(int i=0;i<root->children.size();i++){
    // 	bool tempAns=isPresent(root->children[i],x);
    // 	if(tempAns==true){
    // 		ans=tempAns;
    // 	}
    // }
    // return ans;
    if (root->data == x)
    {
        return true;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        bool temp = isPresent(root->children[i], x);
        if (temp == true)
        {
            return true;
        }
    }
    return false;
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
    int x;
    cin >> x;
    cout << (isPresent(root, x) ? "true" : "false");
}