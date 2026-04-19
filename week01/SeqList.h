#ifndef SEQLIST_H
#define SEQLIST_H

class SeqList {
private:
    int* data;
    int size;
    int capacity;

public:
    SeqList();
    ~SeqList();
    
    int getSize() const;
};

#endif