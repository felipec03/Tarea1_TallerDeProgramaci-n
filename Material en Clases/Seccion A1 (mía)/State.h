// Inclusión de librerías, NO USAR CONTAINER
#include <iostream>
#include <string>

using namespace std;


// Interfaz para la clase estado
// Se define el estado para el problema de los bidones
class State {
    public:
    int a0;
    int a1;
    State *parent;
    string operation;

    // Contratos
    State(int a0, int a1, State *parent, string operation);

    void print(); // imprime el estado y toda la secuencia de operaciones que lo generaron
};