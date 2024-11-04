// State.h

#ifndef STATE_H
#define STATE_H

#include <iostream>

using namespace std;

class State {
public:
    int* arregloJugs;
    int* maxCapacities;
    int* goalVolumes;
    int numJugs;
    State* parent;
    std::string operation;
    int cost;
    int priority;
    int totalDiff;
    bool isDeadEnd;
    unsigned long long key; // Unique key for the state

    State(int* arregloJugs, int* maxCapacities, int* goalVolumes, int numJugs, State* parent, const std::string& op);
    ~State();

    bool equals(const State* other) const;
    bool equals(const int* jugArray) const;
    int heuristic();
    bool isSolution() const;
    bool isDifferentFrom(const State* other) const;
    void computeKey(); // Method to compute the state's key
    void print() const;
};

#endif