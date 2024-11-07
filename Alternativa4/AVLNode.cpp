#include "AVLNode.h"

AVLNode::AVLNode(const State& value)
    : left(nullptr), right(nullptr), value(value), count(1), height(1) {}
    
void AVLNode::updateValues() {
    count = (left ? left->count : 0) + (right ? right->count : 0) + 1;
    height = std::max(left ? left->height : 0, right ? right->height : 0) + 1;
}

int AVLNode::balanceFactor() {
    return (left ? left->height : 0) - (right ? right->height : 0);
}

AVLNode* AVLNode::left_rotate() {
    AVLNode* R = right;
    right = R->left;
    R->left = this;

    this->updateValues();
    R->updateValues();

    return R;
}

AVLNode* AVLNode::right_rotate() {
    AVLNode* L = left;
    left = L->right;
    L->right = this;

    this->updateValues();
    L->updateValues();

    return L;
}