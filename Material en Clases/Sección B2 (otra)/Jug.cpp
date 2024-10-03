#include "Jug.h"

Jug::Jug(State *initial_state) {
    open = new Queue(1000);
    closed = new Queue(1000);
    open->push(initial_state);
//    cout << "initial state ptr: " << initial_state << endl;
}


State* Jug::fill0(State *s) {
    if (s->a0 < 3) {
        return new State(3, s->a1, s, (char *) "llenar a0");
    } else {
        return nullptr;
    }
}

State* Jug::fill1(State *s) {
    if (s->a1 < 5) {
        return new State(s->a0, 5, s, (char *) "llenar a1");
    } else {
        return nullptr;
    }
}

State* Jug::empty0(State *s) {
    if (s->a0 > 0) {
        return new State(0, s->a1, s, (char *) "vaciar a0");
    } else {
        return nullptr;
    }
}

State* Jug::empty1(State *s) {
    if (s->a1 > 0) {
        return new State(s->a0, 0, s, (char *) "vaciar a1");
    } else {
        return nullptr;
    }
}

State* Jug::a0toa1(State *s) {
//    s->print();
    if ((s->a0 > 0) && (s->a1 < 5)) {
        int a = min(s->a0, 5 - s->a1);
        return new State(s->a0 - a, s->a1 + a, s, (char *) "trasvasar a0 a1");
    } else {
        return nullptr;
    }
}

State* Jug::a1toa0(State *s) {
    if ((s->a1 > 0) && (s->a0 < 3)) {
        int a = min(s->a1, 3 - s->a0);
        return new State(s->a0 + a, s->a1 - a, s, (char *) "trasvasar a1 a0");
    } else {
        return nullptr;
    }
}

State* Jug::solve() {
    while (open->number_of_elements() > 0) {
        State *state = open->pop();
//        cout << "pop state ptr: " << state << endl;
        closed->push(state);
        if (state->is_goal()) {
            return state;
        }

        State* e1 = fill0(state);
        if (e1 != nullptr && !closed->contains(e1) && !open->contains(e1)) {
            e1->parent=state;
            e1->op=(char *)"llenar a0";
            open->push(e1);
//            cout << "llenar a0" << endl;
        } else {
            if (e1 != nullptr)
                delete e1;
        }

        State* e2 = fill1(state);
        if (e2 != nullptr && !closed->contains(e2) && !open->contains(e2)) {
            e2->parent=state;
            e2->op=(char *)"llenar a1";
            open->push(e2);
//            cout << "llenar a1" << endl;
        } else {
            delete e2;
        }

        State* e3 = empty0(state);
        if (e3 != nullptr && !closed->contains(e3) && !open->contains(e3)) {
            e3->parent=state;
            e3->op=(char *)"vaciar a0";
            open->push(e3);
//            cout << "vaciar a0" << endl;
        } else {
            delete e3;
        }

        State* e4 = empty1(state);
        if (e4 != nullptr && !closed->contains(e4) && !open->contains(e4)) {
            e4->parent=state;
            e4->op=(char *)"vaciar a1";
            open->push(e4);
//            cout << "vaciar a1" << endl;
        } else {
            delete e4;
        }   

        State* e5 = a0toa1(state);
        if (e5 != nullptr && !closed->contains(e5) && !open->contains(e5)) {
            e5->parent=state;
            e5->op=(char *)"trasvasar a0 a1";
            open->push(e5);
//            cout << "trasvasar a0 a1" << endl;
        } else {
            delete e5;
        }   

        State* e6 = a1toa0(state);
        if (e6 != nullptr && !closed->contains(e6) && !open->contains(e6)) {
            e6->parent=state;   
            e6->op=(char *)"trasvasar a1 a0";
            open->push(e6);
//            cout << "trasvasar a1 a0" << endl;
        } else {
            delete e6;
        }

    }
    return nullptr;
}