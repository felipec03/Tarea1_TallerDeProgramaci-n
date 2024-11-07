// HashTable.cpp
#include "HashTable.h"

HashTable::HashTable(size_t n) {
    capacity = n;
    number = 0;
    buckets = new AVL*[capacity]();
}

HashTable::HashTable() : HashTable(101) {}

HashTable::~HashTable() {
    for (int i = 0; i < capacity; i++) {
        if (buckets[i] != nullptr) {
            delete buckets[i];
        }
    }
    delete[] buckets;
}

int HashTable::hash(State* x) {
    return (int)(x->hash_value % capacity);
}

State* HashTable::findOrInsert(State* x) {
    if (number >= capacity * 0.75) {  // Load factor threshold
        resize();
    }

    int h = hash(x);
    if (buckets[h] == nullptr) {
        buckets[h] = new AVL();
    }

    State* existing = buckets[h]->find(x);
    if (existing != nullptr) {
        return existing;
    }

    buckets[h]->insert(x);
    number++;
    return x;
}

void HashTable::insert(State* x) {
    if (number >= capacity * 0.75) {
        resize();
    }

    int h = hash(x);
    if (buckets[h] == nullptr) {
        buckets[h] = new AVL();
    }

    if (!buckets[h]->contains(x)) {
        buckets[h]->insert(x);
        number++;
    }
}

bool HashTable::contains(State* x) {
    int h = hash(x);
    if (buckets[h] == nullptr) {
        return false;
    }
    return buckets[h]->contains(x);
}

void HashTable::resize() {
    int oldCapacity = capacity;
    capacity *= 2;
    AVL** newBuckets = new AVL*[capacity]();

    for (int i = 0; i < oldCapacity; i++) {
        if (buckets[i] != nullptr) {
            // Rehash all nodes in this AVL tree
            rehashAVL(buckets[i]->getRoot(), newBuckets, capacity);
            // Delete the old AVL tree (nodes are preserved)
            delete buckets[i];
        }
    }
    delete[] buckets;
    buckets = newBuckets;
}

void HashTable::rehashAVL(AVLNode* node, AVL** newBuckets, int newCapacity) {
    if (node == nullptr) return;

    rehashAVL(node->left, newBuckets, newCapacity);

    State* s = node->state;
    int h = (int)(s->hash_value % newCapacity);
    if (newBuckets[h] == nullptr) {
        newBuckets[h] = new AVL();
    }
    newBuckets[h]->insert(s);

    rehashAVL(node->right, newBuckets, newCapacity);
}

void HashTable::deleteAllStates() {
    for (int i = 0; i < capacity; i++) {
        if (buckets[i] != nullptr) {
            buckets[i]->deleteAllStates();
        }
    }
}

void HashTable::print() {
    for (int i = 0; i < capacity; i++) {
        if (buckets[i] != nullptr) {
            buckets[i]->print();
        }
    }
}