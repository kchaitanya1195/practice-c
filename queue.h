#include <iostream>
#include <stddef.h>
using std::cout;
using std::endl;

class Queue {
    public:
        int size;
        int capacity;

        Queue();
        Queue(int cap);

        void enqueue(int data);
        int dequeue();
        int front() { return queue[head]; }
        bool isEmpty() { return size == 0; }
        bool isFull() { return size == capacity; }
        
        void printQueue();

    private:
        int head, tail;
        int *queue;
};