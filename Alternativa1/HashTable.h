// Interfaz de una tabla hash con encadenamiento para almacenamiento de States
#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "State.h"

class HashTable {
    private:
        int capacity;
        State **arr;
        int number;
    public:
        HashTable(size_t n);
        HashTable();
        ~HashTable();
        void insert(State *x);
        State* search(State *x);
        bool contains(State *x);
        void remove(State *x);
        void print();
        size_t hash(State *x);
};

#endif