#include "Pour.h"

Pour::Pour(){
}

// Utilizando polimorfismo, se define la operación de Pour
// que recibe dos enteros, un estado y retorna un puntero a State
// a corresponde al índice del jarro que se quiera trasvasijar hacia b en el arreglo de jarras
State* Pour::operation(State* currentState, int a, int b){
    if(currentState->arregloJugs[a] == 0 || currentState->arregloJugs[b] == currentState->maxCapacities[b]){
        return nullptr;
    }
    // Crear un nuevo estado con el agua trasvasijada
    int* newJugs = new int[currentState->numJugs];
    for(int i = 0; i < currentState->numJugs; i++){
        newJugs[i] = currentState->arregloJugs[i];
    }

    newJugs[a] = currentState->arregloJugs[a];

    // Hay que calcular cuánta agua se puede trasvasijar
    int water = std::min(currentState->arregloJugs[a], currentState->maxCapacities[b] - currentState->arregloJugs[b]);
    
    // Se trasvasija el agua
    newJugs[a] -= water;
    newJugs[b] += water;
    State* newState = new State(newJugs, currentState->maxCapacities, currentState->numJugs, currentState, "Pour jug " + std::to_string(a) + " into jug " + std::to_string(b));
    delete[] newJugs;
    return newState;
}

string Pour::getName() {
    return "Pour";
}

bool Pour::isUnary() {
    return false;
}