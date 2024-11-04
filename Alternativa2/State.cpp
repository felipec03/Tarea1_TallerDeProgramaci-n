// State.cpp

#include "State.h"

State::State(int* arregloJugs, int* maxCapacities, int* goalVolumes, int numJugs, State* parent, const std::string& op)
    : arregloJugs(arregloJugs), maxCapacities(maxCapacities),
      goalVolumes(goalVolumes), numJugs(numJugs), parent(parent),
      operation(op), cost(0), priority(0), totalDiff(-1), isDeadEnd(false) {
    computeKey();
}

State::~State() {
    if (arregloJugs != nullptr) {
        delete[] arregloJugs;
        arregloJugs = nullptr;
    }
    if (maxCapacities != nullptr) {
        delete[] maxCapacities;
        maxCapacities = nullptr;
    }
    if (goalVolumes != nullptr) {
        delete[] goalVolumes;
        goalVolumes = nullptr;
    }
}

void State::computeKey() {
    // Simple hash function combining jug volumes
    key = 0;
    for (int i = 0; i < numJugs; ++i) {
        key = key * 31 + arregloJugs[i];
    }
}

bool State::equals(const State* other) const {
    if (other == nullptr || numJugs != other->numJugs) {
        return false;
    }
    for (int i = 0; i < numJugs; ++i) {
        if (arregloJugs[i] != other->arregloJugs[i]) {
            return false;
        }
    }
    return true;
}

// Overload for array comparison
bool State::equals(const int* jugArray) const {
    for (int i = 0; i < numJugs; ++i) {
        if (arregloJugs[i] != jugArray[i]) {
            return false;
        }
    }
    return true;
}

bool State::isSolution() const {
    for (int i = 0; i < numJugs; ++i) {
        if (arregloJugs[i] != goalVolumes[i]) {
            return false;
        }
    }
    return true;
}

// Heurística para A*
// Se enfoca en la diferencia entre los volúmenes actuales y los volúmenes objetivo
// El nombre formal de esta heurística es "Manhattan distance"
int State::heuristic() {
    if (totalDiff != -1) {
        return totalDiff;
    }
    totalDiff = 0;
    for (int i = 0; i < numJugs; ++i) {
        totalDiff += abs(arregloJugs[i] - goalVolumes[i]);
    }
    return totalDiff;
}

bool State::isDifferentFrom(const State* other) const {
    for (int i = 0; i < numJugs; ++i) {
        if (arregloJugs[i] != other->arregloJugs[i]) return true;
    }
    return false;
}

void State::print() const {
    cout << "Estado actual: ";
    for (int i = 0; i < numJugs; i++) {
        cout << arregloJugs[i] << " ";
    }
    cout << endl;
}