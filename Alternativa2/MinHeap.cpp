#include "MinHeap.h"

MinHeap::MinHeap(int capacity)
    : capacity(capacity), size(0) {
    heapArray = new State*[capacity];
}

MinHeap::~MinHeap() {
    delete[] heapArray;
}

void MinHeap::resize() {
    capacity *= 2;
    State** newHeapArray = new State*[capacity];
    for (int i = 0; i < size; ++i) {
        newHeapArray[i] = heapArray[i];
    }
    delete[] heapArray;
    heapArray = newHeapArray;
}

void MinHeap::insert(State* state) {
    if (!state) return;
    if (size == capacity) {
        resize();
    }
    heapArray[size] = state;
    heapifyUp(size);
    size++;
}

State* MinHeap::extractMin() {
    if (size == 0) {
        return nullptr;
    }
    State* minState = heapArray[0];
    size--;
    heapArray[0] = heapArray[size];
    heapifyDown(0);
    return minState;
}

void MinHeap::heapifyUp(int index) {
    State* temp = heapArray[index];
    while (index > 0 && heapArray[(index - 1) / 2]->priority > temp->priority) {
        heapArray[index] = heapArray[(index - 1) / 2];
        index = (index - 1) / 2;
    }
    heapArray[index] = temp;
}

void MinHeap::heapifyDown(int index) {
    State* temp = heapArray[index];
    int child;
    while ((child = 2 * index + 1) < size) {
        if (child + 1 < size && heapArray[child + 1]->priority < heapArray[child]->priority) {
            child++;
        }
        if (heapArray[child]->priority >= temp->priority) break;
        heapArray[index] = heapArray[child];
        index = child;
    }
    heapArray[index] = temp;
}

bool MinHeap::isEmpty() const {
    return size == 0;
}