// HashTable.cpp

#include "HashTable.h"

#include "HashTable.h"

HashTable::HashTable(int capacity)
    : capacity(capacity), size(0), loadFactorThreshold(0.75f) {
    table = new HashNode*[capacity];
    for (int i = 0; i < capacity; ++i) {
        table[i] = nullptr;
    }
}

HashTable::~HashTable() {
    for (int i = 0; i < capacity; ++i) {
        HashNode* node = table[i];
        while (node) {
            HashNode* temp = node;
            node = node->next;
            delete temp;
        }
    }
    delete[] table;
}

int HashTable::hashFunction(unsigned long long key) const {
    return key % capacity;
}

bool HashTable::insert(State* state) {
    int index = hashFunction(state->key);
    HashNode* node = new HashNode{state, table[index]};
    table[index] = node;
    size++;

    // Resize if load factor exceeds threshold
    if ((float)size / capacity > loadFactorThreshold) {
        resize();
    }
    return true;
}

bool HashTable::contains(State* state) const {
    int index = hashFunction(state->key);
    HashNode* node = table[index];
    while (node != nullptr) {
        if (node->state->equals(state)) {
            return true;
        }
        node = node->next;
    }
    return false;
}

void HashTable::resize() {
    int oldCapacity = capacity;
    capacity *= 2;
    HashNode** oldTable = table;
    table = new HashNode*[capacity];
    for (int i = 0; i < capacity; ++i) {
        table[i] = nullptr;
    }

    // Rehash all nodes
    for (int i = 0; i < oldCapacity; ++i) {
        HashNode* node = oldTable[i];
        while (node) {
            HashNode* nextNode = node->next;
            int index = hashFunction(node->state->key);
            node->next = table[index];
            table[index] = node;
            node = nextNode;
        }
    }
    delete[] oldTable;
}