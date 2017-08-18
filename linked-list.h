#include <iostream>
#include <stddef.h>
using namespace std;

class Node {
    public:
        int data;
        Node *next, *prev;

        Node();
        Node(int d);
};

class SinglyLinkedList {
    public:
        Node *head;

        SinglyLinkedList(){ head = NULL; }

        void add(int data);
        void insert(int data);
        void append(Node *list);
        void remove(int data);
        int getLast();
        Node *getLastNode();
        void clear(){ head = NULL; }
};

class DoublyLinkedList {
    public:
        Node *head, *tail;

        DoublyLinkedList() { head = NULL; tail = NULL; }

        void add(int data);
        void insert(int data);
        void append(Node *list);
        void remove(int data);
        void clear() { head = NULL; tail = NULL; }
};

void printList(Node* head);
void printRevList(Node* tail);