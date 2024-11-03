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
    cout << "Jugs: ";
    for (int i = 0; i < numJugs; i++) {
        cout << arregloJugs[i] << " ";
    }
    cout << endl;
}

// Función heurística
int State::heuristic() {
    int h = 0;
    for(int i = 0; i < numJugs; i++) {
        if (goalVolumes[i] != 0) {
            h += abs(arregloJugs[i] - goalVolumes[i]);
        }
    }
    return h;
}

bool State::equals(const State* other) const {
    if (numJugs != other->numJugs) {
        return false;
    }
    for (int i = 0; i < numJugs; ++i) {
        if (arregloJugs[i] != other->arregloJugs[i]) {
            return false;
        }
    }
    return true;
}