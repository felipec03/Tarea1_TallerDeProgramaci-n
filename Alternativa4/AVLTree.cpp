#include "AVLTree.h"
#include <iostream>

AVLTree::AVLTree() : _size(0), root(nullptr) {}

AVLTree::~AVLTree() {
    clear(root);
}

void AVLTree::clear() {
    clear(root);
    root = nullptr;
    _size = 0;
}

void AVLTree::clear(AVLNode* node) {
    if (node) {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}

void AVLTree::insert(const State& value) {
    root = insert(root, value);
    _size++;
}

AVLNode* AVLTree::insert(AVLNode* node, const State& value) {
    if (!node)
        return new AVLNode(value);

    if (value < node->value)
        node->left = insert(node->left, value);
    else if (value > node->value)
        node->right = insert(node->right, value);
    else
        return node;  // Duplicate values are not inserted

    node->updateValues();
    return balance(node);
}

void AVLTree::erase(const State& value) {
    root = erase(root, value);
}

AVLNode* AVLTree::erase(AVLNode* node, const State& value) {
    if (!node)
        return nullptr;

    if (value < node->value) {
        node->left = erase(node->left, value);
    } else if (value > node->value) {
        node->right = erase(node->right, value);
    } else {
        if (!node->left || !node->right) {
            AVLNode* temp = node->left ? node->left : node->right;
            if (!temp) {
                temp = node;
                node = nullptr;
            } else {
                *node = *temp;  // Move contents
            }
            delete temp;
            _size--;
        } else {
            AVLNode* temp = node->right;
            while (temp->left)
                temp = temp->left;
            node->value = temp->value;
            node->right = erase(node->right, temp->value);
        }
    }

    if (!node)
        return node;

    node->updateValues();
    return balance(node);
}

AVLNode* AVLTree::balance(AVLNode* node) {
    int bf = node->balanceFactor();

    if (bf > 1 && node->left->balanceFactor() >= 0)
        return node->right_rotate();

    if (bf > 1 && node->left->balanceFactor() < 0) {
        node->left = node->left->left_rotate();
        return node->right_rotate();
    }

    if (bf < -1 && node->right->balanceFactor() <= 0)
        return node->left_rotate();

    if (bf < -1 && node->right->balanceFactor() > 0) {
        node->right = node->right->right_rotate();
        return node->left_rotate();
    }

    return node;
}

bool AVLTree::empty() const {
    return _size == 0;
}

int AVLTree::size() const {
    return _size;
}

bool AVLTree::find(const State& value) const {
    AVLNode* current = root;
    while (current) {
        if (current->value == value)
            return true;
        if (value < current->value)
            current = current->left;
        else
            current = current->right;
    }
    return false;
}

void AVLTree::display() {
    if (root)
        display(root, 0, 0);
}

void AVLTree::display(AVLNode* cur, int depth, int state) {
    if (cur->left)
        display(cur->left, depth + 1, -1);

    for (int i = 0; i < depth; ++i)
        std::cout << "    ";

    if (state == -1)
        std::cout << "┌──";
    else if (state == 1)
        std::cout << "└──";
    else
        std::cout << "";

    std::cout << cur->value.priority << std::endl;

    if (cur->right)
        display(cur->right, depth + 1, 1);
}