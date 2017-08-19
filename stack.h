#include <iostream>
#include <stddef.h>
using std::cout;

class Stack {
    public:

        Stack();

        void push(int data);
        int pop();
        int peek() { return stack[stackSize]; }
        int size() { return stackSize + 1; }
        bool empty() { return stackSize < 0; }

    private:
        int stackSize;
        int capacity;
        int *stack;
};