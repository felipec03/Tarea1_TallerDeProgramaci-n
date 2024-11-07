#include "Jug.h"
using namespace std;

Jug::Jug(State* initialState, unsigned long sizeOpen, unsigned long long sizeAll) {
    this->initialState = initialState;

    numberOfOperations = 3;
    operationArray = new Operation*[numberOfOperations];
    operationArray[0] = new Fill();
    operationArray[1] = new Empty();
    operationArray[2] = new Pour();

    open = new PriorityQueue(sizeOpen);
    all = new HashTable(sizeAll);

    initialState->priority = initialState->heuristic();
    open->push(initialState);
    all->insert(*initialState);
}

State* Jug::solve() {
    // Identify jugs that need to change
    bool* isGoalJug = new bool[initialState->numJugs];
    for (int i = 0; i < initialState->numJugs; ++i) {
        isGoalJug[i] = (initialState->goalVolumes[i] != initialState->arregloJugs[i]);
    }

    int* newJugs = new int[initialState->numJugs];

    open->push(initialState);
    all->insert(*initialState);

    while (!open->isEmpty()) {
        State* current = open->pop();
        
        if (current->isSolution()) {
            delete[] isGoalJug;
            return current;
        }

        if (current->costo > 30) { // Limit depth
            continue;
        }

    

        for (int i = 0; i < numberOfOperations; ++i) {
            Operation* operation = operationArray[i];
            if (operation->isUnary()) {
                for (int j = 0; j < initialState->numJugs; ++j) {
                    memcpy(newJugs, current->arregloJugs, sizeof(int) * initialState->numJugs);
                    State* newState = operation->operation(current, j);
                    if (newState != nullptr) {
                        newState->costo = current->costo + 1;
                        newState->priority = newState->costo + newState->heuristic();
                        if (!all->contains(*newState)) {
                            open->push(newState);
                            all->insert(*newState);
                        } else {
                            delete newState;
                        }
                    }
                }
            } else {
                for (int a = 0; a < initialState->numJugs; ++a) {
                    for (int b = 0; b < initialState->numJugs; ++b) {
                        if (a != b) {
                            State* newState = operation->operation(current, a, b);
                            if (newState != nullptr) {
                                newState->costo = current->costo + 1;
                                newState->priority = newState->costo + newState->heuristic();
                                if (!all->contains(*newState)) {
                                    open->push(newState);
                                    all->insert(*newState);
                                } else {
                                    delete newState;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    delete[] newJugs;
    delete[] isGoalJug;
    return nullptr;
}


void Jug::printSolution(State* state, int numberOfStates) {
    if (state == nullptr) {
        cout << "Numero de operaciones tomadas: " << numberOfStates << endl;
        return;
    }
    printSolution(state->parent, numberOfStates + 1);
    if (!state->op.empty()) {
        cout << state->op << endl;
        state->print();
    }
}

Jug::~Jug() {
    for (int i = 0; i < numberOfOperations; ++i) {
        delete operationArray[i];
    }
    delete[] operationArray;
    delete open;
    delete all;
}