#ifndef MINHEAP_H
#define MINHEAP_H

#include "State.h"

class MinHeap {
private:
    State** heapArray;
    int capacity;
    int size;

    void heapifyUp(int index);
    void heapifyDown(int index);
    void resize();

public:
    MinHeap(int capacity);
    ~MinHeap();

    void insert(State* state);
    State* extractMin();
    bool isEmpty() const;
};

#endif