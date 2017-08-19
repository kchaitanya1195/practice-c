#include <iostream>
#include <stddef.h>
using std::cout;

class Stack {
    public:

        Stack();

        void push(int data);
        int pop();
        int peek() { return stack[currPosition]; }
        int size() { return currPosition + 1; }
        bool empty() { return currPosition < 0; }

    private:
        int currPosition;
        int capacity;
        int *stack;
};