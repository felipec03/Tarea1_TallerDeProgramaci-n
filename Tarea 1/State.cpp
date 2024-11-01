#include "State.h"
// se puede cambiar char* por string

State::State(int* arregloJugs, int* maxCapacities, int* goalVolumes, int numJugs, State *parent, string op) {
    this->numJugs = numJugs;
    this->arregloJugs = new int[numJugs];
    this->maxCapacities = new int[numJugs];
    this->goalVolumes = new int[numJugs];
    for(int i = 0; i < numJugs; i++) {
        this->arregloJugs[i] = arregloJugs[i];
        this->maxCapacities[i] = maxCapacities[i];
        this->goalVolumes[i] = goalVolumes[i];
    }
    this->parent = parent;
    this->op = op;
}

State::State() {
    arregloJugs = nullptr;
    maxCapacities = nullptr;
    parent = nullptr;
    op = "";
}

// Destructor
State::~State() {
    delete[] arregloJugs;
    delete[] maxCapacities;
    delete[] goalVolumes;
}

// Revisa si el arreglo de jugs actual es igual al arreglo de jugs objetivo
// Se comparan dos arreglos de numeros enteros
bool State::isSolution() {
    for(int i = 0; i < numJugs; i++) {
        if(arregloJugs[i] != goalVolumes[i]) {
            return false;
        }
    }
    return true;
}

bool State::isFinal() {
    for (int i = 0; i < numJugs; i++) {
        if (arregloJugs[i] == 2) {
            return true;
        }
    }
    return false;
}

// print() method
void State::print() {
    cout << "Jarrones: ";
    for (int i = 0; i < numJugs; i++) {
        cout << arregloJugs[i] << " ";
    }
    cout << endl;
}
