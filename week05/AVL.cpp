#include "AVL.h"
#include<iostream>

AVL::Node::Node(int value): value(value), height(1), left(nullptr), right(nullptr) {}

AVL::AVL(): root(nullptr), size(0), leftRotationCount(0), rightRotationCount(0), rebalanceCount(0) {}

AVL::~AVL() {
    release(root);
}

AVL::Node* AVL::cloneNode(const Node* src) {
    if (src == nullptr) {
        return nullptr;
    }
    
    Node* pointer = new Node(src->value);
    pointer->height = src->height;

    pointer->left = cloneNode(src->left);
    pointer->right = cloneNode(src->right);

    return pointer;
}

AVL::AVL(const AVL& other): root(nullptr), size(0), leftRotationCount(0), rightRotationCount(0), rebalanceCount(0) {
    root = cloneNode(other.root);
    size = other.size;
}

AVL& AVL::operator=(const AVL& other) {
    if (this == &other) {
        return *this;
    }

    clear();
    root = cloneNode(other.root);
    size = other.size;
    leftRotationCount = 0;
    rightRotationCount = 0;
    rebalanceCount = 0;

    return *this;
}

int AVL::getHeight(const Node* pointer) const {
    if (pointer == nullptr) {
        return 0;
    }

    return pointer->height;
}

void AVL::updateHeight(Node* pointer) {
    if (pointer == nullptr) {
        return;
    }

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
        return ;
    }

    if (pointer->right == nullptr) {
        return;
    }

    leftRotationCount++;

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

    if (pointer->left == nullptr) {
        return;
    }

    rightRotationCount++;

    Node* temp = pointer;
    pointer = pointer->left;
    temp->left = pointer->right;
    pointer->right = temp;

    updateHeight(pointer->right);
    updateHeight(pointer);
}

bool AVL::isEmpty() const {
    return size == 0;
}

int AVL::getSize() const {
    return size;
}

void AVL::rotateAsNeeded(Node*& pointer) {
    int bf = getBalanceFactor(pointer);
    if (bf == 2) {
        rebalanceCount++;

        int bfOfLeft = getBalanceFactor(pointer->left);
        if (bfOfLeft >= 0) {
            rotateRight(pointer);
        } else {
            rotateLeft(pointer->left);
            rotateRight(pointer);
        }
    } else if (bf == -2) {
        rebalanceCount++;

        int bfOfRight = getBalanceFactor(pointer->right);
        if (bfOfRight <= 0) {
            rotateLeft(pointer);
        } else {
            rotateRight(pointer->right);
            rotateLeft(pointer);
        }
    }
}

bool AVL::insertIntoNode(Node*& pointer, int value) {
    if (pointer == nullptr) {
        pointer = new Node(value);
        return true;
    }

    if (value == pointer->value) {
        return false;
    }
    
    bool result = false;
    if (value < pointer -> value) {
        result = insertIntoNode(pointer -> left, value);
    } else {
        result = insertIntoNode(pointer -> right, value);
    }

    if (!result) {
        return false;
    }

    updateHeight(pointer);
    rotateAsNeeded(pointer);

    return result;
}

bool AVL::insert(int value) {
    if (insertIntoNode(root, value)) {
        size++;
        return true;
    }

    return false;
}

bool AVL::contains(int value) const {
    const Node* pointer = root;
    while (pointer != nullptr) {
        if (value == pointer->value) {
            return true;
        } else if (value < pointer->value) {
            pointer = pointer->left;
        } else {
            pointer = pointer->right;
        }
    }

    return false;
}

int AVL::findSubTreeMax(const Node* pointer) const {
    while(pointer->right != nullptr) {
        pointer = pointer->right;
    }

    return pointer->value;
}

bool AVL::removeFromNode(Node*& pointer, int value) {
    if (pointer == nullptr) {
        return false;
    }

    bool result = false;
    if (value < pointer->value) {
        result = removeFromNode(pointer->left, value);
    } else if (value > pointer->value) {
        result = removeFromNode(pointer->right, value);
    } else {
        if (pointer->left != nullptr && pointer->right != nullptr) {
            int maxOfLeft = findSubTreeMax(pointer->left);
            pointer->value = maxOfLeft;
            result = removeFromNode(pointer->left, maxOfLeft);
        } else {
            Node* temp = nullptr;
            if (pointer->left != nullptr) {
                temp = pointer->left;
            } else {
                temp = pointer->right;
            }

            delete pointer;
            pointer = temp;
            result = true;
        }
    }

    if (!result) {
        return false;
    }

    updateHeight(pointer);
    rotateAsNeeded(pointer);

    return true;
}

