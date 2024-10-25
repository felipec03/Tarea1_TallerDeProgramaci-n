#include "State.h"
// se puede cambiar char* por string

State::State(int *arregloJugs, int numJugs, State *parent, char *op) {
    this->arregloJugs = arregloJugs;
    this->numJugs = numJugs;
    this->parent = parent;
    this->op = op;
}

State::State() {
    arregloJugs = nullptr;
    parent = nullptr;
    op = (char *) "";
}

void State::print() { // recorrido en preorden
    if (parent != nullptr) { // si no es el estado inicial
//        cout<< "parent: "<<parent<<endl;
        parent->print();
        cout << op << endl;
    }
    cout << "a0: " << a0 << " a1: " << a1 << endl;
}


