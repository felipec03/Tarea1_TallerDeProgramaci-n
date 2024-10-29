#include <iostream>
#include "Operation.h"
using namespace std;

// Fill hereda de Operation de manera pública
class Pour : public Operation {
    public:
    Pour();
    State* operation(State* currentState, int a, int b);
    void printOperation();
};