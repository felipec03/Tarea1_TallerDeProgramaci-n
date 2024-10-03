#include "Queue.h"
Queue::Queue(int size) {
    this->size = size;
    arr = new State*[size];
    back = -1;
    front = -1;
}

int Queue::number_of_elements() {
    if (back == -1) {
        return 0;
    } else if (back >= front) {
        return back - front + 1;
    } else {
        return size - front + back + 1;
    }
}

void Queue::push(State* s) {
    if (back == -1) { // si la cola esta vacia
        back = 0;
        front = 0;
    } else if (number_of_elements()==size) { // si la cola esta llena
        State **new_arr = new State*[size*2];
        if (front <= back) {
            for(int i = front; i <= back; i++) {
                new_arr[i] = arr[i];
            }
            front=0;
            back=size-1;
        } else {
            for(int i = front; i < size; i++) {
                new_arr[i] = arr[i];
            }
            for(int i = 0; i <= back; i++) {
                new_arr[i+size] = arr[i];
            }
            front=0;
            back=size-1;
        }
        delete[] arr;
        arr = new_arr;
        size = size*2;
        back = (back + 1) % size;
    } else { // si la cola no esta llena
        back = (back + 1) % size;
    }

    arr[back] = s;
//    cout << "push state parent : " << s->parent << endl;
//    cout << "push copy state ptr : " << arr[back]->parent << endl;
}

State* Queue::pop() {
    if (number_of_elements() == 0) {
        return nullptr;
    } else {
        State *s = arr[front];
        if (front == back) {// caso en que solo hay un elemento
            front = -1;
            back = -1;
        } else {
            front = (front + 1) % size;
        }
//        cout << "pop state parent : " << s->parent << endl;
        return s;
    }
}

bool Queue::is_empty() {
    return number_of_elements() == 0;
}

bool Queue::contains(State* s) {
    if (number_of_elements() == 0) {
        return false;
    }
    if (front <= back) {
        for(int i = front; i <= back; i++) {
            if (arr[i]->a0 == s->a0 && arr[i]->a1 == s->a1) {
                return true;
            }
        }
    } else {
        for(int i = front; i < size; i++) {
            if (arr[i]->a0 == s->a0 && arr[i]->a1 == s->a1) {
                return true;
            }
        }
        for(int i = 0; i <= back; i++) {
            if (arr[i]->a0 == s->a0 && arr[i]->a1 == s->a1) {
                return true;
            }
        }
    }

    return false;
}
