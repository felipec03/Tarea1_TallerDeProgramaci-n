// State.h

#ifndef STATE_H
#define STATE_H

#include <iostream>
#include <cstring>

class State {
public:
    int* arregloJugs;               // Current volumes
    const int* maxCapacities;       // Max capacities (shared)
    const int* goalVolumes;         // Goal volumes (shared)
    int numJugs;                    // Number of jugs
    State* parent;                  // Parent state
    std::string op;                 // Operation performed
    float priority;                 // Priority for A*
    unsigned long hash_value;       // Precomputed hash value
    int costo;

    State(int* arregloJugs, const int* maxCapacities, const int* goalVolumes, int numJugs, State* parent, const std::string& op);
    State(const State& other);
    ~State();
    bool isSolution() const;
    void print() const;
    int heuristic() const;
    bool equals(const State* other) const;
};

#endif