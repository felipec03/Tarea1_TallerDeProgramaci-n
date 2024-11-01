#include "Jug.h"

int main(){
    int initialVolumes[3] = {0, 0, 0};     // Starting with empty jugs
    int capacities[3] = {3, 5, 7};         // Capacities of the jugs
    int goalVolumes[3] = {0, 0, 6};        // Desired volumes in the goal state

    State* initialState = new State(initialVolumes, capacities, goalVolumes, 3, nullptr, "Inicio");
    
    Jug j = Jug(initialState, 100, 100);
    
    State* solution = j.solve();

    // Check if a solution was found
    if (solution != nullptr) {
        cout << "Solution found!" << endl;
        j.printSolution(solution);
    } else {
        cout << "No solution exists." << endl;
    }

    delete initialState; // Clean up
    return 0;
}