#include <iostream>
#include <stddef.h>
using std::cout;

class Stack {
    public:

        Stack();

        void push(int data);
        int pop();
        int size() { return stackSize + 1; }

    private:
        int stackSize;
        int capacity;
        int *stack;
};