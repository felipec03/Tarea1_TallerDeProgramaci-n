#include <iostream>
#include "Operation.h"
using namespace std;

// Fill hereda de Operation de manera pública
class Fill : public Operation {
    public:
    Fill();
    State* operation(State* currentState, int a);
    void printOperation();
};