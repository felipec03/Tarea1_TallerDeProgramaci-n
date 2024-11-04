#include "State.h"

int main(){
    // Creamos un estado vacío
    int arregloJugs[] = {0,0,0};
    int maxCapacities[] = {1,2,3};
    int goalVolumes[] = {0,0,0};
    State* state = new State(arregloJugs, maxCapacities, goalVolumes, 3, nullptr, "inicio");
    // Imprimimos el estado
    state->print();
    // Comprobamos si el estado es solución
    bool esSolucion = state->isSolution();
    cout << "Es la solución?: " << esSolucion << endl;
    // Calculamos la heurística
    cout << "Heurística asociada al estado: " << state->heuristic() << endl; 
    // Comparamos si el estado es igual a otro
    State* state2 = new State(arregloJugs, maxCapacities, goalVolumes, 3, nullptr, "segundo");
    bool iguales = state->equals(state2);
    cout << "Son iguales: " << iguales << endl;
    // Calculamos la clave del estado
    state->computeKey();
    // Liberamos memoria
    state->~State();

    return 0;
}