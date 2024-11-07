#include "HashTable.h"
#include <iostream>

HashTable::HashTable(size_t n) : capacity(n), number(0) {
    arr = new AVLTree[capacity];
}

HashTable::HashTable() : HashTable(101) {}  // Default capacity set to a prime number

HashTable::~HashTable() {
    delete[] arr;
}

int HashTable::hash(const State& s) {
    return static_cast<int>(s.hash_value % capacity);
}

void HashTable::insert(const State& x) {
    if (static_cast<double>(number) / capacity > LOAD_FACTOR_THRESHOLD) {
        resize();
    }

    int h = hash(x);
    if (!arr[h].find(x)) {
        arr[h].insert(x);
        number++;
    }
    // Optionally implement resizing based on load factor
}

bool HashTable::contains(const State& x) {
    int h = hash(x);
    return arr[h].find(x);
}

void HashTable::remove(const State& x) {
    int h = hash(x);
    if (arr[h].find(x)) {
        arr[h].erase(x);
        number--;
    }
}

void HashTable::print() {
    for (size_t i = 0; i < capacity; ++i) {
        if (!arr[i].empty()) {
            std::cout << "Bucket " << i << ":\n";
            arr[i].display();
        }
    }
}

// Idea resizing
void HashTable::resize() {
    size_t newCapacity = capacity * 2 + 1;
    
    // Check for overflow and max size
    if (newCapacity < capacity || newCapacity > MAX_CAPACITY) {
        newCapacity = MAX_CAPACITY;
    }
    
    if (capacity >= MAX_CAPACITY) {
        return; // Already at max capacity
    }
    
    capacity = newCapacity;
    AVLTree* newArr = new AVLTree[capacity];
    
    // Copy elements
    for (size_t i = 0; i < capacity/2; i++) {
        for (AVLNode* node = arr[i].root; node != nullptr;) {
            AVLNode* next = node->right;
            int newIndex = node->value.hash_value % capacity;
            newArr[newIndex].insert(node->value);
            node = next;
        }
    }
    
    delete[] arr;
    arr = newArr;
}