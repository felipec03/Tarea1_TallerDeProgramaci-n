// Implementación de clase HashTable para almacenamiento de States
#include "HashTable.h"

// Constructor de HashTable con capacidad n
HashTable::HashTable(int n){
    capacity=n;
    number=0;
    arr = new State*[n];
    for (int i=0; i<n; i++){
        arr[i]=nullptr;
    }
}

// Constructor de HashTable con capacidad por defecto
HashTable::HashTable(){
    capacity=100;
    number=0;
    arr = new State*[100];
    for (int i=0; i<100; i++){
        arr[i]=nullptr;
    }
}

// Destructor de HashTable
HashTable::~HashTable(){
    for (int i=0; i<capacity; i++){
        if (arr[i]!=nullptr){
            delete arr[i];
        }
    }
    delete[] arr;
}

// Función de hash generalizada para n Jarros
int HashTable::hash(State *s){
    int hash = 0;
    for(int i = 0 ; i < s->numJugs ; i++){
        hash += s->arregloJugs[i];
    }
    return hash % capacity;
}

// Insertar un State en la tabla
void HashTable::insert(State *x){
    int h=hash(x);
    while (arr[h]!=nullptr){
        h=(h+1)%capacity;
    }
    arr[h]=x;
    number++;
}

// Buscar un State en la tabla
// Función de búsqueda para n Jarros, si lo encuentra retorna el State, si no retorna nullptr
State* HashTable::search(State *x){
    int h=hash(x);
    while (arr[h]!=nullptr){
        if (arr[h]->arregloJugs == x->arregloJugs){
            return arr[h];
        }
        h=(h+1)%capacity;
    }
    return nullptr;
}

// Verificar si un State está en la tabla
bool HashTable::contains(State *x){
    return search(x) != nullptr;
}

// Eliminar un State de la tabla hash
// Generalizado para n Jarros
void HashTable::remove(State *x){
    int h=hash(x);
    while (arr[h]!=nullptr){
        if (arr[h]->arregloJugs == x->arregloJugs){
            delete arr[h];
            arr[h]=nullptr;
            number--;
            return;
        }
        h=(h+1)%capacity;
    }
}

// Imprimir la tabla
void HashTable::print(){
    for (int i=0; i<capacity; i++){
        if (arr[i]!=nullptr){
            cout<<"["<<i<<"] ";
            arr[i]->print();
        }
    }
}
