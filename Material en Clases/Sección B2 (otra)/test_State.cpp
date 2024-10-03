#include "State.h"

int main() {
    State *s = new State(0, 0, nullptr, (char *) "");
    s->print();

    State *s1 = new State(3, 0, s, (char *) "llenar a0");
    s1->print();

    State *s2 = new State(3, 5, s1, (char *) "llenar a1");
    s2->print();



    return 0;
}