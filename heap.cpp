#include "heap.h"

void Heap::insertVal(int val) {
    heapSize++;
    heap[heapSize] = val;
    int temp;
    int curr = heapSize, par = heapSize/2;
    while(par > 0){
        if(comp(heap[curr], heap [par])){
            temp = heap[par];
            heap[par] = heap[curr];
            heap[curr] = temp;
        } else
            break;

        curr = par;
        par = curr/2;
    }
}
int Heap::findVal(int val) {
    for(int i=1; i<=heapSize; i++){
        if(heap[i] == val)
            return i;
    }
    return 0;
}
void Heap::deleteVal(int val) {
    //cout<<"------delete------"<<endl;
    int i = findVal(val);
    heap[i] = heap[heapSize];
    heapSize--;
    int curr = i;
    //cout<<curr<<" "<<heapSize<<endl;
    while(2*curr<=heapSize){
        int first = heap[2*curr];
        int second = ((2*curr+1)<=heapSize)?heap[2*curr+1]:(first+1);

        //cout<<first<<" "<<second<<endl;
        if(comp2(heap[curr], first) && comp2(heap[curr], second))
            break;

        int t;
        if(comp2(first, second)){
            t = heap[curr];
            heap[curr] = heap[2*curr];
            heap[2*curr] = t;

            curr = 2*curr;
        } else{
            t = heap[curr];
            heap[curr] = heap[2*curr+1];
            heap[2*curr+1] = t;

            curr = 2*curr+1;
        }
    }
    //cout<<"------delete------"<<endl;
}
int Heap::removeTop() {
    int t = top();
    deleteVal(t);
    return t;
}
void Heap::printHeap(){
    for(int i=1; i<=heapSize; i++)
        cout<<heap[i]<<" ";
    cout<<endl;
}