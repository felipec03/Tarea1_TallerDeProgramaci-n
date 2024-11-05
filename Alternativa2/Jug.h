#ifndef JUG_H
#define JUG_H

#include <iostream>
#include "HashTable.h"
#include "Fill.h"
#include "Empty.h"
#include "Pour.h"
#include "PriorityQueue.h"

class Jug {
public:
    State* initialState;
    PriorityQueue* open;
    HashTable* all;

    int numberOfOperations;
    Operation** operationArray;

    //State** statesCreated;
    //int statesCapacity;
    //int statesCount;

    Jug(State* initialState, unsigned long sizeOpen, unsigned long sizeAll);
    State* solve();
    void printSolution(State* s);
    ~Jug();
};

#endif