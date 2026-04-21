#include <iostream>
#include "SeqList.h"

SeqList::SeqList(): data(nullptr), size(0), capacity(0){
}

SeqList::SeqList(const SeqList& other): data(nullptr), size(other.size), capacity(other.capacity) {
    if(capacity > 0){
        data = new int[capacity];
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }
}

SeqList& SeqList::operator=(const SeqList& other) {
    if (this == &other) {
        return *this;
    }

    delete[] data;
    data = nullptr;
    capacity = other.capacity;
    size = other.size;

    if (capacity > 0) {
        data = new int[capacity];
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }

    return *this;
}

SeqList::~SeqList(){
    delete[] data;
}

int SeqList::getSize() const{
    return size;
}

void SeqList::allocate(int cap){
    if(data != nullptr){
        delete[] data;
    }
    data = new int[cap];
    capacity = cap;
    size = 0; 
}

void SeqList::setFirst(int value){
    if (capacity > 0) {
        data[0] = value;
        size = 1;
    }
}

int SeqList::getFirst() const{
    return data[0];
}

void SeqList::expand() {
    int newCapacity;
    if (capacity == 0) {
        newCapacity = 1;
    } else {
        newCapacity = 2 * capacity;
    }

    //创建新的数组
    int* temp = new int[newCapacity];
    for (int i = 0; i < size ; i++ ){
        temp[i] = data[i];
    }
    
    delete[] data;
    data = temp;
    capacity = newCapacity;
}

void SeqList::pushBack(int value) {
    if (size < capacity) {
        data[size++] = value;
    }else if (size == capacity) {
        expand();
        data[size++] = value;
    }
}

int SeqList::get(int index) const {
    if (index >= size || index < 0) {
        return -404;    // 模拟错误处理
    }
    return data[index];
}