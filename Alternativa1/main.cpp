#include "Jug.h"

int main() {
    int initialVolumes[8] = {2, 3, 5, 7, 9, 11, 13, 17};     // Starting with full jugs
    int capacities[8]     = {2, 3, 5, 7, 9, 11, 13, 17};     // Capacities of the jugs
    int goalVolumes[8]    = {0, 0, 0, 0, 0, 0, 0, 6};     // Desired volumes in the goal state

    State* initialState = new State(initialVolumes, capacities, goalVolumes, 8, nullptr, "Inicio");
    
    Jug j = Jug(initialState, 10000000, 10000000);
    
    State* solution = j.solve();

    if (solution != nullptr) {
        std::cout << "Solution found!" << std::endl;
        j.printSolution(solution);
    } else {
        std::cout << "No solution exists." << std::endl;
    }

    return 0;
}