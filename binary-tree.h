#include <iostream>
#include <stddef.h>
using namespace std;

class TreeNode {
    public:
        int data;
        TreeNode *left, *right, *parent;

        TreeNode(int d, TreeNode *par = NULL);
};

class BinaryTree {
    public:
        TreeNode *root;

        BinaryTree(): root(NULL) {}
        BinaryTree(int data): root(new TreeNode(data)) {}
        BinaryTree(TreeNode *r): root(r) {}

        void insert(int data) { insert(data, &root); }
        bool has(int data) { return has(data, root); }
        int height() { return height(root); }

    protected:
        void insert(int data, TreeNode **curr, TreeNode *par = NULL);
        bool has(int data, TreeNode *curr);
        int height(TreeNode *curr);
};

class BalancedBinaryTree: public BinaryTree {
    public:
        BalancedBinaryTree():BinaryTree() {}
        BalancedBinaryTree(int data):BinaryTree(data) {}
        BalancedBinaryTree(TreeNode *r):BinaryTree(r) {}
};

void printTree(TreeNode *root, int tab);