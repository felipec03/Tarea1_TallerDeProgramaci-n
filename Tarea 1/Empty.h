#include <iostream>
#include "Operation.h"
using namespace std;

// Fill hereda de Operation de manera pública
class Empty : public Operation {
    public:
    Empty();
    State* operation(State* currentState, int a);
    void printOperation();
};