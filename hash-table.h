#include <iostream>
using std::cout;
using std::endl;

class HashEntry {
    public:
        int key,value;

        HashEntry(int key, int value):key(key), value(value) {}
};

class HashTable {
    public:
        HashTable(int size=10000);

        void put(int key, int value);
        int get(int key, int def=0);
        int hash(int key) { return key%hashSize; }
        void test();

    protected:
        HashEntry ***hashArray;
        int hashSize;
};