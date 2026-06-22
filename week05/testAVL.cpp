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
        std::cout << "\n" <<std::endl;
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

bool testRemoveLeafNode() {
    std::cout << "Test: remove leaf node" << std::endl;
    AVL tree;
    int arr[] = {5,3,7,2,4,6,8};
    for (int i = 0; i < 7; i++) {
        tree.insert(arr[i]);
    }

    bool result1 = tree.remove(2);
    int length1;
    int* inOrder1 = tree.inOrder(length1);
    int expected1[] = {3,4,5,6,7,8};
    bool isExpected1 = length1 == 6;
    for (int i = 0; i < length1 && isExpected1; i++) {
        if (inOrder1[i] != expected1[i]) {
            isExpected1 = false;
        }
    }
    delete[] inOrder1;

    bool passed1 = result1 && tree.isAVLTree() && isExpected1;

    bool result2 = tree.remove(4);
    bool result3 = tree.remove(3);
    int length2;
    int* inOrder2 = tree.inOrder(length2);
    int expected2[] = {5,6,7,8};
    bool isExpected2 = length2 == 4;
    for (int i = 0; i < length2 && isExpected2; i++) {
        if (inOrder2[i] != expected2[i]) {
            isExpected2 = false;
        }
    }
    delete[] inOrder2;

    bool passed2 = result2 && result3 && tree.isAVLTree() && isExpected2;

    if (passed1 && passed2) {
        std::cout << "Passed!" << std::endl;
    } else {
        std::cout << "Failed!" << std::endl;
    }
    std::cout << "\n" << std::endl;
    return passed1 && passed2;
}

bool testRemoveOnlyLeftChildNode() {
    std::cout << "Test: remove node with only left child" << std::endl;
    AVL tree;
    int arr[] = {5,3,7,2,6,8,10};
    for (int i = 0; i < 7; i++) {
        tree.insert(arr[i]);
    }

    bool removeResult = tree.remove(3);
    int length;
    int* inOrderArr = tree.inOrder(length);
    int expected[] = {2,5,6,7,8,10};
    bool isExpected = length == 6;
    for (int i = 0; i < length && isExpected; i++) {
        if (inOrderArr[i] != expected[i]) {
            isExpected = false;
        }
    }
    delete[] inOrderArr;

    if (removeResult && tree.isAVLTree() && isExpected) {
        std::cout << "Passed!" << std::endl;
    } else {
        std::cout << "Failed!" << std::endl;
    }
    std::cout << "\n" << std::endl;
    return removeResult && tree.isAVLTree() && isExpected;
}

bool testRemoveOnlyRightChildNode() {
    std::cout << "Test: remove node with only right child" << std::endl;
    AVL tree;
    int arr[] = {5,3,8,4,7,9,6};
    for (int i = 0; i < 7; i++) {
        tree.insert(arr[i]);
    }

    bool removeResult = tree.remove(3);
    int length;
    int* inOrderArr = tree.inOrder(length);
    int expected[] = {4,5,6,7,8,9};
    bool isExpected = length == 6;
    for (int i = 0; i < length && isExpected; i++) {
        if (inOrderArr[i] != expected[i]) {
            isExpected = false;
        }
    }
    delete[] inOrderArr;

    if (removeResult && tree.isAVLTree() && isExpected) {
        std::cout << "Passed!" << std::endl;
    } else {
        std::cout << "Failed!" << std::endl;
    }
    std::cout << "\n" << std::endl;
    return removeResult && tree.isAVLTree() && isExpected;
}

bool testRemoveTwoChildNode() {
    std::cout << "Test: remove node with two child" << std::endl;
    AVL tree;
    int arr[] = {5,3,7,2,4,6,8};
    for (int i = 0; i < 7; i++) {
        tree.insert(arr[i]);
    }

    bool removeResult = tree.remove(7);
    int length;
    int* inOrderArr = tree.inOrder(length);
    int expected[] = {2,3,4,5,6,8};
    bool isExpected = length == 6;
    for (int i = 0; i < length && isExpected; i++) {
        if (inOrderArr[i] != expected[i]) {
            isExpected = false;
        }
    }
    delete[] inOrderArr;

    if (removeResult && tree.isAVLTree() && isExpected) {
        std::cout << "Passed!" << std::endl;
    } else {
        std::cout << "Failed!" << std::endl;
    }
    std::cout << "\n" << std::endl;
    return removeResult && tree.isAVLTree() && isExpected;
}

bool testRemoveRoot() {
    std::cout << "Test: remove root" << std::endl;
    AVL tree;
    int arr[] = {5,3,7,2,4,6,8};
    for (int i = 0; i < 7; i++) {
        tree.insert(arr[i]);
    }

    bool removeResult = tree.remove(5);
    int length;
    int* inOrderArr = tree.inOrder(length);
    int expected[] = {2,3,4,6,7,8};
    bool isExpected = length == 6;
    for (int i = 0; i < length && isExpected; i++) {
        if (inOrderArr[i] != expected[i]) {
            isExpected = false;
        }
    }
    delete[] inOrderArr;

    if (removeResult && tree.isAVLTree() && isExpected) {
        std::cout << "Passed!" << std::endl;
    } else {
        std::cout << "Failed!" << std::endl;
    }
    std::cout << "\n" << std::endl;
    return removeResult && tree.isAVLTree() && isExpected;
}

