// HashTable.cpp

#include "HashTable.h"

HashTable::HashTable(int n) {
    capacity = n;
    number = 0;
    arr = new State*[n];
    for (int i = 0; i < n; i++) {
        arr[i] = nullptr;
    }
}

HashTable::HashTable(){
    capacity = 100;
    number = 0;
    arr = new State*[capacity];
    for (int i=0; i<capacity; i++){
        arr[i] = nullptr;
    }
}

HashTable::~HashTable() {
    delete[] arr;
}

int HashTable::hash(State *s){
    int hash = 0;
    for(int i = 0 ; i < s->numJugs ; i++){
        hash = hash * 31 + s->arregloJugs[i];
    }
    return abs(hash) % capacity;
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