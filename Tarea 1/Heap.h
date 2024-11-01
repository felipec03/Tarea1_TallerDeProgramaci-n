#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <string>
#include "State.h"
using namespace std;

// cola de prioridad implementada como arbol binario
// en un arreglo.
// Hijo izquierdo de i: 2*i+1
// Hijo derecho de i: 2*i+2
// Padre de i: (i-1)/2
class Heap {
    public:
        State **arr;
        int capacity;
        int number;
        Heap(int n); // Crea Heap vacio de capacidad n
        Heap(); // Crea Heap vacio
        ~Heap(); // Destructor
        void push(State *x); // Inserta un elemento en el Heap
        State *pop(); // Elimina y retorna el elemento de mayor prioridad
        bool isEmpty(); // Retorna true si el Heap esta vacio
        void bubbleUp(int i); // Mueve el elemento en la posicion i hacia arriba con swap
        void bubbleDown(int i); // Mueve el elemento en la posicion i hacia abajo con swap
        void swap(int i, int j); // Intercambia los elementos en las posiciones i y j del arreglo
};

#endif