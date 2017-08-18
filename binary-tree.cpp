#include "binary-tree.h"

TreeNode::TreeNode(int d, TreeNode *par) {
    data = d;
    parent = par;
    left = right = NULL;
}
bool TreeNode::isRightChild() {
    return parent->right == this;
}

void BinaryTree::insert(int data, TreeNode **curr, TreeNode *par) {
    if (!(*curr)) {
        *curr = new TreeNode(data, par);
        backTrack(*curr);
        return;
    }

    if (data > (*curr)->data)
        insert(data, &((*curr)->right), *curr);
    else
        insert(data, &((*curr)->left), *curr);

    backTrack(*curr);
}
TreeNode *BinaryTree::findNode(int data, TreeNode *curr) {
    if (!curr)
        return NULL;
    
    if (curr->data == data)
        return curr;
    
    TreeNode *found = findNode(data, curr->right);
    if (!found)
        return findNode(data, curr->left);
    else
        return found;
}
void BinaryTree::deleteNode(TreeNode *node) {
    if (isLeaf(node)) {
        replace(node, NULL);
    } else if (!node->right) {
        replace(node, node->left);
    } else if (!node->left) {
        replace(node, node->right);
    } else {
        TreeNode *min = minNode(node->right);
        node->data = min->data;
        deleteNode(min);
    }
}
void BinaryTree::replace(TreeNode *node, TreeNode *newNode) {
    if (node == root) {
        root = newNode;
        return;
    }
    if (node->isRightChild()) 
        node->parent->right = newNode;
    else
        node->parent->left = newNode;
    if (newNode)
        newNode->parent = node->parent;
}
void BinaryTree::deleteData(int data) {
    TreeNode *node = findNode(data);
    if(node)
        deleteNode(node);
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
void BinaryTree::inorder(TreeNode *curr) {
    if (curr->left)
        inorder(curr->left);
    cout<<curr->data<<" ";
    if (curr->right)
        inorder(curr->right);
    
    if(curr == root)
        cout<<endl;
}
void BinaryTree::preorder(TreeNode *curr) {
    cout<<curr->data<<" ";
    if (curr->left)
        preorder(curr->left);
    if (curr->right)
        preorder(curr->right);
    
    if(curr == root)
        cout<<endl;
}
void BinaryTree::postorder(TreeNode *curr) {
    if (curr->left)
        postorder(curr->left);
    if (curr->right)
        postorder(curr->right);
    cout<<curr->data<<" ";
    
    if(curr == root)
        cout<<endl;
}
TreeNode *BinaryTree::maxNode(TreeNode *curr) {
    if (!curr)
        return NULL;
    if (curr->right)
        return maxNode(curr->right);
    else
        return curr;
}
TreeNode *BinaryTree::minNode(TreeNode *curr) {
    if (!curr)
        return NULL;
    if (curr->left)
        return minNode(curr->left);
    else
        return curr;
}

void BinaryTree::printTree(TreeNode *curr, int tab) {
    if (!curr) 
        return;

    printTree(curr->right, tab + 1);
    for (int i = 0; i < tab; i++)
        cout<<"\t";
    cout<<curr->data<<endl;
    printTree(curr->left, tab + 1);
}
void BinaryTree::printVertTree(TreeNode *curr, string prefix, bool isTail) {
    if (curr)
        cout<<prefix<<(isTail?"└──":"├──")<<curr->data<<endl;
    else {
        cout<<prefix<<(isTail?"└──":"├──")<<"*"<<endl;
        return;
    }
    if (isLeaf(curr))
        return;
    printVertTree(curr->right, prefix + (isTail?"   ":"│  "), false);
    printVertTree(curr->left, prefix + (isTail?"   ":"│  "), true);
}

void BalancedBinaryTree::backTrack(TreeNode *node) {
    int rightHeight = height(node->right), leftHeight = height(node->left);
    //cout<<node->data<<endl<<leftHeight<<" "<<rightHeight<<endl;
    if (abs(rightHeight - leftHeight) >= 2) {
        if (rightHeight > leftHeight)
            rotateLeft(node);
        else
            rotateRight(node);
    }
}
void BalancedBinaryTree::rotateRight(TreeNode *node) {
    TreeNode *left = node->left, *temp = node->left->right;
    replace(node, node->left);
    left->right = node;
    node->left = temp;

    left->parent = node->parent;
    node->parent = left;
    if(temp)
        temp->parent = node;
}
void BalancedBinaryTree::rotateLeft(TreeNode *node) {
    TreeNode *right = node->right, *temp = node->right->left;
    replace(node, node->right);
    right->left = node;
    node->right = temp;

    right->parent = node->parent;
    node->parent = right;
    if(temp)
        temp->parent = node;
}