#include<iostream>
#include "AVL.h"

void printIsAVLTree(const AVL& avl) {
    if (avl.isAVLTree()) {
        std::cout << "Successful!" << std::endl;
    } else {
        std::cout << "Failed!" << std::endl;
    }
    std::cout << "\n" << std::endl;
}

void printValuesOfTreeInOrder(const AVL& avl) {
    if (avl.isEmpty()) {
        std::cout << "It is an empty tree." << std::endl;
        return;
    }

    int length, *arr;
    arr = avl.inOrder(length);
    
    for (int i = 0; i < length; i++) {
        std::cout << arr[i] << std::endl;
    }
    std::cout << "\n" <<std::endl;

    delete[] arr;
}

void validateConstruction(const AVL& a, const AVL& b) {
    if(a.isEmpty() && b.isEmpty()) {
        std::cout << "Passed!(Both of them are empty.)" << std::endl;
        return;
    }

    bool result = false;
    if (b.isAVLTree()) {
        int lengthOfA, lengthOfB;
        int* arrayOfA = a.preOrder(lengthOfA);
        int* arrayOfB = b.preOrder(lengthOfB);

        if (lengthOfA == lengthOfB) {
            result = true;
            for (int i = 0; i < lengthOfA; i++) {
                if (arrayOfA[i] != arrayOfB[i]) {
                    result = false;
                    break;
                }
            }
        }

        delete[] arrayOfA;
        delete[] arrayOfB;
    }

    if (result) {
        std::cout << "Passed!" << std::endl;
    } else {
        std::cout << "Failed!" << std::endl;
    }
}

bool testIsAVLTree() {
    std::cout << "Test: (function) isAVLTree : " << std::endl;
    AVL avl;

    if (!avl.isAVLTree()) {
        std::cout << "Failed!" << std::endl;
        return false;
    }

    if (avl.testIsAVLTree()) {
        std::cout << "Successful!" << std::endl;
    } else {
        std::cout << "Failed!" << std::endl;
        return false;
    }
    std::cout << "\n" <<std::endl;
    return true;
}

void testRotateLeft() {
    std::cout << "The result of the test of rotateLeft:" << std::endl;
    AVL avl;
    if (avl.testRotateLeft()) {
        std::cout << "Pass" << std::endl;
    } else {
        std::cout << "Failed" << std::endl;
    }
    std::cout << "\n" <<std::endl;
}

void testRotateRight() {
    std::cout << "The result of the test of rotateRight:" << std::endl;
    AVL avl;

    if (avl.testRotateRight()) {
        std::cout << "Pass" <<std::endl;
    } else {
        std::cout << "Failed" <<std::endl;
    }
    std::cout << "\n" <<std::endl;
}

void testInsert() {
    std::cout << "Test: LL formation after insertion: " << std::endl;
    AVL tree1;
    tree1.insert(3);
    tree1.insert(2);
    tree1.insert(1);
    printIsAVLTree(tree1);

    std::cout << "Test: LR formation after insertion: " << std::endl;
    AVL tree2;
    tree2.insert(3);
    tree2.insert(1);
    tree2.insert(2);
    printIsAVLTree(tree2);

    std::cout << "Test: RR formation after insertion: " << std::endl;
    AVL tree3;
    tree3.insert(1);
    tree3.insert(2);
    tree3.insert(3);
    printIsAVLTree(tree3);

    std::cout << "Test: RL formation after insertion: " << std::endl;
    AVL tree4;
    tree4.insert(1);
    tree4.insert(3);
    tree4.insert(2);
    printIsAVLTree(tree4);
}

void testCopyConstructor() {
    AVL a;
    int arr[] = {5,3,7,2,4,6,8};
    for (int i = 0; i < 7; i++) {
        a.insert(arr[i]);
    }

    AVL b(a);
    std::cout << "b has copied a." << std::endl;

    std::cout << "Validate the structure of two trees:" << std::endl;
    validateConstruction(a, b);

    a.insert(9);
    std::cout << "Insert 9 into a, the values of a:" << std::endl;
    printValuesOfTreeInOrder(a);
    std::cout << "Now, The values of b: (expected: 2,3,4,5,6,7,8)" << std::endl;
    printValuesOfTreeInOrder(b);

    a.clear();
    if (a.isEmpty()) {
        std::cout << "Now, a is empty." << std::endl;
    }
    std::cout << "The Values of b: (expected: 2,3,4,5,6,7,8)" << std::endl;
    printValuesOfTreeInOrder(b);
}

void testCopyAssignmentOperator() {
    std::cout << "Test: copy assignment operator:  " << std::endl;
    AVL a;
    int arr1[] = {7,4,10,2,6,8,12};
    for (int i = 0; i < 7; i++) {
        a.insert(arr1[i]);
    }
    std::cout << "The Values of a: " << std::endl;
    printValuesOfTreeInOrder(a);

    AVL b;
    int arr2[] = {5,3,7,2,4,6,8};
    for (int i = 0; i < 7; i++) {
        b.insert(arr2[i]);
    }
    std::cout << "The Values of b: " << std::endl;
    printValuesOfTreeInOrder(b);

    b = a;
    std::cout << "b has copied a." << std::endl;

    std::cout << "Validate the structure of two trees:" << std::endl;
    validateConstruction(a, b);
    
    a.insert(1);
    std::cout << "Insert 1 into a, the values of a: " << std::endl;
    printValuesOfTreeInOrder(a);
    std::cout << "Now, The values of b: (expected: 2,4,6,7,8,10,12)" << std::endl;
    printValuesOfTreeInOrder(b);

    a.clear();
    if (a.isEmpty()) {
        std::cout << "Now, a is empty." << std::endl;
    }
    std::cout << "The Values of b: (expected: 2,4,6,7,8,10,12)" << std::endl;
    printValuesOfTreeInOrder(b);

    std::cout << "Validate self-assignment:" << std::endl;
    b = b;
    std::cout << "The Values of b after self-assignment: (expected: 2,4,6,7,8,10,12)" << std::endl;
    printValuesOfTreeInOrder(b);
}

int main() {
    if (!testIsAVLTree()) {
        return 0;
    }

    testCopyConstructor();
    testCopyAssignmentOperator();
}