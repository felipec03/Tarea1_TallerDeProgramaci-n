#include "Fill.h"

Fill::Fill(){
}

// Utilizando polimorfismo, se define la operación de Fill
// que recibe un entero y retorna un puntero a State
// a corresponde al índice del jarro que se quiera llenar en el arreglo de jarras
State* Fill::operation(State* currentState, int a){
    // Se crea un nuevo estado con el estado actual
    State* newState = currentState;
        newState->arregloJugs[a] = newState->maxCapacities[a];
        newState->op = "Fill";
        return newState;
    }
