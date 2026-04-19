#ifndef COUNTER_H
#define COUNTER_H

class Counter {
private:
    int value;

public:
    Counter();
    void increment();
    int getValue() const;

};

#endif