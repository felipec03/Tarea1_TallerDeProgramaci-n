// HashTable.cpp

#include "HashTable.h"
#include <functional>

HashTable::HashTable(size_t n) {
    capacity = n;
    number = 0;
    arr = new State*[capacity]();
}

HashTable::HashTable() : HashTable(101) {} // Default capacity set to a prime number

HashTable::~HashTable() {
    delete[] arr;
}

int HashTable::hash(State *s) {
    return (int)(s->hash_value % capacity);
}

State* HashTable::findOrInsert(State *x) {
    int h = hash(x);
    int original_h = h;
    while (arr[h] != nullptr) {
        if (arr[h]->equals(x)) {
            return arr[h];
        }
        h = (h + 1) % capacity;
        if (h == original_h) break;
    }

    if (number >= capacity / 2) {
        resize();
        h = hash(x);
    }

    arr[h] = x;
    number++;
    return x;
}

void HashTable::insert(State *x) {
    int h = hash(x);
    int original_h = h;
    while (arr[h] != nullptr) {
        h = (h + 1) % capacity;
        if (h == original_h) break;
    }

    if (number >= capacity / 2) {
        resize();
        h = hash(x);
    }

    arr[h] = x;
    number++;
}

bool HashTable::contains(State *x) {
    int h = hash(x);
    int original_h = h;
    while (arr[h] != nullptr) {
        if (arr[h]->equals(x)) {
            return true;
        }
        h = (h + 1) % capacity;
        if (h == original_h) break;
    }
    return false;
}

void HashTable::remove(State *x) {
    int h = hash(x);
    int original_h = h;
    while (arr[h] != nullptr) {
        if (arr[h]->equals(x)) {
            delete arr[h];
            arr[h] = nullptr;
            number--;
            return;
        }
        h = (h + 1) % capacity;
        if (h == original_h) break;
    }
}

void HashTable::print() {
    for (int i = 0; i < capacity; i++) {
        if (arr[i] != nullptr) {
            arr[i]->print();
        }
    }
}

void HashTable::resize() {
    int oldCapacity = capacity;
    capacity *= 2;
    State** newArr = new State*[capacity]();

    for (int i = 0; i < oldCapacity; ++i) {
        if (arr[i] != nullptr) {
            int h = hash(arr[i]);
            while (newArr[h] != nullptr) {
                h = (h + 1) % capacity;
            }
            newArr[h] = arr[i];
        }
    }
    delete[] arr;
    arr = newArr;
}