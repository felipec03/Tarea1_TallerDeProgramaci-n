#include "Pour.h"

Pour::Pour(){
}

// Utilizando polimorfismo, se define la operación de Pour
// que recibe dos enteros, un estado y retorna un puntero a State
// a corresponde al índice del jarro que se quiera trasvasijar hacia b en el arreglo de jarras
State* Pour::operation(State* currentState, int a, int b){
    // Se crea un nuevo estado con el estado actual
    State* newState = currentState;
    // Se calcula la cantidad de agua que se puede trasvasijar
    int water = min(newState->arregloJugs[a], newState->maxCapacities[b] - newState->arregloJugs[b]);
    // Se trasvasija el agua
    newState->arregloJugs[a] -= water;
    newState->arregloJugs[b] += water;
    newState->op = "Pour";
    return newState;
}