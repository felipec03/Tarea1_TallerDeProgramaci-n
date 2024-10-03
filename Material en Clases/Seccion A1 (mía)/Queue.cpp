#include "Queue.h"

// Constructor para cola vacía
Queue::Queue(){
    array = nullptr;
    front = -1;
    back = -1;
    size = 0;
}

// Constructor para cola vacía de tamaño definido n
Queue::Queue(int n){
    array = new State*[n];      // Arreglo de tamaño definido para n elementos
    front = -1;                 // Convención: back = front = -1
    back = -1;
    size = n;
}

// Se puede hacer sin usar una comparación
int Queue::numberElements(){
    if (back == -1  && front == -1){
        return 0;
    }
    if(back >= front){
        return (back - front + 1);
    }
    return (size - front + back + 1);
}

State* Queue::pop(){
    // Si la cola está vacía
    if(front == -1){
        return nullptr;
    }
    else{
        State* s = array[front];
        if(numberElements() == 1){
            front = back = -1;
        }
        else if(front == size -1){
            front = 0;
        }
        else{
            front++;
        }
        return s;
    }
}

void Queue::push(State* s){

    // Queremos que esta estructura sea auto implementanble
    if(numberElements() == size){
        // Cambiar, no puede ser en la tarea.
        // Cantiad en el open y closed es variable.
        // Hay que encontrar manera de ampliar capacidad.
        State **arrTemp = new State*[2*size];
        // Copiamos el arreglo antiguo aquí

        // Copiar entre medio de ambos
        if(back >= front){
            for(int k=front; k <= back; k++){
                arrTemp[k-front] = array[k];
            }
        }
        // Copiar de front a size-1 y de 0 a back

        else{
            for (int k = front; k <=size-1; k++)
            {
                arrTemp[k-front] = array[k];
            }
            for (int k = 0; k<=back; k++){
                arrTemp[k + size - front] = array[k];
            }
        }
        front = 0;
        back = size-1;
        size = size*2;
        delete[] array;     // Idem a free en C.
        array = arrTemp;

    }

    // aquí ya corregimos cualquier posible falta de memoría.
    else{
        // Caso en que cola esté vacía
        if (front == -1 && back == -1){
            front = back = 0;
        }
        // Si el último está al final del arreglo
        else if (back == size -1){
            back = 0;
        }
        else{
            back++;
        }
        array[back] = s;
    }
    return;
}

bool Queue::find(State* s){
    // Es posible condensar el código, notar que if dentro del for es idéntico
    if (back == -1 && front == -1){
        return false;
    }
    if(back >= front){
        for(int k = front; k<=back; k++){
            if(array[k]->a0 == s->a0 && array[k]->a1 == s->a1){
                return true;
            }
        }
    }
    else{
        for(int k = front; k<=size-1; k++){
            if(array[k]->a0 == s->a0 && array[k]->a1 == s->a1){
                return true;
            }
        }
        for(int k = 0; k <=back; k++){
            if(array[k]->a0 == s->a0 && array[k]->a1 == s->a1){
                return true;
            }
        }
    }
    return false;
}

bool Queue::isEmpty(){
    return (front == -1 && back == -1);
}
