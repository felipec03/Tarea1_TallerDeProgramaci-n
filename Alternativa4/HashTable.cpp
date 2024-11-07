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
    for (int i = 0; i < capacity; ++i) {
        if (!arr[i].empty()) {
            std::cout << "Bucket " << i << ":\n";
            arr[i].display();
        }
    }
}