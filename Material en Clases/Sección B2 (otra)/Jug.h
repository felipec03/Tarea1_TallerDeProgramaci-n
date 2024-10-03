#include <iostream>
#include "Queue.h"

class Jug {
    public:
    Queue *open;
    Queue *closed;
    Jug(State *initial_state);
    State* solve();

    State * fill0(State *s);
    State * fill1(State *s);
    State * empty0(State *s);
    State * empty1(State *s);
    State * a0toa1(State *s);
    State * a1toa0(State *s);
};