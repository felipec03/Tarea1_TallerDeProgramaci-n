// Fill.cpp

#include "Fill.h"

Fill::Fill() {
    operacion = "Fill";
}

State* Fill::operation(State* currentState, int a) {
    if (currentState->arregloJugs[a] == currentState->maxCapacities[a]) {
        return nullptr;
    }
    int* newJugs = new int[currentState->numJugs];
    for (int i = 0; i < currentState->numJugs; i++) {
        newJugs[i] = currentState->arregloJugs[i];
    }
    newJugs[a] = currentState->maxCapacities[a];
    State* newState = new State(newJugs, currentState->maxCapacities, currentState->goalVolumes, currentState->numJugs, currentState, "Fill jug " + std::to_string(a));
    delete[] newJugs;
    return newState;
}

string Fill::getName() {
    return "Fill";
}

bool Fill::isUnary() {
    return true;
}