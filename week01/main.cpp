#include <iostream>
#include "Counter.h"

int main() {
    Counter counter;
    counter.increment();
    counter.increment();
    std::cout << counter.getValue() << std::endl;
    return 0;
}