#include <iostream>
#include "binary-tree.h"
using namespace std;

int main(){
    const int n = 6;
    int a[n] = {1,2,3,4,5,6};
    BinaryTree *bt = new BinaryTree;
    BalancedBinaryTree *bbt = new BalancedBinaryTree;
    for (int i = 0; i < n; i++) {
        bt->insert(a[i]);
        bbt->insert(a[i]);
    }
    //bt->printTree();
    //bt->printVertTree();
    /*cout<<bt->has(8)<<endl;
    cout<<bt->has(10)<<endl;
    cout<<bt->height()<<endl;
    bt->preorder();
    bt->postorder();*/
    //bt->inorder();
    //cout<<bt->maxNode()->data<<endl;
    //cout<<bt->minNode()->data<<endl;
    //bbt->insert(10);
    //bt->deleteData(23);
    //bt->printVertTree();
    bbt->printVertTree();
    return 0;
}