#include "stack.h"

Stack::Stack() {
    stackSize = -1;
    capacity = 10;
    stack = new int[capacity];
}
void Stack::push(int data) {
    stackSize++;
    if (stackSize >= capacity) {
        int *old = stack;
        capacity += 10;
        stack = new int[capacity];
        stack = old;
        delete old;
    }
    stack[stackSize] = data;
}
int Stack::pop() {
    stackSize--;
    return stack[stackSize+1];
}