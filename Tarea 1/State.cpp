#include "State.h"
// se puede cambiar char* por string

State::State(int *arregloJugs, int* maxCapacities, int numJugs, State *parent, string op) {
    this->arregloJugs = arregloJugs;
    this->maxCapacities = maxCapacities;
    this->numJugs = numJugs;
    this->parent = parent;
    this->op = op;
}

State::State() {
    arregloJugs = nullptr;
    maxCapacities = nullptr;
    parent = nullptr;
    op = "";
}

// print() method
void State::print() {
    cout << "Jarrones: ";
    for (int i = 0; i < numJugs; i++) {
        cout << arregloJugs[i] << " ";
    }
    cout << endl;
}
