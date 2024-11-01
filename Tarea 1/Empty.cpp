#include "Empty.h"

Empty::Empty(){
}

// Utilizando polimorfismo, se define la operación de Empty
// que recibe un entero, un estado y retorna un puntero a State
// a corresponde al índice del jarro que se quiera vaciar en el arreglo de jarras
State* Empty::operation(State* currentState, int a){
    // Se crea un nuevo estado con el estado actual

    if(currentState->arregloJugs[a] == 0){
        return nullptr;
    }

    int* newJugs = new int[currentState->numJugs];
    for(int i = 0; i < currentState->numJugs; i++){
        newJugs[i] = currentState->arregloJugs[i];
    }
    newJugs[a] = 0;
    State* newState = new State(newJugs, currentState->maxCapacities, currentState->numJugs, currentState, "Empty jug " + std::to_string(a));
    delete[] newJugs;
    return newState;
}

string Empty::getName() {
    return "Empty";
}

bool Empty::isUnary() {
    return true;
}