#include "Heap.h"

Heap Heap::Heap(int size) {
	this->size = size;
	this->heap = new int[size];
	this->count = 0;
}

Heap::~Heap() {
	delete[] heap;
}

void Heap::insert(int value) {
	if (count == size) {
		return;
	}
	heap[count] = value;
	count++;
	heapifyUp();
}
