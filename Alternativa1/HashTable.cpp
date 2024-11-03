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

size_t HashTable::hash(State *s) {
    size_t hash = 0;
    for (int i = 0; i < s->numJugs; i++) {
        hash = (hash * 31 + static_cast<size_t>(s->arregloJugs[i])) % capacity;
    }
    return hash;
}

void HashTable::insert(State *x){
    int h = hash(x);
    while (arr[h]!=nullptr){
        if (arr[h]->equals(x)) {
            return; // Already exists
        }
        h = (h+1)%capacity;
    }
    arr[h] = x;
    number++;
}

State* HashTable::search(State *x){
    int h = hash(x);
    int original_h = h;
    while (arr[h]!=nullptr){
        if (arr[h]->equals(x)){
            return arr[h];
        }
        h = (h+1)%capacity;
        if (h == original_h) break;
    }
    return nullptr;
}

bool HashTable::contains(State *x){
    return search(x) != nullptr;
}

void HashTable::remove(State *x){
    int h = hash(x);
    int original_h = h;
    while (arr[h]!=nullptr){
        if (arr[h]->equals(x)){
            delete arr[h];
            arr[h]=nullptr;
            number--;
            return;
        }
        h = (h+1)%capacity;
        if (h == original_h) break;
    }
}

void HashTable::print(){
    for (int i=0; i<capacity; i++){
        if (arr[i]!=nullptr){
            arr[i]->print();
        }
    }
}