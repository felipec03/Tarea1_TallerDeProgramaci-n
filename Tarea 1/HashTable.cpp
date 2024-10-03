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

// Función de hash para un State
int HashTable::hash(State *x){
    return (x->a0+x->a1)%capacity;
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
State* HashTable::search(State *x){
    int h=hash(x);
    while (arr[h]!=nullptr){
        if (arr[h]->a0==x->a0 && arr[h]->a1==x->a1){
            return arr[h];
        }
        h=(h+1)%capacity;
    }
    return nullptr;
}

// Eliminar un State de la tabla
void HashTable::remove(State *x){
    int h=hash(x);
    while (arr[h]!=nullptr){
        if (arr[h]->a0==x->a0 && arr[h]->a1==x->a1){
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

