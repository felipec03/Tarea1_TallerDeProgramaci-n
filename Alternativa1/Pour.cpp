// Pour.cpp

#include "Pour.h"

Pour::Pour(){
    operacion = "Pour";
}

State* Pour::operation(State* currentState, int a, int b){
    if(currentState->arregloJugs[a] == 0 || currentState->arregloJugs[b] == currentState->maxCapacities[b]){
        return nullptr;
    }
    int* newJugs = new int[currentState->numJugs];
    for(int i = 0; i < currentState->numJugs; i++){
        newJugs[i] = currentState->arregloJugs[i];
    }
    int water = std::min(currentState->arregloJugs[a], currentState->maxCapacities[b] - currentState->arregloJugs[b]);
    newJugs[a] -= water;
    newJugs[b] += water;
    State* newState = new State(newJugs, currentState->maxCapacities, currentState->goalVolumes, currentState->numJugs, currentState, "Trasvasijar bidón " + std::to_string(a) + " -> " + std::to_string(b));
    delete[] newJugs;
    return newState;
}

string Pour::getName() {
    return "Trasvasijar";
}

bool Pour::isUnary() {
    return false;
}