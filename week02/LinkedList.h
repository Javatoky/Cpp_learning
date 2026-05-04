#ifndef LINKEDLIST_H
#define LINKEDLIST_H
class LinkedList {
private: 
    struct Node {
        int value;
        Node* next;

        Node(int v);
    };
    
    Node* head;
    Node* tail;
    int size;

public:
    LinkedList();
    ~LinkedList();

    int getSize() const;
    bool isEmpty() const;

    void pushBack(int value);
    bool insert(int index, int value);
    bool removeAt(int index);
    int find(int value) const;
    bool get(int index, int& value) const;
    void clear();
};

#endif