#include "SeqList.h"

SeqList::SeqList(): data(nullptr), size(0), capacity(0){
}

SeqList::~SeqList(){
    delete[] data;
}

int SeqList::getSize() const{
    return size;
}