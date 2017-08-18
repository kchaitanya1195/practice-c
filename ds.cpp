#include <iostream>
#include "binary-tree.h"
using namespace std;

int main(){
    const int n = 10;
    int a[n] = {23, 45, 19, 8, 35, 14, 9, 11, 28, 64};
    BinaryTree *bt = new BinaryTree;
    BalancedBinaryTree *bbt = new BalancedBinaryTree;
    for (int i = 0; i < n; i++) {
        bt->insert(a[i]);
    }
    printTree(bt->root, 0);
    cout<<bt->has(8)<<endl;
    cout<<bt->has(10)<<endl;
    cout<<bt->height()<<endl;
    return 0;
}