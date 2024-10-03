#include "Queue.h"

int main()
{
    Queue *q = new Queue(2);

    State *s = new State(0,0,nullptr, "init");
    q->push(s);
    State *s1 = new State(3,0, s, "fill a0");
    q->push(s1);
    State *s2 = new State(3,5, s1, "fill a1");
    q->push(s2);
    State *s3  = new State(0,5,s2, "pour a0");
    q->push(s3);

    s3->print();
    cout << "Tamaño cola: " << q->numberElements() << endl;
    cout << "--------------------------------------------------" << endl;
    while(q->numberElements() > 0){
        State* ss = q->pop();
        ss->print();
    }
}
