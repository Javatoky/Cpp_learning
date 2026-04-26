#include "SeqListPractice.h"

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

bool SeqList::isEmpty() const {
    return size == 0;
}

//引用是编译器的障眼法：它用一块你看不见的内存存了一个地址，然后让你觉得你在直接操作原变量；当你问它“你的地址是啥”时，它悄悄把那块内存里存的地址读数告诉你，让你永远不知道它自己的家门牌号。