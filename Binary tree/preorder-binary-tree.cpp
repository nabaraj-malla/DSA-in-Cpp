// Problem statement
// You are given a ‘Binary Tree’.
// Return the preorder traversal of the Binary Tree.
void preOrder(BinaryTreeNode<int> *root)
{
    if (!root)
        return;

    cout << root->data << " ";

    preOrder(root->left);

    preOrder(root->right);
}
