#include "Queue.h"

int main() {
    Queue *q = new Queue(3);
    cout << "number of elements: " << q->number_of_elements() << endl;
    State *s = new State(0, 0, nullptr, (char *) "");
    q->push(s);
    cout << "number of elements: " << q->number_of_elements() << endl;

    State *s1 = new State(3, 0, s, (char *) "llenar a0");
    q->push(s1);
    cout << "number of elements: " << q->number_of_elements() << endl;

    State *s2 = new State(3, 5, s1, (char *) "llenar a1");
    q->push(s2);
    cout << "number of elements: " << q->number_of_elements() << endl;

    State *s3 = new State(0, 5, s2, (char *) "vaciar a0");
    q->push(s3);
    cout << "number of elements: " << q->number_of_elements() << endl;

    State *s4 = new State(3, 2, s3, (char *) "trasvasar a1 a0");
    q->push(s4);
    cout << "number of elements: " << q->number_of_elements() << endl;

    State *s5 = new State(0, 2, s4, (char *) "vaciar a0");
    q->push(s5);
    cout << "number of elements: " << q->number_of_elements() << endl;

    State *s6 = new State(2, 0, s5, (char *) "trasvasar a1 a0");
    q->push(s6);
    cout << "number of elements: " << q->number_of_elements() << endl;

    State *s7 = new State(2, 5, s6, (char *) "llenar a1");
    q->push(s7);
    cout << "number of elements: " << q->number_of_elements() << endl;

    State *s8 = new State(3, 4, s7, (char *) "trasvasar a1 a0");
    q->push(s8);
    cout << "number of elements: " << q->number_of_elements() << endl;

    State *s9 = new State(4, 3, s8, (char *) "trasvasar a1 a0");
    q->push(s9);
    cout << "number of elements: " << q->number_of_elements() << endl;

    State *s10 = new State(0, 7, s9, (char *) "llenar a1");
    q->push(s10);
    cout << "number of elements: " << q->number_of_elements() << endl;

    State *s11 = new State(3, 4, s10, (char *) "trasvasar a1 a0");
    q->push(s11);
    cout << "number of elements: " << q->number_of_elements() << endl;

    State *s12 = new State(4, 0, s11, (char *) "vaciar a1");
    q->push(s12);
    cout << "number of elements: " << q->number_of_elements() << endl;

    State *s13 = new State(4, 3, s12, (char *) "trasvasar a1 a0");
    q->push(s13);

    cout << "initial state" << endl;
    cout << "number of elements: " << q->number_of_elements() << endl;

    cout << "poping elements" << endl;
    State *s14 = q->pop();
    s14->print();
    cout << "number of elements: " << q->number_of_elements() << endl;

    cout << "poping elements" << endl;
    State *s15 = q->pop();
    s15->print();
    cout << "number of elements: " << q->number_of_elements() << endl;

    cout << "poping elements" << endl;
    State *s16 = q->pop();
    s16->print();
    cout << "number of elements: " << q->number_of_elements() << endl;
    


}