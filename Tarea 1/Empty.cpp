#include "Empty.h"

Empty::Empty(){
}

// Utilizando polimorfismo, se define la operación de Empty
// que recibe un entero, un estado y retorna un puntero a State
// a corresponde al índice del jarro que se quiera vaciar en el arreglo de jarras
State* Empty::operation(State* currentState, int a){
    // Se crea un nuevo estado con el estado actual
    State* newState = currentState;
    newState->arregloJugs[a] = 0;
    newState->op = "Empty";
    return newState;
}