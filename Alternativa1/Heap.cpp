// Heap.cpp

#include "Heap.h"

Heap::Heap(int n) {
    capacity = n;
    number = 0;
    arr = new State*[n];
}

Heap::Heap(){
    capacity = 100;
    number = 0;
    arr = new State*[capacity];
}

Heap::~Heap() {
    delete[] arr;
}

void Heap::push(State *x){
    if (number == capacity) {
        capacity *= 2;
        State **arr2 = new State*[capacity];
        for (int i=0; i<number; i++){
            arr2[i]=arr[i];
        }
        delete[] arr;
        arr=arr2;
    }
    arr[number]=x;
    bubbleUp(number);
    number++;
}

State* Heap::pop() {
    if (number==0) {
        return nullptr;
    }
    State *x = arr[0];
    number--;
    arr[0] = arr[number];
    bubbleDown(0);
    return x;
}

bool Heap::isEmpty(){
    return number==0;
}

void Heap::swap(int i, int j){
    State *temp = arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

void Heap::bubbleUp(int i){
    while (i > 0) {
        int parent=(i-1)/2;
        if (arr[i]->priority < arr[parent]->priority) {
            swap(i,parent);
            i = parent;
        } else {
            break;
        }
    }
}

void Heap::bubbleDown(int i){
    while (true) {
        int left=2*i+1;
        int right=2*i+2;
        int min = i;
        if (left<number && arr[left]->priority < arr[min]->priority) {
            min = left;
        }
        if (right<number && arr[right]->priority < arr[min]->priority) {
            min = right;
        }
        if (min != i) {
            swap(i, min);
            i = min;
        } else {
            break;
        }
    }
}