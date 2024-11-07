#ifndef AVL_H
#define AVL_H

#include "AVLNode.h"

class AVL {
public:
    AVLNode* root;

    int getHeight(AVLNode* node);
    int getBalance(AVLNode* node);
    AVLNode* rightRotate(AVLNode* y);
    AVLNode* leftRotate(AVLNode* x);
    AVLNode* insertNode(AVLNode* node, State* state);
    AVLNode* findNode(AVLNode* node, State* state);
    void destroyTree(AVLNode* node);
    void deleteAllStates();
    void deleteAllStates(AVLNode* node);
    void printInOrder(AVLNode* node);

    // Helper functions for resizing without using containers
    void rehashNodes(AVLNode* node, AVL** newBuckets, int newCapacity);

    AVL() : root(nullptr) {}
    ~AVL();

    void insert(State* state);
    State* find(State* state);
    bool contains(State* state);
    AVLNode* getRoot() const { return root; }
    void print();
};

#endif