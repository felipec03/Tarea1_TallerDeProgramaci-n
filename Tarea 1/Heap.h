#include <iostream>
#include "State.h"
using namespace std;

class Heap{
	public:
		State** heap;
		int capacity;
		int number;

		// Constructor para inicializar el heap con un tamaño de 100
		Heap();
		// Constructor para inicializar el heap con un tamaño específico
		Heap(int size);
		// Destructor
		~Heap();
		// Función para insertar un estado en el heap con complejidad O(log n)
		void insert(State* s);
		// Función para remover el estado con menor f en el heap con complejidad O(log n)
		State* remove();
		// Función para verificar si el heap está vacío
		bool isEmpty();
		// Función para imprimir el heap
		void print();
}
