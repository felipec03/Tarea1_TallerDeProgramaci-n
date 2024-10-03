#include <iostream>
#include <string>
#include "State.h"

// Esta es una cola circular
// Se implementa con un arreglo de punteros a State
class Queue{
    public:
    State **array;  // arreglo de punteros a estado, importante trabajar con punteros
    int front;      // índice del primer elemento
    int back;       // índice del último elemento
    int size;       // tamaño del arreglo

    Queue();
    Queue(int n);
    int numberElements();    // Cantidad de elementos de la cola
    void push(State *s);        // Inserta un puntero a un estado a la cola
    State * pop();              // Retorna el primer elemento de la cola
    bool find(State *s);        // Retorna true si un elemento está dentro de la cola
    bool isEmpty();             // Retorna true si la cola está vacía
};
