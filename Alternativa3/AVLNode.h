#ifndef AVLNODE_H
#define AVLNODE_H

#include "State.h"

class AVLNode {
public:
    State* state;
    AVLNode* left;
    AVLNode* right;
    int height;

    AVLNode(State* state) : state(state), left(nullptr), right(nullptr), height(1) {}
};

#endif