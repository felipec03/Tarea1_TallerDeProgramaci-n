// Pour.cpp

#include "Pour.h"

Pour::Pour(){
    operacion = "Pour";
}

State* Pour::operation(State* currentState, int a, int b) {
    if (currentState->arregloJugs[a] == 0 || 
        currentState->arregloJugs[b] == currentState->maxCapacities[b]) {
        return nullptr; // Cannot pour from empty jug or into a full jug
    }

    // Calculate pour amount
    int pourAmount = std::min(currentState->arregloJugs[a], currentState->maxCapacities[b] - currentState->arregloJugs[b]);

    // Create new state
    int* newJugs = new int[currentState->numJugs];
    for (int i = 0; i < currentState->numJugs; i++) {
        newJugs[i] = currentState->arregloJugs[i];
    }
    newJugs[a] -= pourAmount;
    newJugs[b] += pourAmount;

    // Check if new state is same as parent state
    if (currentState->parent && currentState->parent->equals(newJugs)) {
        delete[] newJugs;
        return nullptr;
    }

    State* newState = new State(newJugs, currentState->maxCapacities, currentState->goalVolumes, currentState->numJugs, currentState, "Verter de " + std::to_string(a) + " a " + std::to_string(b));
    delete[] newJugs;
    return newState;
}

string Pour::getName() {
    return "Trasvasijar";
}

bool Pour::isUnary() {
    return false;
}