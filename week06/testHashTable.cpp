#include "HashTable.h"
#include <iostream>

int main() {
    HashTable<int> table;

    table.insert(5);
    table.insert(18);

    if (table.contains(5)) {
        std::cout << "Successful" << std::endl;
    } else {
        std::cout << "Failed" << std::endl;
    }

    if (table.contains(18)) {
        std::cout << "Successful" << std::endl;
    } else {
        std::cout << "Failed" << std::endl;
    }

    if (table.contains(9)) {
        std::cout << "Successful" << std::endl;
    } else {
        std::cout << "Failed" << std::endl;
    }
}