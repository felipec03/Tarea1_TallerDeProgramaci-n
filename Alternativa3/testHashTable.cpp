#include <iostream>
#include "HashTable.h"

int main(){
    int arregloJugs[] = {0,0,0};
    int maxCapacities[] = {1,2,3};
    int goalVolumes[] = {0,0,0};
    State* state = new State(arregloJugs, maxCapacities, goalVolumes, 3, nullptr, "inicio");
    // Tabla hash vacía
    cout << "Tabla hash vacía" << endl;
    HashTable* hashTable = new HashTable(10);
    // Insertamos estado 
    cout << "Insertamos estado" << endl;
    state->print();
    hashTable->insert(state);
    // Comprobamos si la tabla contiene el estado
    cout << "Comprobamos si la tabla contiene el estado" << endl;
    if(hashTable->contains(state)){
        cout << "La tabla contiene el estado" << endl;
    }else{
        cout << "La tabla no contiene el estado" << endl;
    }
    // Redimensionamos la tabla
    cout << "Redimensionamos la tabla" << endl;
    hashTable->resize();
    // Liberamos memoria
    hashTable->~HashTable();
    return 0;
}