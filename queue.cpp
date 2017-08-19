#include "queue.h"

Queue::Queue() {
    size = 0;
    head = tail = 0;
    capacity = 10000;
    queue = new int[capacity];
}
Queue::Queue(int cap) {
    size = 0;
    head = tail = 0;
    capacity = cap;
    queue = new int[capacity];
}

void Queue::enqueue(int data) {
    if (size >= capacity)
        return;
    
    queue[tail] = data;
    tail++;
    tail %= capacity;
    size++;
}
int Queue::dequeue() {
    if (size <= 0)
        return 0;
    
    int val = queue[head];

    head++;size--;
    head %= capacity;
    //printQueue();
    return val;
}
void Queue::printQueue() {
    cout<<head<<" "<<tail<<endl;
    for (int i = head, j = 0; j < size; j++, i++, i%=capacity) {
        cout<<queue[i]<<" ";
    }
    cout<<endl;
}