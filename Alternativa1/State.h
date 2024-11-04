// State.h

#ifndef STATE_H
#define STATE_H

#include <iostream>
#include <vector>

using namespace std;

class State {
    public:
        int* arregloJugs;       // Current volumes
        int* maxCapacities;     // Max capacities
        int* goalVolumes;       // Goal volumes
        int numJugs;            // Number of jugs
        State* parent;                   // Parent state
        string op;                       // Operation performed
        float priority;                  // Priority for A*
        unsigned long hash_value;        // Valor precalculado del hash

        State(int* arregloJugs, int* maxCapacities, int* goalVolumes, int numJugs, State* parent, string op);
        State(const State& other);
        ~State();
        bool isSolution();
        void print();
        int heuristic() const;        
        bool equals(const State* other) const;
};

#endif