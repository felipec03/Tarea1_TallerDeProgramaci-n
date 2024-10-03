#include "Heap.h"


int main() {
    Heap h(2);

    State* s1 = new State(1, 2, nullptr, (char *)"op1");
    s1->priority = 5;
    State* s2 = new State(3, 4, nullptr, (char *)"op2");
    s2->priority = 1;   

    State* s3 = new State(5, 6, nullptr, (char *)"op3");
    s3->priority = 3;
    State* s4 = new State(7, 8, nullptr, (char *)"op4");
    s4->priority = 2;
    State* s5 = new State(9, 10, nullptr,(char *) "op5");
    s5->priority = 4;

    h.push(s1);
    h.push(s2);
    h.push(s3);
    h.push(s4);
    h.push(s5);

    for (int i = 0; i < h.number; i++) {
        cout << h.arr[i]->priority << endl;
    }
    cout << "----------------" << endl; 
    while (h.number > 0) {
        State* s = h.pop();
        cout << s->priority << endl;
        delete s;
    }
    
}