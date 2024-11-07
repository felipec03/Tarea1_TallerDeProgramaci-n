#ifndef FILL_H
#define FILL_H

#include <iostream>
#include "Operation.h"
using namespace std;

// Fill hereda de Operation de manera pública
class Fill : public Operation {
    public:
    Fill();
    State* operation(State* currentState, int a) override;
    void printOperation();
    std::string getName();
    bool isUnary();
};

#endif