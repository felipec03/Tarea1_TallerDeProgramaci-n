// AVL.cpp
#include "AVL.h"
#include <algorithm>

int AVL::getHeight(AVLNode* node) {
    if (node == nullptr) return 0;
    return node->height;
}

int AVL::getBalance(AVLNode* node) {
    if (node == nullptr) return 0;
    return getHeight(node->left) - getHeight(node->right);
}

AVLNode* AVL::rightRotate(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

AVLNode* AVL::leftRotate(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

AVLNode* AVL::insertNode(AVLNode* node, State* state) {
    if (node == nullptr) {
        return new AVLNode(state);
    }

    if (state->hash_value < node->state->hash_value) {
        node->left = insertNode(node->left, state);
    } else if (state->hash_value > node->state->hash_value) {
        node->right = insertNode(node->right, state);
    } else {
        if (state->equals(node->state)) {
            return node; // State already exists
        } else {
            // Handle collision by comparing additional data
            node->right = insertNode(node->right, state);
        }
    }

    node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;
    int balance = getBalance(node);

    // Left Left Case
    if (balance > 1 && state->hash_value < node->left->state->hash_value)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && state->hash_value > node->right->state->hash_value)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && state->hash_value > node->left->state->hash_value) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && state->hash_value < node->right->state->hash_value) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

AVLNode* AVL::findNode(AVLNode* node, State* state) {
    if (node == nullptr)
        return nullptr;

    if (state->hash_value < node->state->hash_value)
        return findNode(node->left, state);
    else if (state->hash_value > node->state->hash_value)
        return findNode(node->right, state);
    else {
        if (state->equals(node->state))
            return node;
        else
            return findNode(node->right, state); // Continue searching
    }
}

void AVL::insert(State* state) {
    root = insertNode(root, state);
}

State* AVL::find(State* state) {
    AVLNode* node = findNode(root, state);
    if (node != nullptr) {
        return node->state;
    }
    return nullptr;
}

bool AVL::contains(State* state) {
    return find(state) != nullptr;
}

void AVL::destroyTree(AVLNode* node) {
    if (node) {
        destroyTree(node->left);
        destroyTree(node->right);
        // Do not delete node->state here
        delete node;
    }
}

void AVL::deleteAllStates() {
    deleteAllStates(root);
}

void AVL::deleteAllStates(AVLNode* node) {
    if (node) {
        deleteAllStates(node->left);
        deleteAllStates(node->right);
        delete node->state; // Delete the State object here
    }
}

AVL::~AVL() {
    destroyTree(root);
}

void AVL::rehashNodes(AVLNode* node, AVL** newBuckets, int newCapacity) {
    if (node == nullptr) return;

    rehashNodes(node->left, newBuckets, newCapacity);

    State* s = node->state;
    int h = (int)(s->hash_value % newCapacity);
    if (newBuckets[h] == nullptr) {
        newBuckets[h] = new AVL();
    }
    newBuckets[h]->insert(s);

    rehashNodes(node->right, newBuckets, newCapacity);
}

void AVL::printInOrder(AVLNode* node) {
    if (node == nullptr) return;
    printInOrder(node->left);
    node->state->print();
    printInOrder(node->right);
}

void AVL::print() {
    printInOrder(root);
    std::cout << std::endl;
}