bool testRemoveUntilEmpty() {
    std::cout << "Test: remove until the tree is empty" << std::endl;
    AVL tree;
    int arr[] = {5,3,7,2,4,6,8};
    for (int i = 0; i < 7; i++) {
        tree.insert(arr[i]);
    }

    bool result1 = tree.remove(3);
    bool result2 = tree.remove(5);
    bool result3 = tree.remove(2);
    bool result4 = tree.remove(6);
    bool result5 = tree.remove(7);
    bool result6 = tree.remove(4);
    bool result7 = tree.remove(8);

    bool allRemoved = result1 && result2 && result3 && result4 && result5 && result6 && result7;
    bool isEmpty = tree.isEmpty();

    if (allRemoved && isEmpty && tree.isAVLTree()) {
        std::cout << "Passed!" << std::endl;
    } else {
        std::cout << "Failed!" << std::endl;
    }
    std::cout << "\n" << std::endl;
    return allRemoved && isEmpty && tree.isAVLTree();
}

bool testRemoveNotExistValue() {
    std::cout << "Test: remove a value that does not exist" << std::endl;
    AVL tree;
    int arr[] = {5,3,7,2,4,6,8};
    for (int i = 0; i < 7; i++) {
        tree.insert(arr[i]);
    }

    bool removeResult = tree.remove(9);
    int length;
    int* inOrderArr = tree.inOrder(length);
    int expected[] = {2,3,4,5,6,7,8};
    bool isExpected = length == 7;
    for (int i = 0; i < length && isExpected; i++) {
        if (inOrderArr[i] != expected[i]) {
            isExpected = false;
        }
    }
    delete[] inOrderArr;

    // removeResult should be false for non-existent value
    if (!removeResult && tree.isAVLTree() && isExpected) {
        std::cout << "Passed!" << std::endl;
    } else {
        std::cout << "Failed!" << std::endl;
    }
    std::cout << "\n" << std::endl;
    return !removeResult && tree.isAVLTree() && isExpected;
}

bool testConsecutiveRotationRemove() {
    std::cout << "Test: trigger consecutive rotations" << std::endl;
    AVL tree;
    int arr[] = {5,7,4,6,11,2,12,10,1,9,3,8};
    for (int i = 0; i < 12; i++) {
        tree.insert(arr[i]);
    }

    int lengthBefore = 0;
    int* preOrderBefore = tree.preOrder(lengthBefore);
    std::cout << "The preorder values before removal: " << std::endl;
    for (int i = 0; i < lengthBefore; i++) {
        std::cout << preOrderBefore[i] << std::endl;
    }
    std::cout << "\n" << std::endl;
    delete[] preOrderBefore;

    bool removeResult = tree.remove(1);
    int rotationCount = tree.getRotationCount();
    int rebalanceCount = tree.getRebalanceCount();

    std::cout << "Remove 1 from the tree." << std::endl;
    std::cout << "Rotation count: " << rotationCount << std::endl;
    std::cout << "Rebalance count: " << rebalanceCount << std::endl;

    int length = 0;
    int* preOrderArr = tree.preOrder(length);
    int expected[] = {7,5,3,2,4,6,10,9,8,11,12};
    bool isExpectedPreOrder = length == 11;
    for (int i = 0; i < length && isExpectedPreOrder; i++) {
        if (preOrderArr[i] != expected[i]) {
            isExpectedPreOrder = false;
        }
    }

    delete[] preOrderArr;

    bool passed = removeResult && tree.isAVLTree() && rotationCount >= 2 && rebalanceCount >= 2 && isExpectedPreOrder;
    if (passed) {
        std::cout << "Passed!" << std::endl;
    } else {
        std::cout << "Failed!" << std::endl;
    }
    std::cout << "\n" << std::endl;
    return passed;
}

int main() {
    if (!testIsAVLTree()) {
        return 0;
    }

    if (!testRemoveLeafNode()) {
        return 0;
    }
    if (!testRemoveOnlyLeftChildNode()) {
        return 0;
    }
    if (!testRemoveOnlyRightChildNode()) {
        return 0;
    }
    if (!testRemoveTwoChildNode()) {
        return 0;
    }
    if (!testRemoveRoot()) {
        return 0;
    }
    if (!testRemoveUntilEmpty()) {
        return 0;
    }
    if (!testRemoveNotExistValue()) {
        return 0;
    }
    if (!testConsecutiveRotationRemove()) {
        return 0;
    }

    std::cout << "All tests passed!" << std::endl;
    return 0;
}