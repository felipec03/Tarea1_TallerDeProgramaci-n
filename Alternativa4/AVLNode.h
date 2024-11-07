#ifndef AVLNode_h
#define AVLNode_h

#include <algorithm>
#include "State.h"

struct AVLNode {
    AVLNode *left;
    AVLNode *right;

    State value;  
    int count;
    int height;

    AVLNode(const State& value);
    void updateValues();
    int balanceFactor();

    AVLNode* left_rotate();
    AVLNode* right_rotate();
};

#endif