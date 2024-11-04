#ifndef JUG_H
#define JUG_H

#include <iostream>
#include "MinHeap.h"
#include "HashTable.h"
#include "Fill.h"
#include "Empty.h"
#include "Pour.h"

class Jug {
private:
    State* initialState;
    MinHeap* openSet;
    HashTable* closedSet;
    int numberOfOperations;
    Operation** operationArray;
    
public:
    Jug(State* initialState, unsigned long sizeOpen, unsigned long sizeAll);
    State* solve();
    void printSolution(State* goalState);
    ~Jug();
};

#endif