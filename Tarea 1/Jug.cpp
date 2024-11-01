#include "Jug.h"

Jug::Jug(State* initialState, int sizeOpen, int sizeAll) {
    // Inicialización de estructuras de datos

    numberOfOperations = 3;
    operationArray = new Operation*[numberOfOperations];
    operationArray[0] = new Fill();
    operationArray[1] = new Empty();
    operationArray[2] = new Pour();

    open = new Heap(sizeOpen);
    all = new HashTable(sizeAll);
    
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
        operationArray[operationIndex]->operacion = "Fill: " + to_string(i);
        operationIndex++;
    }

    // Generamos operaciones Empty para cada jarra
    for (int i = 0; i < numJugs; i++) {
        operationArray[operationIndex] = new Empty();
        operationArray[operationIndex]->operacion = "Empty: " + to_string(i);    
        operationIndex++;
    }

    // Generamos operaciones Pour entre cada par de jarras
    for (int i = 0; i < numJugs; i++) {
        for (int j = 0; j < numJugs; j++) {
            if (i != j) {
                operationArray[operationIndex] = new Pour();
                operationArray[operationIndex]->operacion = "Pour: " + to_string(i) + " -> " + to_string(j);
                operationIndex++;
            }
        }
    }
}

// El metodo solve tiene por finalidad seguir el algoritmo A* para encontrar la solución al problema de las n jarras.
// El algoritmo A* se basa en la idea de que se tiene un Heap de estados abiertos (open) y una tabla Hash de estados cerrados (all).
// Se toma el estado con menor costo de open, se expande y se insertan los estados hijos en open.
// Se repite el proceso hasta que se encuentra el estado solución.
// En caso de que no se encuentre el estado solución, se retorna nullptr.
/*
State* Jug::solve(){
    while (!open->isEmpty()) {
        State* currentState = open->pop();

        if (currentState->isSolution()) {
            return currentState;
        }

        for (int i = 0; i < currentState->numJugs * 2 + currentState->numJugs * (currentState->numJugs - 1); i++) {
            State* newState = operationArray[i]->operation(currentState);

            if (newState != nullptr && !all->contains(newState)) {
                if (!all->contains(newState)) {
                    open->push(newState);
                    all->insert(newState);
                }
            }
        }
    }
   return nullptr;
}
*/

State* Jug::solve() {
    while (!open->isEmpty()) {
        State* currentState = open->pop();

        if (currentState->isFinal()) {
            // Print the solution path
            std::cout << "Solution found:\n";
            printSolution(currentState);
            return currentState;
        }


        for (int i = 0; i < numberOfOperations; i++) {
            Operation* op = operationArray[i];

            // For operations that take one argument (Fill, Empty)
            if (op->isUnary()) {
                for (int j = 0; j < currentState->numJugs; j++) {
                    State* newState = op->operation(currentState, j);
                    if (newState != nullptr) {
                        newState->parent = currentState;
                        newState->priority = currentState->priority + 1;
                        newState->op = op->operacion + " jug " + std::to_string(j);
                        if (!all->contains(newState)) {
                            open->push(newState);
                            all->insert(newState);
                        } 
                    }
                }
            }
            // For operations that take two arguments (Pour)
            else {
                for (int j = 0; j < currentState->numJugs; j++) {
                    for (int k = 0; k < currentState->numJugs; k++) {
                        if (j == k) continue;
                        State* newState = op->operation(currentState, j, k);
                        if (newState != nullptr) {
                            newState->parent = currentState;
                            newState->priority = currentState->priority + 1;
                            newState->op = op->operacion + " from jug " + std::to_string(j) + " to jug " + std::to_string(k);
                            if (!all->contains(newState)) {
                                open->push(newState);
                                all->insert(newState);
                            } 
                        }
                    }
                }
            }
        }
    }
    std::cout << "No solution found.\n";
    return nullptr;
}

void Jug::printSolution(State* state) {
    if (state == nullptr) {
        return;
    }
    if (state->parent != nullptr) {
        printSolution(state->parent);
    }
    if (!state->op.empty()) {
        std::cout << state->op << ": ";
    }
    state->print();
}

Jug::~Jug() {
    for(int i=0; i<numberOfOperations; i++){
        delete operationArray[i];
    }
    delete[] operationArray;
    delete open;
    delete all;
}