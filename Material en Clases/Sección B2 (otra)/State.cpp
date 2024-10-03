#include "State.h"
// se puede cambiar char* por string

State::State(int a0, int a1, State *parent, char *op) {
    this->a0 = a0;
    this->a1 = a1;
    this->parent = parent;
    this->op = op;
}

State::State() {
    a0 = -1;
    a1 = -1;
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

bool State::is_goal() {
    return a1 == 4;
}

