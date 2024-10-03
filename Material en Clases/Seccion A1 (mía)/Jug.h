#include <iostream>
#include "Queue.h"
using namespace std;

class Jug {
    public:
    Queue* open;
    Queue* all;
    Jug(int sizeOpen, int sizeAll); 		// Construye con tamaños de open y all

    State* filla0(State* origin);			// Llenar vasija a0
    State* filla1(State* origin);			// Llenar vasija a1
    State* emptya0(State* origin);			// Vaciar vasija a0
    State* emptya1(State* origin);			// Vaciar vasija a1
    State* poura0toa1(State* origin);		// Trasvasijar de a0 -> a1
    State* poura1toa0(State* origin);		// Trasvasijar de a1 -> a0

    State* solve();							// Retorna el estado solución.
};
