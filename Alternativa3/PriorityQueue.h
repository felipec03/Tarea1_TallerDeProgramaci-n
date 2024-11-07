#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <iostream>
#include <string>
#include "State.h"

class PriorityQueue {
    public:
        // Atributos
        State **arr;
        int capacity;
        int number;
        int numJugs;

        // Métodos
        PriorityQueue(int n);
        PriorityQueue(int n, int numJugs);
        PriorityQueue();
        ~PriorityQueue();
        void push(State *x);
        State *pop();
        bool isEmpty();
        void bubbleUp(int i);
        void bubbleDown(int i);
        void swap(int i, int j);
};

#endif