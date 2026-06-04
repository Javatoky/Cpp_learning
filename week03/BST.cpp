#include "BST.h"

BST::Node::Node(int v): value(v), left(nullptr), right(nullptr) {}

BST::BST(): root(nullptr), size(0) {}

BST::~BST() {
    release(root);
}

BST::BST(const BST& other): root(nullptr), size(0) {
    if (other.size == 0) {
        return;
    }

    int length = 0;
    int* values = other.preOrder(length);
    for (int i = 0; i < length; i++) {
        insert(values[i]);
    }

    delete[] values;
}

BST& BST::operator=(const BST& other) {
    if (this == &other) {
        return *this;
    }

    clear();

    if (other.size == 0) {
        return *this;
    }

    int length = 0;
    int* values = other.preOrder(length);
    for (int i = 0; i < length; i++) {
        insert(values[i]);
    }

    delete[] values;
    return *this;
}

int BST::getSize() const {
    return size;
}

bool BST::isEmpty() const {
    return size == 0;
}

void BST::release(Node* pointer){
    if (pointer == nullptr) {
        return;
    }

    release(pointer -> left);
    release(pointer -> right);

    delete pointer;
    return;
}

bool BST::insertIntoNode(Node*& pointer, int value) {
    //递归插入，递归深度低适用
    if (pointer == nullptr) {
        pointer = new Node(value);
        return true;
    }

    if (value < pointer -> value) {
        return insertIntoNode(pointer -> left, value);
    }else if (value > pointer -> value) {
        return insertIntoNode(pointer -> right,value);
    }

    return false;
}

bool BST::insert(int value) {
    if (insertIntoNode(root, value)) {
        size++;
        return true;
    }
    return false;
}

int BST::removeHelper(const Node* pointer) const {
    while(pointer->right != nullptr) {
        pointer = pointer->right;
    }

    return pointer->value;
}

bool BST::removeFromNode(Node*& pointer, int value) {
    if (pointer == nullptr) {
        return false;
    }

    if (value < pointer->value) {
        return removeFromNode(pointer->left, value);
    } else if (value > pointer->value) {
        return removeFromNode(pointer->right, value);
    } else {
        if (pointer->left != nullptr && pointer->right != nullptr) {
            int maxOfLeft = removeHelper(pointer->left);
            pointer->value = maxOfLeft;
            return removeFromNode(pointer->left, maxOfLeft);
        } else {
            Node* temp = nullptr;
            if (pointer->left != nullptr) {
                temp = pointer->left;
            } else {
                temp = pointer->right;
            }

            delete pointer;
            pointer = temp;
            return true;
        }
    }
}

bool BST::remove(int value) {
    if (removeFromNode(root, value)) {
        size--;
        return true;
    }

    return false;
}

bool BST::contains(int value) const {
    const Node *pointer = root;
    
    while (pointer != nullptr) {
        if (value < pointer->value) {
            pointer = pointer->left;
        } else if (value > pointer->value) {
            pointer = pointer->right;
        } else {
            return true;
        }
    }

    return false;
}

bool BST::findMax(int& value) const {
    if (root == nullptr) {
        return false;
    }

    const Node* pointer = root;
    while(pointer->right != nullptr) {
        pointer = pointer->right;
    }

    value = pointer->value;
    return true;
}

bool BST::findMin(int& value) const {
    if (root == nullptr) {
        return false;
    }

    const Node* pointer = root;
    while(pointer->left != nullptr) {
        pointer = pointer->left;
    }

    value = pointer->value;
    return true;
}

void BST::preOrderVisitNode(const Node* pointer, int* arr, int& index) const {
    if (pointer == nullptr) {
        return;
    }

    arr[index++] = pointer->value;
    preOrderVisitNode(pointer->left, arr, index);
    preOrderVisitNode(pointer->right, arr, index);
}

int* BST::preOrder(int& length) const {
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

void BST::inOrderVisitNode(const Node* pointer, int* arr, int& index) const {
    if (pointer == nullptr) {
        return;
    }

    inOrderVisitNode(pointer->left, arr, index);
    arr[index++] = pointer->value;
    inOrderVisitNode(pointer->right, arr, index);
}

int* BST::inOrder(int& length) const {
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

void BST::postOrderVisitNode(const Node* pointer, int* arr, int& index) const {
    if (pointer == nullptr) {
        return;
    }

    postOrderVisitNode(pointer->left, arr, index);
    postOrderVisitNode(pointer->right, arr, index);
    arr[index++] = pointer->value;
}

int* BST::postOrder(int& length) const {
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

void BST::clear() {
    release(root);
    root = nullptr;
    size = 0;
}