bool AVL::remove(int value) {
    leftRotationCount = 0;
    rightRotationCount = 0;
    rebalanceCount = 0;

    if (removeFromNode(root, value)) {
        size--;
        return true;
    }

    return false;
}

bool AVL::checkNodeHeight(const Node* pointer) const {
    if (pointer == nullptr) {
        return getHeight(pointer) == 0;
    }

    if (!(checkNodeHeight(pointer->left) && checkNodeHeight(pointer->right))) {
        return false;
    }

    int heightOfLeft = getHeight(pointer->left);
    int heightOfRight = getHeight(pointer->right);

    return getHeight(pointer) == (heightOfLeft >= heightOfRight ? heightOfLeft + 1 : heightOfRight + 1);
}

bool AVL::validateNodeBalanceFactor(const Node* pointer) const {
    if (pointer == nullptr) {
        return true;
    }
    
    if (!(validateNodeBalanceFactor(pointer->left) && validateNodeBalanceFactor(pointer->right))) {
        return false;
    }

    int bf = getBalanceFactor(pointer);
    if (bf > 1 || bf < -1) {
        return false;
    }

    return true;
}

bool AVL::verifyInOrder() const {
    if (root == nullptr) {
        return true;
    }

    int length = 0;
    int* arr = inOrder(length);
    bool isBST = true;
    int temp = arr[0];
    for (int i = 1; i < length; i++) {
        if (temp >= arr[i]) {
            isBST = false;
            break;
        }

        temp = arr[i];
    }

    delete[] arr;
    return isBST;
}

bool AVL::isAVLTree() const {
    if (!checkNodeHeight(root)) {
        return false;
    }

    return validateNodeBalanceFactor(root) && verifyInOrder();
}

int AVL::getRotationCount() const {
    return leftRotationCount + rightRotationCount;
}

int AVL::getRebalanceCount() const {
    return rebalanceCount;
}

void AVL::preOrderVisitNode(const Node* pointer, int* arr, int& index) const {
    if (pointer == nullptr) {
        return;
    }

    arr[index++] = pointer->value;
    preOrderVisitNode(pointer->left, arr, index);
    preOrderVisitNode(pointer->right, arr, index);
}

int* AVL::preOrder(int& length) const {
    if (size == 0) {
        length = 0;
        return nullptr;
    }

    int* arr = new int[size];
    int index = 0;
    preOrderVisitNode(root, arr, index);

    length = size;
    return arr;
}

void AVL::inOrderVisitNode(const Node* pointer, int* arr, int& index) const {
    if (pointer == nullptr) {
        return;
    }

    inOrderVisitNode(pointer->left, arr, index);
    arr[index++] = pointer->value;
    inOrderVisitNode(pointer->right, arr, index);
}

int* AVL::inOrder(int& length) const {
    if (size == 0) {
        length = 0;
        return nullptr;
    }

    int* arr = new int[size];
    int index = 0;
    inOrderVisitNode(root, arr, index);

    length = size;
    return arr;
}

void AVL::postOrderVisitNode(const Node* pointer, int* arr, int& index) const {
    if (pointer == nullptr) {
        return;
    }

    postOrderVisitNode(pointer->left, arr, index);
    postOrderVisitNode(pointer->right, arr, index);
    arr[index++] = pointer->value;
}

int* AVL::postOrder(int& length) const {
    if (size == 0) {
        length = 0;
        return nullptr;
    }

    int* arr = new int[size];
    int index = 0;
    postOrderVisitNode(root, arr, index);

    length = size;
    return arr;
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
    if (bf == -2) {
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

bool AVL::testRotateRight() {
    Node* node = new Node(3);
    node->left = new Node(2);
    node->left->left = new Node(1);

    updateHeight(node->left->left);
    updateHeight(node->left);
    updateHeight(node);

    int bf = getBalanceFactor(node);
    bool result = false;
    if (bf == 2) {
        rotateRight(node);
        if (node->value == 2 && node->left->value == 1 && node->right->value == 3) {
            if (node->height == 2 && node->left->height == 1 && node->right->height == 1) {
                result = true;
            }
        }
    }

    release(node);
    return result;
}

bool AVL::testIsAVLTree() {
    root = new Node(2);
    root->left = new Node(1);
    root->right = new Node(3);
    size = 3;

    updateHeight(root->left);
    updateHeight(root->right);
    updateHeight(root);

    bool result1 = isAVLTree();
    clear();

    root = new Node(3);
    root->left = new Node(2);
    root->left->left = new Node(1);

    updateHeight(root->left->left);
    updateHeight(root->left);
    updateHeight(root);
    size = 3;

    bool result2 = isAVLTree();
    clear();

    bool result3 = isAVLTree();

    return result1 && !result2 && result3;
}
