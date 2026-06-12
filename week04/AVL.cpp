#include "AVL.h"

AVL::Node::Node(int value): value(value), height(1), left(nullptr), right(nullptr) {}

AVL::AVL(): root(nullptr), size(0) {}

AVL::~AVL() {
    release(root);
}

int AVL::getHeight(const Node* pointer) const {
    if (pointer == nullptr) {
        return 0;
    }

    return pointer->height;
}

void AVL::updateHeight(Node* pointer) {
    int rightOfHeight = getHeight(pointer->right);
    int leftOfHeight = getHeight(pointer->left);

    pointer->height = rightOfHeight >= leftOfHeight ? rightOfHeight + 1 : leftOfHeight + 1;
}

int AVL::getBalanceFactor(const Node* pointer) const {
    if (pointer == nullptr) {
        return 0;
    }

    return getHeight(pointer->left) - getHeight(pointer->right);
}

void AVL::rotateLeft(Node*& pointer) {
    if (pointer == nullptr) {
        return;
    }

    if (getBalanceFactor(pointer) != -2 || pointer->right->right == nullptr) {      //待定
        return;
    }

    Node* temp = pointer;           
    pointer = pointer->right;       
    temp->right = pointer->left;    
    pointer->left = temp;           

    updateHeight(pointer->left);
    updateHeight(pointer);          
}

void AVL::rotateRight(Node*& pointer) {
    if (pointer == nullptr) {
        return;
    }

    if (getBalanceFactor(pointer) != 2 || pointer->left->left == nullptr) {
        return;
    }

    Node* temp = pointer;
    pointer = pointer->left;
    temp->left = pointer->right;
    pointer->right = temp;

    updateHeight(pointer->right);
    updateHeight(pointer);
}

void AVL::release(Node* pointer) {
    if (pointer == nullptr) {
        return;
    }

    release(pointer->left);
    release(pointer->right);
    
    delete pointer;
}

void AVL::clear() {
    release(root);

    root = nullptr;
    size = 0;
}

bool AVL::testRotateLeft() {
    Node* node = new Node(1);
    node->right = new Node(2);
    node->right->right = new Node(3);

    updateHeight(node->right->right);
    updateHeight(node->right);
    updateHeight(node);

    int bf = getBalanceFactor(node);
    bool result = false;
    if (bf <= -2) {
        rotateLeft(node);
        if (node->value == 2 && node->left->value == 1 && node->right->value == 3) {
            if (node->height == 2 && node->left->height == 1 && node->right->height == 1) {
                result = true;
            }
        }
    }

    release(node);
    return result;
}

