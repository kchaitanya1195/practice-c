#include "linked-list.h"

void printList(Node *head){
    Node *curr = head;
    int i=0;
    while(curr != NULL){
        cout<<i<<" "<<curr->data<<endl;
        curr = curr->next;
        i++;
    }
    cout<<endl;
}
void printRevList(Node *tail){
    Node *curr = tail;
    int i=0;
    while(curr != NULL){
        cout<<i<<" "<<curr->data<<endl;
        curr = curr->prev;
        i++;
    }
    cout<<endl;
}

Node::Node(){
    data = 0;
    next = NULL;
    prev = NULL;
}
Node::Node(int d){
    data = d;
    next = NULL;
    prev = NULL;
}

void SinglyLinkedList::add(int data){
    //cout<<data<<endl;
    if(head == NULL){
        //cout<<"null head"<<endl;
        head = new Node(data);
        return;
    }
    getLastNode()->next = new Node(data);
}
void SinglyLinkedList::insert(int data){
    Node *temp = head;
    head = new Node(data);
    head->next = temp;
}
void SinglyLinkedList::append(Node *list){
    getLastNode()->next = list;
}
void SinglyLinkedList::remove(int data){
    if(head == NULL)
        return;
    
    if(head->data == data){
        head = head->next;
        return;
    }
    Node *curr = head->next, *prev = head;
    while(curr != NULL && curr->data != data){
        prev = curr;
        curr = curr->next;
    }
    
    if(curr != NULL && curr->data == data)
        prev->next = curr->next;
}
int SinglyLinkedList::getLast(){
    return getLastNode()->data;
}
Node *SinglyLinkedList::getLastNode(){
    if(head == NULL){
        //cout<<"null head"<<endl;
        return head;
    }
    Node* curr = head;
    while(curr->next != NULL){
        curr = curr->next;
    }

    return curr;
}

void DoublyLinkedList::add(int data){
    //cout<<data<<endl;
    if(head == NULL){
        //cout<<"null head"<<endl;
        head = new Node(data);
        tail = head;
        return;
    }
    Node *last = tail;
    last->next = new Node(data);
    tail = last->next;
    tail->prev = last;
}
void DoublyLinkedList::insert(int data){
    if(!head){
        add(data);
        return;
    }
    Node *temp = head;
    head = new Node(data);
    head->next = temp;
    temp->prev = head;
}
void DoublyLinkedList::append(Node *list){
    Node *last = tail;
    last->next = list;
    tail = last->next;
    tail->prev = last;
}
void DoublyLinkedList::remove(int data){
    if(head == NULL)
        return;
    
    if(head->data == data){
        head = head->next;
        return;
    }
    Node *curr = head->next, *prev = head;
    while(curr != NULL && curr->data != data){
        prev = curr;
        curr = curr->next;
    }
    
    if(curr != NULL && curr->data == data)
        prev->next = curr->next;
}