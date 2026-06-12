#include<iostream>
#include "AVL.h"

int main() {
    std::cout << "The result of the test of rotateLeft:" << std::endl;
    AVL avl;
    if (avl.testRotateLeft()) {
        std::cout << "Pass" << std::endl;
    } else {
        std::cout << "Failed" << std::endl;
    }
}