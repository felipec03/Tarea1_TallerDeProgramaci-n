// State.cpp

#include "State.h"

State::State(int* arregloJugs, int* maxCapacities, int* goalVolumes, int numJugs, State* parent, string op) {
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
    this->priority = 0;

    // Precomputar el valor hash
    unsigned long hash = 0;
    unsigned long p = 31;
    unsigned long m = 1e9 + 9;
    unsigned long power_of_p = 1;
    for (int i = 0; i < numJugs; ++i) {
        hash = (hash + (this->arregloJugs[i] + 1) * power_of_p) % m;
        power_of_p = (power_of_p * p) % m;
    }
    this->hash_value = hash;
}

State::State(const State& other) {
    numJugs = other.numJugs;
    arregloJugs = new int[numJugs];
    maxCapacities = new int[numJugs];
    goalVolumes = new int[numJugs];
    for(int i = 0; i < numJugs; i++) {
        arregloJugs[i] = other.arregloJugs[i];
        maxCapacities[i] = other.maxCapacities[i];
        goalVolumes[i] = other.goalVolumes[i];
    }
    parent = other.parent;
    op = other.op;
    priority = other.priority;
    hash_value = other.hash_value;
}

State::~State() {
    delete[] arregloJugs;
    delete[] maxCapacities;
    delete[] goalVolumes;
}

bool State::isSolution() {
    for(int i = 0; i < numJugs; i++) {
        if(arregloJugs[i] != goalVolumes[i]) {
            return false;
        }
    }
    return true;
}

void State::print() {
    cout << "Estado actual: ";
    for (int i = 0; i < numJugs; i++) {
        cout << arregloJugs[i] << " ";
    }
    cout << endl;
}

// Heurística para A*
// Se enfoca en la diferencia entre los volúmenes actuales y los volúmenes objetivo
int State::heuristic() const {
    int h = 0;
    for (int i = 0; i < numJugs; ++i) {
        int diff = abs(goalVolumes[i] - arregloJugs[i]);
        h += diff;
    }
    return h;
}

bool State::equals(const State* other) const {
    if (this->numJugs != other->numJugs) return false;
    for (int i = 0; i < numJugs; ++i) {
        if (this->arregloJugs[i] != other->arregloJugs[i]) {
            return false;
        }
    }
    return true;
}