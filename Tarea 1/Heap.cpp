#include "Heap.h"

Heap::Heap(int n){
    capacity=n;
    number=0;
    arr = new State*[n];
}

Heap::Heap(){
    capacity=0;
    number=0;
    arr = new State*[0];
}

Heap::~Heap(){
    delete[] arr;
}

void Heap::push(State *x){

    if (number == capacity) { // si esta lleno
        State **arr2 = new State*[capacity*2];
        for (int i=0; i<capacity; i++){
            arr2[i]=arr[i];
        }
        capacity=capacity*2;
        delete[] arr;
        arr=arr2;
    }
    arr[number]=x;
    number++;
    bubbleUp(number-1);
    return;
}

State* Heap::pop() {
    if (number==0) {
        return nullptr;
    } else if (number==1) {
        number=0;
        return arr[0];
    } else {
        State *x = arr[0];
        arr[0]=arr[number-1];
        number--;
        bubbleDown(0);
        return x;
    }
}

void Heap::swap(int i, int j){
    State *temp = arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
    return;
}

void Heap::bubbleUp(int i){
    if (i==0) {
        return;
    }
    int parent=(i-1)/2;
    if (arr[i]->priority < arr[parent]->priority) {
        swap(i,parent);
        bubbleUp(parent);
    }
    return;
}

void Heap::bubbleDown(int i){
    int left=2*i+1;
    int right=2*i+2;
    // veamos el min de los 3 nodos (i, left, right)
    int min=i;
    if (left<number && // si hay hijo izquierdo
        arr[left]->priority < arr[min]->priority) {
        min=left;
    }
    if (right<number && // si hay hijo derecho
         arr[right]->priority < arr[min]->priority) {
        min=right;
    }
    if (min!=i) {
        swap(i,min);
        bubbleDown(min);
    }
    return;
}

