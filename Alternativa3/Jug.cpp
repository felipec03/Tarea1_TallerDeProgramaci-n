// Jug.cpp
#include "Jug.h"
#include <iostream>
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
    all->insert(initialState);
}

State* Jug::solve() {
    bool* isGoalJug = new bool[initialState->numJugs];
    for (int i = 0; i < initialState->numJugs; ++i) {
        isGoalJug[i] = (initialState->goalVolumes[i] != initialState->arregloJugs[i]);
    }

    int numberOfStates = 0;
    State* result = nullptr;

    while (!open->isEmpty()) {
        State* current = open->pop();
        ++numberOfStates;

        if (current->isSolution()) {
            result = current;
            break;
        }

        for (int i = 0; i < initialState->numJugs; ++i) {
            if (isGoalJug[i]) {
                for (int j = 0; j < numberOfOperations; ++j) {
                    if (operationArray[j]->isUnary()) {
                        State* newState = operationArray[j]->operation(current, i);
                        if (newState != nullptr) {
                            newState->priority = newState->costo + newState->heuristic();
                            if (!all->contains(newState)) {
                                open->push(newState);
                                all->insert(newState);
                            } else {
                                delete newState;
                            }
                        }
                    }
                }
            }
        }

        for (int i = 0; i < initialState->numJugs; ++i) {
            for (int j = 0; j < initialState->numJugs; ++j) {
                if (i != j && (isGoalJug[i] || isGoalJug[j])) {
                    for (int k = 0; k < numberOfOperations; ++k) {
                        if (!operationArray[k]->isUnary()) {
                            State* newState = operationArray[k]->operation(current, i, j);
                            if (newState != nullptr) {
                                newState->priority = newState->costo + newState->heuristic();
                                if (!all->contains(newState)) {
                                    open->push(newState);
                                    all->insert(newState);
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

    delete[] isGoalJug;
    return result;
}

void Jug::printSolution(State* state, int numberOfStates) {
    if (state == nullptr) {
        cout << "No solution was found." << endl;
        return;
    }
    // Count steps
    int steps = 0;
    State* current = state;
    while (current != nullptr) {
        if (!current->op.empty()) {
            steps++;
        }
        current = current->parent;
    }

    // Create an array to store the steps
    std::string* stepArray = new std::string[steps];
    current = state;
    int index = steps - 1;
    while (current != nullptr) {
        if (!current->op.empty()) {
            stepArray[index--] = current->op;
        }
        current = current->parent;
    }

    cout << "Number of states explored: " << numberOfStates << endl;
    cout << "Steps to solution:" << endl;
    for (int i = 0; i < steps; ++i) {
        cout << stepArray[i] << endl;
    }
    delete[] stepArray;
}

Jug::~Jug() {
    delete open;

    // Delete all State objects
    all->deleteAllStates();
    delete all;

    // Delete operations
    for (int i = 0; i < numberOfOperations; i++) {
        delete operationArray[i];
    }
    delete[] operationArray;
}