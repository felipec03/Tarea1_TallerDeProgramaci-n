#include <iostream>
#include "State.h"

class Queue {
    public:
    int back; // los que entran el ultimo
    int front; // los que salen el primero
    int size;
    void push(State* s); // encolar en back
    State* pop(); // sacar de front
    bool is_empty();
    int number_of_elements(); // numero de elementos en la cola

    State** arr; // arreglo de estados que implementa la cola
    Queue(int size); // constructor con tamaño 
    bool contains(State* s); // verifica si un estado esta en la cola

};