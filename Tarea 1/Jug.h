#include <iostream>
#include "Queue.h"
#include "Heap.h"
#include "HashTable.h"
#include "Operation.h"
using namespace std;

class Jug {
    public:
    Queue* open;
    Queue* all;
    Operation* operationArray;

    // Métodos
    Jug(int sizeOpen, int sizeAll); 		// Construye con tamaños de open y all
    State* solve();							// Retorna el estado solución.
};
