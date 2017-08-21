#include "hash-table.h"

HashTable::HashTable(int size):hashSize(size) {
    hashArray = new HashEntry**[hashSize];
    for (int i=0;i<hashSize;i++) {
        hashArray[i] = new HashEntry*[50];
    }
}

void HashTable::put(int key, int value) {
    int hashVal = hash(key), pos = -1;

    HashEntry *curr = hashArray[hashVal][++pos];
    while (curr != NULL && curr->key != key) {
        curr = hashArray[hashVal][++pos];
    }

    hashArray[hashVal][pos] = new HashEntry(key, value);
}
int HashTable::get(int key, int def) {
    int hashVal = hash(key), pos = -1;

    HashEntry *curr = hashArray[hashVal][++pos];
    while (curr != NULL && curr->key != key) {
        curr = hashArray[hashVal][++pos];
    }

    return (curr)?curr->value:def;
}

void HashTable::test() {
    for (int i=1;i<3;i++){
        cout<<hashArray[5*i][0]->key<<" "<<hashArray[5*i][0]->value<<endl;
        cout<<hashArray[5*i][1]->key<<" "<<hashArray[5*i][1]->value<<endl;
    }
}