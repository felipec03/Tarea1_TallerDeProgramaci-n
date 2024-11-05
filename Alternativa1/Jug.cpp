#include "Jug.h"

Jug::Jug(State* initialState, unsigned long sizeOpen, unsigned long sizeAll) {
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

    //statesCapacity = 100;
    //statesCount = 0;
    //statesCreated = new State*[statesCapacity];
    //statesCreated[statesCount++] = initialState;
}

State* Jug::solve() {
    // Identify jugs that need to change
    bool* isGoalJug = new bool[initialState->numJugs];
    for (int i = 0; i < initialState->numJugs; ++i) {
        isGoalJug[i] = (initialState->goalVolumes[i] != initialState->arregloJugs[i]);
    }

    int numberOfStates = 0;

    while (!open->isEmpty()) {
        State* current = open->pop();
        ++numberOfStates;
        
        if (current->isSolution()) {
            delete[] isGoalJug;
            cout << "Resuelto en " << numberOfStates << " estados" << endl;
            return current;
        }

        for (int i = 0; i < numberOfOperations; ++i) {
            Operation* operation = operationArray[i];

            if (operation->isUnary()) {
                for (int jug = 0; jug < initialState->numJugs; ++jug) {

                    State* newState = operation->operation(current, jug);
                    if (newState && !all->contains(newState)) {
                        newState->priority = newState->heuristic();
                        open->push(newState);
                        all->insert(newState);
                    } else {
                        delete newState;
                    }
                }
            } else {
                for (int fromJug = 0; fromJug < initialState->numJugs; ++fromJug) {
                    for (int toJug = 0; toJug < initialState->numJugs; ++toJug) {
                        if (fromJug != toJug) {
                            State* newState = operation->operation(current, fromJug, toJug);
                            if (newState && !all->contains(newState)) {
                                newState->priority = newState->heuristic();
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

    delete[] isGoalJug;
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
}