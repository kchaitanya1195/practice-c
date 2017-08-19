#include <iostream>
using std::cout;
using std::endl;

class Heap{
    public:
        int heap[100005], heapSize;
        bool (*comp)(int, int);

        Heap(bool (*c)(int, int)):heapSize(0), comp(c) { heap[0] = -1; }

        bool comp2(int a, int b) { return comp(a, b) || (a==b); }
        void insertVal(int val);
        int findVal(int val);
        void deleteVal(int val);
        int top() { return heap[1]; }
        int removeTop();

        void printHeap();

};

class Comparators{
    public:
        static bool isGreaterThan(int a, int b) { return a > b; }
        static bool isLessThan(int a, int b){ return a < b; }
};