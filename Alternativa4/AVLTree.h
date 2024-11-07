#ifndef AVLTree_h
#define AVLTree_h

#include "AVLNode.h"

class AVLTree {
public:
    int _size;
    AVLNode* root;

    AVLTree();
    ~AVLTree();

    void insert(const State& value);
    void erase(const State& value);
    void clear();
    bool empty() const;
    int size() const;
    bool find(const State& value) const;
    void display();

    AVLNode* insert(AVLNode* node, const State& value);
    AVLNode* erase(AVLNode* node, const State& value);
    AVLNode* balance(AVLNode* node);

    void clear(AVLNode* node);
    void display(AVLNode* cur, int depth = 0, int state = 0);
};

#endif