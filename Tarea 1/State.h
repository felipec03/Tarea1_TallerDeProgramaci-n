#ifndef STATE_H
#define STATE_H

#include <iostream>

using namespace std;

class State {
    public:
    int* arregloJugs;                   // Arreglo con los valores de los jarrones
    int* maxCapacities;                 // Arreglo con las capacidades máximas de los jarrones
    int* goalVolumes;                   // Arreglo con los volúmenes objetivo de los jarrones
    int numJugs;                        // Número de jarrones
    State *parent;                      // Puntero al estado padre
    string op;                          // Operación que se realizó para llegar a este estado
    float priority;                     // Prioridad del estado
    
    State(int* arregloJugs, int* maxCapacities, int numJugs, State *parent, string op);
    State();
    ~State();
    bool isSolution();
    bool isFinal();
    void print();
};

#endif