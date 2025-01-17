// Interfaz de una tabla hash con encadenamiento para almacenamiento de States
#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "State.h"

class HashTable {
    public:
        int capacity;
        State **arr;
        int number;
        static const size_t MAX_LOAD_FACTOR = 1;
        static const size_t CLEANUP_THRESHOLD = 50000000; 
        static const size_t CLEANUP_TARGET = 1000000; 

        HashTable(size_t n);
        HashTable();
        ~HashTable();
        State* findOrInsert(State *x);
        void insert(State *x);
        bool contains(State *x);
        void remove(State *x);
        void print();
        int hash(State *x);
        void resize();
};

#endif