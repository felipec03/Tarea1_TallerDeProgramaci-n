#include "PriorityQueue.h"

PriorityQueue::PriorityQueue(int n) {
    capacity = n;
    number = 0;
    arr = new State*[n];
}

PriorityQueue::PriorityQueue(int n, int numJugs) {
    capacity = n;
    this->numJugs = numJugs;
    number = 0;
    arr = new State*[n];
}

PriorityQueue::PriorityQueue() {
    capacity = 100;
    number = 0;
    arr = new State*[capacity];
}

PriorityQueue::~PriorityQueue() {
    delete[] arr;
}

void PriorityQueue::push(State *x) {
    if (number == capacity) {
        capacity *= 2;
        State **arr2 = new State*[capacity];
        for (int i = 0; i < number; i++) {
            arr2[i] = arr[i];
        }
        delete[] arr;
        arr = arr2;
    }
    arr[number] = x;
    bubbleUp(number);
    number++;
}

State* PriorityQueue::pop() {
    if (number == 0) {
        return nullptr;
    }
    State *x = arr[0];
    number--;
    arr[0] = arr[number];
    bubbleDown(0);
    return x;
}

bool PriorityQueue::isEmpty() {
    return number == 0;
}

void PriorityQueue::bubbleUp(int i) {
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (arr[i]->priority < arr[parent]->priority) {
            swap(i, parent);
            i = parent;
        } else {
            break;
        }
    }
}

void PriorityQueue::bubbleDown(int i) {
    while (2 * i + 1 < number) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int minChild = left;
        if (right < number && arr[right]->priority < arr[left]->priority) {
            minChild = right;
        }
        if (arr[i]->priority > arr[minChild]->priority) {
            swap(i, minChild);
            i = minChild;
        } else {
            break;
        }
    }
}

void PriorityQueue::swap(int i, int j) {
    State *temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
