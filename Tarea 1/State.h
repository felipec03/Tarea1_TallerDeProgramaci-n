#include <iostream>
using namespace std;

class State {
    public:
    int* arregloJugs;                   // Arreglo con los valores de los jarrones
    int numJugs;                        // Número de jarrones
    State *parent;                      // Puntero al estado padre
    char *op;                           // Operación que se realizó para llegar a este estado
    float priority;                     // Prioridad del estado
    
    State(int* arregloJugs, State *parent, char *op);
    State();
    void print();
};