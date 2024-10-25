#include "Fill.h"

Fill:Fill(){
    return nullptr;
}


// Utilizando polimorfismo, se define la operación de Fill
// que recibe un entero y retorna un puntero a State
// a corresponde al índice del jarro que se quiera llenar en el arreglo de jarras
State* Fill::operation(int a){
    // Se crea un nuevo estado con el estado actual
    State* newState = new State(*currentState);
    
}