#include "Jug.h"

Jug::Jug(State* initialState, int sizeOpen, int sizeAll) {
    this->initialState = initialState;

    numberOfOperations = 3;
    operationArray = new Operation*[numberOfOperations];
    operationArray[0] = new Fill();
    operationArray[1] = new Empty();
    operationArray[2] = new Pour();

    open = new Heap(sizeOpen);
    all = new HashTable(sizeAll);

    initialState->priority = initialState->heuristic();
    open->push(initialState);
    all->insert(initialState);

    // Initialize the statesCreated array
    statesCapacity = 100;
    statesCount = 0;
    statesCreated = new State*[statesCapacity];
    statesCreated[statesCount++] = initialState;
}

State* Jug::solve() {
    while (!open->isEmpty()) {
        State* current = open->pop();

        if (current->isSolution()) {
            return current;
        }

        for (int i = 0; i < numberOfOperations; ++i) {
            Operation* operation = operationArray[i];
            if (operation->isUnary()) {
                for (int j = 0; j < current->numJugs; ++j) {
                    State* newState = operation->operation(current, j);
                    if (newState != nullptr && !all->contains(newState)) {
                        newState->priority = current->priority + 1 + newState->heuristic();
                        open->push(newState);
                        all->insert(newState);

                        // Add newState to statesCreated array
                        if (statesCount == statesCapacity) {
                            // Resize the array
                            statesCapacity *= 2;
                            State** temp = new State*[statesCapacity];
                            for (int k = 0; k < statesCount; ++k) {
                                temp[k] = statesCreated[k];
                            }
                            delete[] statesCreated;
                            statesCreated = temp;
                        }
                        statesCreated[statesCount++] = newState;
                    } else {
                        delete newState;
                    }
                }
            } else {
                for (int j = 0; j < current->numJugs; ++j) {
                    for (int k = 0; k < current->numJugs; ++k) {
                        if (j != k) {
                            State* newState = operation->operation(current, j, k);
                            if (newState != nullptr && !all->contains(newState)) {
                                newState->priority = current->priority + 1 + newState->heuristic();
                                open->push(newState);
                                all->insert(newState);

                                // Add newState to statesCreated array
                                if (statesCount == statesCapacity) {
                                    // Resize the array
                                    statesCapacity *= 2;
                                    State** temp = new State*[statesCapacity];
                                    for (int l = 0; l < statesCount; ++l) {
                                        temp[l] = statesCreated[l];
                                    }
                                    delete[] statesCreated;
                                    statesCreated = temp;
                                }
                                statesCreated[statesCount++] = newState;
                            } else {
                                delete newState;
                            }
                        }
                    }
                }
            }
        }
    }
    return nullptr;
}

void Jug::printSolution(State* state) {
    if (state == nullptr) {
        return;
    }
    printSolution(state->parent);
    if (!state->op.empty()) {
        std::cout << state->op << std::endl;
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

    // Delete all created State objects
    for (int i = 0; i < statesCount; ++i) {
        delete statesCreated[i];
    }
    delete[] statesCreated;
}