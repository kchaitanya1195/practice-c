#include <iostream>
using std::cout;
using std::endl;

class HashEntry {
    public:
        int key,value;

        HashEntry(key, value):key(key), value(value) {}
};

class HashTable {
    public:
        HashTable(int size=10000);

        void put(int key, int value);
        int hash(int key) { return key%hashSize; }

    protected:
        HashEntry **hashArray;
        int hashSize;
};