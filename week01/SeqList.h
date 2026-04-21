#ifndef SEQLIST_H
#define SEQLIST_H

class SeqList {
private:
    int* data;
    int size;
    int capacity;

    void expand();

public:
    SeqList();
    SeqList(const SeqList& other);
    SeqList& operator=(const SeqList& other);
    ~SeqList();

    void allocate(int cap);
    int getSize() const;
    void setFirst(int value);
    int getFirst() const;
    void pushBack(int value);
    int get(int index) const;
};

#endif