// HashTable.h
#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "State.h"
#include "AVL.h"

class HashTable {
public:
    int capacity;
    AVL** buckets;
    int number;

    void resize();
    int hash(State* x);
    void rehashAVL(AVLNode* node, AVL** newBuckets, int newCapacity);

    
    HashTable(size_t n);
    HashTable();
    ~HashTable();

    State* findOrInsert(State* x);
    void insert(State* x);
    bool contains(State* x);
    void deleteAllStates();

    void print();
};

#endif