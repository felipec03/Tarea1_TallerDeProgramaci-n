// Heap.h

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <string>
#include "State.h"
using namespace std;

class Heap {
    public:
        State **arr;
        int capacity;
        int number;
        Heap(int n);
        Heap();
        ~Heap();
        void push(State *x);
        State *pop();
        bool isEmpty();
    private:
        void bubbleUp(int i);
        void bubbleDown(int i);
        void swap(int i, int j);
};

#endif