// State.cpp

#include "State.h"
#include <cmath>
using namespace std;

State::State(int* arregloJugs, const int* maxCapacities, const int* goalVolumes, int numJugs, State* parent, const std::string& op) {
    this->numJugs = numJugs;
    this->arregloJugs = new int[numJugs];
    for (int i = 0; i < numJugs; i++) {
        this->arregloJugs[i] = arregloJugs[i];
    }
    this->maxCapacities = maxCapacities;   // Shared pointers
    this->goalVolumes = goalVolumes;       // Shared pointers
    this->parent = parent;
    this->op = op;
    this->costo = (parent != nullptr) ? parent->costo + 1 : 0;
    this->priority = this->costo + heuristic();

    // Precompute the hash value
    unsigned long hash = 0;
    unsigned long p = 31;
    unsigned long m = 1000000009;
    unsigned long power_of_p = 1;
    for (int i = 0; i < numJugs; ++i) {
        hash = (hash + (arregloJugs[i] + 1) * power_of_p) % m;
        power_of_p = (power_of_p * p) % m;
    }
    this->hash_value = hash;
}

State::State(const State& other) {
    numJugs = other.numJugs;
    arregloJugs = new int[numJugs];
    for (int i = 0; i < numJugs; i++) {
        arregloJugs[i] = other.arregloJugs[i];
    }
    maxCapacities = other.maxCapacities;   // Shared pointers
    goalVolumes = other.goalVolumes;       // Shared pointers
    parent = other.parent;
    op = other.op;
    priority = other.priority;
    hash_value = other.hash_value;
}

State::~State() {
    delete[] arregloJugs;
    // Do not delete maxCapacities or goalVolumes since they are shared
}

bool State::isSolution() const {
    for (int i = 0; i < numJugs; i++) {
        if (arregloJugs[i] != goalVolumes[i]) {
            return false;
        }
    }
    return true;
}

void State::print() const {
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
    for (int i = 0; i < numJugs; i++) {
        h += abs(goalVolumes[i] - arregloJugs[i]);
    }
    return h;
}

bool State::equals(const State* other) const {
    if (this->numJugs != other->numJugs) {
        return false;
    }
    for (int i = 0; i < numJugs; ++i) {
        if (this->arregloJugs[i] != other->arregloJugs[i]) {
            return false;
        }
    }
    return true;
}