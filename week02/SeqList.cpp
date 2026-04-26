#include "SeqList.h"

SeqList::SeqList(): data(nullptr), capacity(0), size(0) {
}

SeqList::SeqList(const SeqList& other): data(nullptr), capacity(other.capacity), size(other.size) {
    if (capacity > 0){
        data = new int[capacity];

        for (int i = 0; i < size; i++ ){
            data[i] = other.data[i];
        }
    }
}

SeqList& SeqList::operator=(const SeqList& other){
    if (this == &other){
        return *this;
    }
    
    delete[] data;
    data = nullptr;
    capacity = other.capacity;
    size = other.size;

    if (capacity > 0) {
        data = new int[capacity];
        
        for (int i= 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }
    return *this;
}

SeqList::~SeqList() {
    delete[] data;
}

int SeqList::getSize() const {
    return size;
}

bool SeqList::isEmpty() const {
    return size == 0;
}

int SeqList::getCapacity() const {
    return capacity;
}

void SeqList::expand(){
    int newCapacity;
    if (capacity == 0) {
        newCapacity = 1;
    } else {
        newCapacity = 2 * capacity;
    }

    int* array = new int[newCapacity];
    for (int i = 0; i < size ; i++) {
        array[i] = data[i];
    }

    delete[] data;
    data = array;
    capacity = newCapacity;
}

void SeqList::pushBack(int value){
    if (size == capacity) {
        expand();
    }
    data[size++] = value;
}
bool SeqList::insert(int index, int value) {
    if (index < 0 || index > size) {
        return false;
    }

    if (size == capacity) {
        expand();
    }

    for (int i = size; i > index; i--) {
        data[i] = data[i-1];
    }
    
    data[index] = value;
    size++;

    return true;
}

bool SeqList::removeAt(int index) {
    if (index < 0 || index >= size) {
        return false;
    }

    for (int i = index; i < size - 1; i++) {
        data[i] = data[i + 1];
    }
    size--;
    return true;
}

int SeqList::find(int value) const {
    for (int i = 0; i < size; i++ ) {
        if (data[i] == value) {
            return i;
        }
    }
    return -1;
}

bool SeqList::get(int index, int& value) const {
    if (index < 0 || index >= size) {
        return false;
    }
    value = data[index];
    return true;
}

void SeqList::clear() {
    size = 0;
}