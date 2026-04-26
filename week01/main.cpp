#include <iostream>
#include "SeqListPractice.h"

int main() {
    SeqList list;
    list.pushBack(10);
    list.pushBack(20);
    list.pushBack(30);

    std::cout << list.getSize() << std::endl;
    std::cout << list.get(0) << std::endl;
    std::cout << list.get(1) << std::endl;
    std::cout << list.get(2) <<std::endl;
    
    return 0;
}