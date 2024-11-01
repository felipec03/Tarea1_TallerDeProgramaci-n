#ifndef EMPTY_H
#define EMPTY_H

#include <iostream>
#include "Operation.h"
using namespace std;

// Fill hereda de Operation de manera pública
class Empty : public Operation {
    public:
    Empty();
    State* operation(State* currentState, int a) override;
    void printOperation();
    std::string getName() override;
    bool isUnary() override;
};

#endif