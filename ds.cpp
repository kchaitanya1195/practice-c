#include <iostream>
#include "binary-tree.h"
#include "stack.h"
#include "queue.h"
#include "heap.h"
#include "hash-table.h"
using namespace std;

void testHashTable() {
    const int n = 6;
    int a[n] = {5,10,55,60},
        b[n] = {4, 15, 7, 20};
    HashTable hs = HashTable(50);
    for (int i=0;i<n;i++) {
        hs.put(a[i], b[i]);
    }

    hs.test();

    cout<<hs.get(55)<<" "<<hs.get(5)<<endl;
    cout<<hs.get(9)<<endl;
}
void testHeap() {
    const int n = 6;
    int a[n] = {1,2,3,4,5,6};
    Heap minH = Heap(Comparators::isLessThan), maxH = Heap(Comparators::isGreaterThan);
    for(int i = 0; i < n; i++) {
        minH.insertVal(a[i]);
        maxH.insertVal(a[i]);
    }

    minH.printHeap();
    maxH.printHeap();
}
void testQueue() {
    const int n = 6;
    int a[n] = {1,2,3,4,5,6};
    Queue q = Queue(5);
    for (int i = 0; i < n; i++) {
        q.enqueue(a[i]);
        //q.printQueue();
    }

    q.printQueue();
    cout<<q.front()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    q.printQueue();
    q.enqueue(4);
    q.printQueue();
}
void testStack() {
    const int n = 6;
    int a[n] = {1,2,3,4,5,6};
    Stack s = Stack();
    for (int i = 0; i < n; i++) {
        s.push(a[i]);
    }
    cout<<s.pop()<<endl;
    cout<<s.peek()<<endl;
    cout<<s.pop()<<endl;
    
    for (int i = 0; i < 2 * n; i++) {
        s.push(a[i%n]);
    }
    cout<<s.size()<<endl;
    cout<<s.peek()<<endl;
}
void testBinaryTree() {
    const int n = 6;
    int a[n] = {1,2,3,4,5,6};
    BinaryTree bt = BinaryTree();
    BalancedBinaryTree bbt = BalancedBinaryTree();
    for (int i = 0; i < n; i++) {
        bt.insert(a[i]);
        bbt.insert(a[i]);
    }
    //bt.printTree();
    //bt.printVertTree();
    /*cout<<bt.has(8)<<endl;
    cout<<bt.has(10)<<endl;
    cout<<bt.height()<<endl;
    bt.preorder();
    bt.postorder();*/
    //bt.inorder();
    //cout<<bt.maxNode()->data<<endl;
    //cout<<bt.minNode()->data<<endl;
    //bbt.insert(10);
    //bt.deleteData(23);
    //bt.printVertTree();
    bbt.printVertTree();
}

int main() {
    testHashTable();
    return 0;
}