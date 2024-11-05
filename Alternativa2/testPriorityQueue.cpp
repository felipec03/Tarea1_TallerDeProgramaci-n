#include "PriorityQueue.cpp"

int main(){
    PriorityQueue* pq = new PriorityQueue(10);
    State* s = new State(nullptr, nullptr, nullptr, 0, nullptr, "");
    s->priority = 5;
    pq->push(s);
    s = new State(nullptr, nullptr, nullptr, 0, nullptr, "");
    s->priority = 3;
    pq->push(s);
    s = new State(nullptr, nullptr, nullptr, 0, nullptr, "");
    s->priority = 7;
    pq->push(s);
    s = new State(nullptr, nullptr, nullptr, 0, nullptr, "");
    s->priority = 1;
    pq->push(s);
    s = new State(nullptr, nullptr, nullptr, 0, nullptr, "");

    while (!pq->isEmpty()) {
        s = pq->pop();
        std::cout << s->priority << std::endl;
    }
    return 0;
}