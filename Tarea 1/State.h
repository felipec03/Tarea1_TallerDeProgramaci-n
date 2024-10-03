#include <iostream>
using namespace std;

class State {
    public:
    int a0; // maximo 3
    int a1; // maximo 5
    State *parent;
    char *op;
    float priority;
    State(int a0, int a1, State *parent, char *op);
    State();
    void print();
    bool is_goal();
};