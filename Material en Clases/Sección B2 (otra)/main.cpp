#include "Jug.h"

int main() {
    State *initial_state = new State(0, 0, nullptr, (char *) "");
    
    Jug *j = new Jug(initial_state);
    State *solution = j->solve();
    if (solution == nullptr) {
        cout << "No solution" << endl;
    } else {
        solution->print();
    }
    return 0;
}