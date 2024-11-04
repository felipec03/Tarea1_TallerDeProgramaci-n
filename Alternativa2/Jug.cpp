#include "Jug.h"
#define MAX_DEPTH 1000 // Adjust as necessary


Jug::Jug(State* initialState, unsigned long sizeOpen, unsigned long sizeAll) {
    this->initialState = initialState;
    
    // Initialize operations
    numberOfOperations = 3;
    operationArray = new Operation*[numberOfOperations];
    operationArray[0] = new Fill();
    operationArray[1] = new Empty();
    operationArray[2] = new Pour();

    // Initialize data structures
    openSet = new MinHeap(sizeOpen);
    closedSet = new HashTable(sizeAll);

    // Set initial state
    initialState->cost = 0;
    initialState->priority = initialState->heuristic();
    openSet->insert(initialState);
}

State* Jug::solve() {
    while (!openSet->isEmpty()) {
        State* current = openSet->extractMin();

        if (current->isSolution()) {
            return current;
        }

        if (closedSet->contains(current)) {
            continue;
        }

        closedSet->insert(current);

        // Generate successors
        for (int i = 0; i < numberOfOperations; ++i) {
            Operation* op = operationArray[i];
            if (op->isUnary()) {
                for (int j = 0; j < current->numJugs; ++j) {
                    State* newState = op->operation(current, j);
                    if (newState && !closedSet->contains(newState)) {
                        newState->cost = current->cost + 1;
                        newState->priority = newState->cost + newState->heuristic();
                        openSet->insert(newState);
                    }
                }
            } else {
                for (int j = 0; j < current->numJugs; ++j) {
                    for (int k = 0; k < current->numJugs; ++k) {
                        if (j == k) continue;
                        State* newState = op->operation(current, j, k);
                        if (newState && !closedSet->contains(newState)) {
                            newState->cost = current->cost + 1;
                            newState->priority = newState->cost + newState->heuristic();
                            openSet->insert(newState);
                        }
                    }
                }
            }
        }
    }
    return nullptr;
}

Jug::~Jug() {
    for (int i = 0; i < numberOfOperations; ++i) {
        delete operationArray[i];
    }
    delete[] operationArray;
    delete openSet;
    delete closedSet;
}

void Jug::printSolution(State* goalState) {
    vector<string> steps;
    State* temp = goalState;
    while (temp != nullptr) {
        if (!temp->operation.empty()) {
            steps.push_back(temp->operation);
        }
        temp = temp->parent;
    }
    cout << "Solución encontrada en " << steps.size() << " pasos:" << endl;
    for (auto it = steps.rbegin(); it != steps.rend(); ++it) {
        cout << *it << endl;
    }
}