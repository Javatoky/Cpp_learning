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

    int getSize() const;
    void pushBack(int value);
    int get(int index) const;
    bool isEmpty() const;
};

#endif