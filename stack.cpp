#include "stack.h"

Stack::Stack() {
    currPosition = -1;
    capacity = 10;
    stack = new int[capacity];
}
void Stack::push(int data) {
    currPosition++;
    if (currPosition >= capacity) {
        int *old = stack;
        capacity += 10;
        stack = new int[capacity];
        stack = old;
        delete old;
    }
    stack[currPosition] = data;
}
int Stack::pop() {
    currPosition--;
    return stack[currPosition+1];
}