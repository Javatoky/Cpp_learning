#include "LinkedList.h"
#include <iostream>

void printBoolResult(bool status) {
    if (status) {
        std::cout << "Success" << std::endl;
    }else {
        std::cout << "Fail" << std ::endl;
    }
}

void printAllValue(const LinkedList& list) {
    if (list.isEmpty()) {
        std::cout << "No element in this list" << std::endl;
        return;
    }
    int value;
    for (int i = 0; i < list.getSize(); i++) {
        if (!list.get(i, value)) {
            std::cout << "Print interrupt!" << std::endl;
        }
        std::cout << value <<std::endl;
    }
    return;
}

int main() {
    std::cout << "Test empty linked list, isEmpty: (expect Success)" << std::endl;
    LinkedList emptyList;
    printBoolResult(emptyList.isEmpty());


    int tempValue; 
    std::cout << "Test empty linked list, get: (expect Fail)" << std::endl;
    printBoolResult(emptyList.get(7, tempValue));
    std::cout << "\n" << std::endl;

    LinkedList list;
    list.pushBack(7);
    list.pushBack(9);
    list.pushBack(3);
    std::cout << "Test not empty linked list, legal get: (expect '7' '9' '3')" << std::endl;
    printAllValue(list);

    std::cout << "Illegal get: (expect 'Fail')" << std::endl;
    printBoolResult(list.get(10, tempValue));
    std::cout << "\n" << std::endl;

    std::cout << "Test the status after clear: " << std::endl;
    list.clear();
    std::cout << "getSize: (expect '0')" << std::endl;
    std::cout << list.getSize() << std::endl;
    std::cout << "isEmpty: (expect 'Success')" << std::endl;
    printBoolResult(list.isEmpty());
    std::cout << "get: (expect 'Fail')" << std::endl;
    printBoolResult(list.get(3, tempValue));
    std::cout << "\n" << std::endl;

    std::cout << "Test insert:" << std::endl;
    LinkedList list1;
    std::cout << "Empty list, insert: (expect '9')" << std::endl;
    list1.insert(0, 9);
    printAllValue(list1);
    std::cout << "Not empty list, insert at the top: (expect '4' '9')" << std::endl;
    list1.insert(0, 4);
    printAllValue(list1);
    std::cout << "Not empty list, insert in the middle: (expect '4' '0' '9')" << std::endl;
    list1.insert(1, 0);
    printAllValue(list1);
    std::cout << "Not empty list, insert at the tail: (expect '4' '0' '9' '7')" << std::endl;
    list1.insert(3, 7);
    printAllValue(list1);
    std::cout << "Illegal insert: (expect Fail)" << std::endl;
    printBoolResult(list1.insert(9, 100));
    std::cout << "\n" << std::endl;

    std::cout << "Test remove:" << std::endl;
    std::cout << "Test remove the top: (expect '0' '9' '7')" << std::endl;
    list1.removeAt(0);
    printAllValue(list1);
    std::cout << "Test remove in the middle: (expect '0' '7')" << std::endl;
    list1.removeAt(1);
    printAllValue(list1);
    std::cout << "Test remove at the tail: (expect '0')" << std::endl;
    list1.removeAt(1);
    printAllValue(list1);
    std::cout << "Test illegal remove: (expect Fail)" << std::endl;
    printBoolResult(list1.removeAt(500));
    std::cout << "Test pushBack when the list is empty after removed: (expect '5')" << std::endl;
    list1.removeAt(0);
    if (list1.isEmpty()) {
        std::cout << "Now, the list is empty." << std::endl;
    }
    list1.pushBack(5);
    printAllValue(list1);
    std::cout << "\n" << std::endl;

    std::cout << "Test find:" << std::endl;
    std::cout << "Find existent element: (expect '0')" << std::endl;
    std::cout << list1.find(5) << std::endl;
    std::cout << "Find not existent element: (expect '-1')" << std::endl;
    std::cout << list1.find(250) << std::endl;
    std::cout << "\n" << std::endl;

    std::cout << "Test copy construction: " << std::endl;
    LinkedList a;
    a.pushBack(1);
    a.pushBack(2);
    a.pushBack(3);
    std::cout << "All values of the linked list 'a' before copied by 'b': " << std::endl;
    printAllValue(a);
    LinkedList b(a);
    a.pushBack(7);
    a.removeAt(1);
    std::cout << "Now, all values of 'a': (expect '1' '3' '7')" << std::endl;
    printAllValue(a);
    std::cout << "All values of 'b' which copied 'a': (expect '1' '2' '3')" << std::endl;
    printAllValue(b);
    std::cout << "\n" << std::endl;
    
    std::cout << "Test copy assignment: " << std::endl;
    LinkedList c;
    c.pushBack(4);
    c.pushBack(3);
    std::cout << "All values of 'c': (expect '4' '3')" << std::endl;
    printAllValue(c);
    c = a;
    std::cout << "Now, 'c' copy assignment from 'a'." << std::endl;
    a.clear();
    if (a.isEmpty()) {
        std::cout << "Now, 'a' is empty." << std::endl;
    }
    std::cout << "All values of 'c': (expect '1' '3' '7')" << std::endl;
    printAllValue(c);
    c = c;
    std::cout << "'c' copy assignment itself: (expect '1' '3' '7')" << std::endl;
    printAllValue(c);
    LinkedList d;
    std::cout << "'d' is an empty linked list, 'c' copy assignment from 'd'" << std::endl;
    c = d;
    std::cout << "All values of 'c': (expect 'No element in this list.')" << std::endl;
    printAllValue(c);
    std::cout << "'d' copy assignment from 'b'" << std::endl;
    d = b;
    std::cout << "All values of 'd': (expect '1' '2' '3')" << std::endl;
    printAllValue(d);
}