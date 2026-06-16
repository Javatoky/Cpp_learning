#include<iostream>
#include "AVL.h"

void printIsAVLTree(AVL& avl) {
    if (avl.isAVLTree()) {
        std::cout << "Successful!" << std::endl;
    } else {
        std::cout << "Failed!" << std::endl;
    }
    std::cout << "\n" << std::endl;
}

int main() {
    std::cout << "Test: (function) isAVLTree : " << std::endl;
    AVL avl;
    if (avl.testIsAVLTree()) {
        std::cout << "Successful!" << std::endl;
    } else {
        std::cout << "Failed!" << std::endl;
        return 0;
    }
    std::cout << "\n" <<std::endl;

    std::cout << "The result of the test of rotateLeft:" << std::endl;
    AVL avl1;
    if (avl1.testRotateLeft()) {
        std::cout << "Pass" << std::endl;
    } else {
        std::cout << "Failed" << std::endl;
    }
    std::cout << "\n" <<std::endl;

    std::cout << "The result of the test of rotateRight:" << std::endl;
    AVL avl2;
    if (avl2.testRotateRight()) {
        std::cout << "Pass" <<std::endl;
    } else {
        std::cout << "Failed" <<std::endl;
    }
    std::cout << "\n" <<std::endl;

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