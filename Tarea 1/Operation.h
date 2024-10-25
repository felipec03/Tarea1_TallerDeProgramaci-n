#include <iostream>
using namespace std;

// La clase operación tiene por objetivo generalizar las operaciones Fill, Empty y Pour.
// Para ello, se define una clase abstracta que tiene dos métodos virtuales que serán
// implementados por las clases Fill, Empty y Pour.
// La clase Operation tiene un constructor por defecto y dos métodos virtuales que retornan
// un puntero a State.
// La clase Operation no tiene atributos.

class Operation{
    public:
    Operation operation();
    // El método operation(int a) recibe un entero y retorna un puntero a State.
    // a corresponde al índice del jarro que se quiera llenar en el arreglo de jarras
    State* virtual operation(int a);
    // El método operation(int a, int b) recibe dos enteros y retorna un puntero a State.
    // a corresponde al índice del jarro que se quiera trasvasijar hacia b en el arreglo de jarras
    State* virtual operation(int a, int b);
};