// Fill.cpp

#include "Fill.h"

Fill::Fill() {
    operacion = "Fill";
}

State* Fill::operation(State* currentState, int a) {
    if (currentState->arregloJugs[a] == currentState->maxCapacities[a]) {
        return nullptr; // Jug is already full
    }
    
    // Create new state
    int* newJugs = new int[currentState->numJugs];
    for (int i = 0; i < currentState->numJugs; i++) {
        newJugs[i] = currentState->arregloJugs[i];
    }
    newJugs[a] = currentState->maxCapacities[a];

    // Check if new state is same as parent state
    if (currentState->parent && currentState->parent->equals(currentState)) {
        delete[] newJugs;
        return nullptr;
    }

    State* newState = new State(newJugs, currentState->maxCapacities, currentState->goalVolumes, currentState->numJugs, currentState, "Llenar bidón -> " + std::to_string(a));
    delete[] newJugs;
    return newState;
}
string Fill::getName() {
    return "Llenar";
}

bool Fill::isUnary() {
    return true;
}