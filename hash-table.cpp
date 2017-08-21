#include "hash-table.h"

HashTable::HashTable(int size):hashSize(size) {
    hashArray = new HashEntry*[hashSize];
    for (int i=0;i<hashSize;i++) {
        hashArray[i] = new HashEntry[50];
    }
}

void HashTable::put(int key, int value) {
    int hash = hash(key);
    cout<<hashArray[hash][0].key<<endl;
}