// State.cpp

#include "State.h"
#include <cmath>
#include <bits/stdc++.h>
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
    unsigned long hash = 5381;
    for (int i = 0; i < numJugs; ++i) {
        hash = ((hash << 5) + hash) + arregloJugs[i]; // DJB2 hash
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


void State::print() const {
    std::cout << "Estado actual: ";
    for (int i = 0; i < numJugs; i++) {
        std::cout << arregloJugs[i] << " ";
    }
    std::cout << std::endl;
}


int State::heuristic() const {
    int h = 0;
    int totalDiff = 0;
    
    // Calculate total volume difference
    int currentTotal = 0;
    int goalTotal = 0;
    for (int i = 0; i < numJugs; ++i) {
        currentTotal += arregloJugs[i];
        goalTotal += goalVolumes[i];
        
        // Direct differences weighted more heavily
        h += std::abs(goalVolumes[i] - arregloJugs[i]) * 2;
    }
    
    // Add overall volume difference
    totalDiff = std::abs(currentTotal - goalTotal);
    h += totalDiff;
    
    return h;
}

bool State::equals(const State* other) const {
    if (this->numJugs != other->numJugs && this->arregloJugs[0] != other->arregloJugs[0]) {
        return false;
        }
    for (int i = 0; i < numJugs; ++i) {
        if (this->arregloJugs[i] != other->arregloJugs[i]) {
            return false;
        }
    }
    return true;
}

bool State::isSolution() const {
    for (int i = 0; i < numJugs; i++) {
        if (arregloJugs[i] != goalVolumes[i]) {
            return false;
        }
    }
    return true;
}

// IDEA AVL
// Comparison operators

bool State::operator<(const State& other) const {
    return this->priority < other.priority;
}

bool State::operator>(const State& other) const {
    return this->priority > other.priority;
}

bool State::operator==(const State& other) const {
    return this->equals(&other);
}