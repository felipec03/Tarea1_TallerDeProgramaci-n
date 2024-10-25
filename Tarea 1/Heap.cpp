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

int Heap::remove() {
	if (count == 0) {
		return -1;
	}
	int value = heap[0];
	heap[0] = heap[count - 1];
	count--;
	heapifyDown();
	return value;
}

bool Heap::isEmpty() {
	return count == 0;
}

void Heap::print() {
	for (int i = 0; i < count; i++) {
		cout << heap[i] << " ";
	}
	cout << endl;
}


