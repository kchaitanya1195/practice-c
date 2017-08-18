#include "binary-tree.h"

void printTree(TreeNode *root, int tab) {
    if (!root) 
        return;

    printTree(root->right, tab + 1);
    for (int i = 0; i < tab; i++)
        cout<<"\t";
    cout<<root->data<<endl;
    printTree(root->left, tab + 1);
}

TreeNode::TreeNode(int d, TreeNode *par) {
    data = d;
    parent = par;
    left = right = NULL;
}

void BinaryTree::insert(int data, TreeNode **curr, TreeNode *par) {
    if (!(*curr)) {
        *curr = new TreeNode(data, par);
        return;
    }

    if (data > (*curr)->data)
        insert(data, &((*curr)->right), *curr);
    else
        insert(data, &((*curr)->left), *curr);
}
bool BinaryTree::has(int data, TreeNode *curr) {
    if (!curr) 
        return false;
    
    if(curr->data == data)
        return true;

    if (data > curr->data)
        return has(data, curr->right);
    else
        return has(data, curr->left);
}
int BinaryTree::height(TreeNode *curr) {
    if (!curr)
        return 0;

    return max(height(curr->left), height(curr->right)) + 1;
}