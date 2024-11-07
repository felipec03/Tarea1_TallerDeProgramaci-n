#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "State.h"
#include "AVLTree.h"

class HashTable {
public:
    //int capacity;
    AVLTree* arr;  // Array of AVL Trees as buckets
    int number;

    // Idea resizing
    static constexpr  double LOAD_FACTOR_THRESHOLD = 0.75;
    static constexpr size_t MAX_CAPACITY = 1000000007; // Use a large prime number
    size_t capacity; // Change from int to size_t

    HashTable(size_t n);
    HashTable();
    ~HashTable();

    void insert(const State& x);
    bool contains(const State& x);
    void remove(const State& x);
    void print();
    int hash(const State& x);

    // Idea resizing
    
    void resize();
};

#endif  // HASHTABLE_H