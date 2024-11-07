// Empty.cpp

#include "Empty.h"

Empty::Empty(){
    operacion = "Empty";
}

State* Empty::operation(State* currentState, int a){
    if(currentState->arregloJugs[a] == 0){
        return nullptr;
    }
    int* newJugs = new int[currentState->numJugs];
    for(int i = 0; i < currentState->numJugs; i++){
        newJugs[i] = currentState->arregloJugs[i];
    }
    newJugs[a] = 0;
    State* newState = new State(newJugs, currentState->maxCapacities, currentState->goalVolumes, currentState->numJugs, currentState, "Vaciar bidón: " + std::to_string(a));
    delete[] newJugs;
    return newState;
}

string Empty::getName() {
    return "Vaciar";
}

bool Empty::isUnary() {
    return true;
}