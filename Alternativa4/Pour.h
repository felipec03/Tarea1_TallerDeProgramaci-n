#ifndef POUR_H
#define POUR_H

#include <iostream>
#include "Operation.h"
using namespace std;

// Fill hereda de Operation de manera pública
class Pour : public Operation {
    public:
    Pour();
    State* operation(State* currentState, int a, int b) override;
    void printOperation();
    std::string getName() override;
    bool isUnary() override;
};

#endif