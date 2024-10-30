#include <iostream>
#include "Heap.h"
#include "HashTable.h"
#include "Fill.h"
#include "Empty.h"
#include "Pour.h"

using namespace std;

class Jug {
    public:
    Heap* open;
    HashTable* all;
    Operation** operationArray;

    // Métodos
    Jug(int sizeOpen, int sizeAll); 		// Construye con tamaños de open y all
    State* solve();							// Retorna el estado solución.
};
