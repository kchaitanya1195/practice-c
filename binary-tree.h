#include <iostream>
#include <stddef.h>
using namespace std;

class TreeNode {
    public:
        int data;
        TreeNode *left, *right, *parent;

        TreeNode(int d, TreeNode *par = NULL);

        bool isRightChild();
};

class BinaryTree {
    public:
        TreeNode *root;

        BinaryTree(): root(NULL) {}
        BinaryTree(int data): root(new TreeNode(data)) {}
        BinaryTree(TreeNode *r): root(r) {}

        void insert(int data) { insert(data, &root); }
        TreeNode *findNode(int data) { return findNode(data, root); }
        void deleteNode(TreeNode *node) ;
        void deleteData(int data);
        void replace(TreeNode *node, TreeNode *newNode);
        bool has(int data) { return has(data, root); }
        int height() { return height(root); }
        void inorder() { inorder(root); }
        void preorder() { preorder(root); }
        void postorder() { postorder(root); }
        TreeNode *maxNode() { return maxNode(root); }
        TreeNode *minNode() { return minNode(root); }
        
        void printTree() { printTree(root); };
        void printVertTree() { printVertTree(root); };

    private:
        virtual void insertBackTrack(TreeNode *node) {}

    protected:
        void insert(int data, TreeNode **curr, TreeNode *par = NULL);
        TreeNode *findNode(int data, TreeNode *curr);
        bool has(int data, TreeNode *curr);
        int height(TreeNode *curr);
        void inorder(TreeNode *curr);
        void preorder(TreeNode *curr);
        void postorder(TreeNode *curr);
        TreeNode *maxNode(TreeNode *curr);
        TreeNode *minNode(TreeNode *curr);
        bool isLeaf(TreeNode *node) { return (node) && (!node->right) && (!node->left); }

        void printTree(TreeNode *curr, int tab = 0);
        void printVertTree(TreeNode *curr, string prefix = "", bool isTail = true);
};

class BalancedBinaryTree: public BinaryTree {
    public:
        BalancedBinaryTree():BinaryTree() {}
        BalancedBinaryTree(int data):BinaryTree(data) {}
        BalancedBinaryTree(TreeNode *r):BinaryTree(r) {}

    private:
        void insertBackTrack(TreeNode *node);
};