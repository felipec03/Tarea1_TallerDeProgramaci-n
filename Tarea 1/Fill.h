#ifndef FILL_CLASS
#define FILL_CLASS

#include <iostream>

using namespace std;

// Fill hereda de Operation de manera pública
class Fill : public Operation {
    public:
    char* operationName;
    Fill();
    State* operation(int a);
    void printOperation();
};

