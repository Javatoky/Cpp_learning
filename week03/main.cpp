#include "BST.h"
#include<iostream>

int main() {
    BST emptyTree;
    std::cout << "Removing default(expected)" << std::endl;
    if (!emptyTree.remove(3)) {
        std::cout << "Removing default" << std::endl;
    }
    std::cout << "\n" <<std::endl;

    BST tree;
    int arr[] = {5,3,7,2,4,6,8};

    for (int i=0; i<7; i++) {
        tree.insert(arr[i]);
    }
    int length = 0;
    int* array = nullptr;
    array = tree.inOrder(length);
    std::cout << "2,3,4,5,6,7,8(expected)" << std::endl;
    for (int i=0; i<length; i++) {
        std::cout << array[i] << std::endl;
    }
    delete[] array;
    std::cout << "\n" <<std::endl;

    std::cout << "2,3,4,5,6,7(expected)" << std::endl;
    if (tree.remove(8)) {
        array = tree.inOrder(length);
        for (int i=0; i<length; i++) {
            std::cout << array[i] << std::endl;
        }
    }
    delete[] array;
    std::cout << "\n" <<std::endl;

    std::cout << "2,3,4,5,6(expected)" << std::endl;
    if (tree.remove(7)) {
        array = tree.inOrder(length);
        for (int i=0; i<length; i++) {
            std::cout << array[i] << std::endl;
        }
    }
    delete[] array;
    std::cout << "\n" <<std::endl;
 
    std::cout << "2,4,5,6(expected)" << std::endl;
    if (tree.remove(3)) {
        array = tree.inOrder(length);
        for (int i=0; i<length; i++) {
            std::cout << array[i] << std::endl;
        }
    }
    delete[] array;
    std::cout << "\n" <<std::endl;

    std::cout << "2,4,6(expected)" << std::endl;
    if (tree.remove(5)) {
        array = tree.inOrder(length);
        for (int i=0; i<length; i++) {
            std::cout << array[i] << std::endl;
        }
    }
    delete[] array;
    std::cout << "\n" <<std::endl;

    std::cout << "6(expected)" << std::endl;
    if (tree.remove(2) && tree.remove(4)) {
        array = tree.inOrder(length);
        for (int i=0; i<length; i++) {
            std::cout << array[i] << std::endl;
        }
    }
    delete[] array;
    std::cout << "\n" <<std::endl;

    if (tree.remove(6)) {
        array = tree.inOrder(length);
        std::cout << "empty(expected)" << std::endl;
        for (int i=0; i<length; i++) {
            std::cout << array[i] << std::endl;
        }
    }
    delete[] array;
    std::cout << "\n" <<std::endl;

    std::cout << "Removing default(expected)" << std::endl;
    if (!tree.remove(13)) {
        std::cout << "Removing default" << std::endl;
    }
}
