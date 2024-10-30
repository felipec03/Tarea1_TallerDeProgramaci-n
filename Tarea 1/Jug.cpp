#include "Jug.h"

Jug::Jug(int sizeOpen, int sizeAll) {
    // Inicialización de estructuras de datos
    open = new Heap(sizeOpen);
    all = new HashTable(sizeAll);
    State* initialState = new State(0, 0, 0, nullptr, "");
    
    // Se inserta el estado inicial en el heap open y en la tabla all
    open->push(initialState);
    all->insert(initialState);

    // Calculamos el número total de operaciones posibles
    int numJugs = initialState->numJugs;
    int totalOperations = numJugs * 2 + numJugs * (numJugs - 1); // Fill + Empty + Pour

    // Creamos el arreglo de operaciones
    operationArray = new Operation*[totalOperations];
    int operationIndex = 0;

    // Generamos operaciones Fill para cada jarra
    for (int i = 0; i < numJugs; i++) {
        operationArray[operationIndex] = new Fill();
        operationIndex++;
    }

    // Generamos operaciones Empty para cada jarra
    for (int i = 0; i < numJugs; i++) {
        operationArray[operationIndex] = new Empty();
        operationIndex++;
    }

    // Generamos operaciones Pour entre cada par de jarras
    for (int i = 0; i < numJugs; i++) {
        for (int j = 0; j < numJugs; j++) {
            if (i != j) {
                operationArray[operationIndex] = new Pour();
                operationIndex++;
            }
        }
    }
}

State* Jug::solve(){
	
	return nullptr;
}
