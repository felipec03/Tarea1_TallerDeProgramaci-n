#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "State.h"
#include <functional>

struct HashNode {
    State* state;
    HashNode* next;
};

class HashTable {
public:
    HashNode** table;
    int capacity;
    int size;
    float loadFactorThreshold;

    int hashFunction(unsigned long long key) const;
    void resize();
    HashTable(int capacity);
    ~HashTable();

    bool insert(State* state);
    bool contains(State* state) const;
};

#endif