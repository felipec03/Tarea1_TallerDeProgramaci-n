#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "State.h"
#include "AVLTree.h"

class HashTable {
public:
    int capacity;
    AVLTree* arr;  // Array of AVL Trees as buckets
    int number;

    HashTable(size_t n);
    HashTable();
    ~HashTable();

    void insert(const State& x);
    bool contains(const State& x);
    void remove(const State& x);
    void print();
    int hash(const State& x);
};

#endif  // HASHTABLE_H