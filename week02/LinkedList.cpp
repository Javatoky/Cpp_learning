#include "LinkedList.h"

LinkedList::LinkedList(): head(nullptr), tail(nullptr), size(0) {}
LinkedList::~LinkedList() {
    clear();
}

LinkedList::Node::Node(int v): value(v), next(nullptr) {}

int LinkedList::getSize() const{
    return size;
}

bool LinkedList::isEmpty() const {
    return size == 0;
}

void LinkedList::pushBack(int value) {
    Node* pointer = new Node(value);
    if (tail == nullptr) {
        head = tail = pointer;
        size++;
        return;
    }
    
    tail -> next = pointer;
    tail = pointer;
    size++;
}

bool LinkedList::insert(int index, int value) {
    if (index < 0 || index > size) {
        return false;
    }

    Node* pointer = new Node(value);
    if (index == 0) {
        pointer -> next = head;
        head = pointer;
    } else {
        Node* temp = head;
        for (int i = 0; i < index - 1; i++) {
            temp = temp -> next;
        }
        pointer -> next = temp -> next;
        temp -> next = pointer;
    }
    
    if (index == size) {
        tail = pointer;
    }
    size++;

    return true;
}

bool LinkedList::removeAt(int index) {
    if (index < 0 || index >= size) {
        return false;
    }

    Node* temp;
    Node* deleteTemp;
    if (index == 0) {
        deleteTemp = head;
        head = head -> next;
        temp = head;
    } else {
        temp = head;
        for (int i = 0; i < index - 1; i++) {
            temp = temp -> next;
        }
        deleteTemp = temp -> next;
        temp -> next = deleteTemp -> next;
    }

    if (index == size - 1) {
        tail = temp;
    }
    delete deleteTemp;
    size--;

    return true;
}

int LinkedList::find(int value) const {
    Node* temp = head;
    for (int i = 0; i < size; i++) {
        if (temp -> value == value) {
            return i;
        } 
        temp = temp -> next;
    }

    return -1;
}

bool LinkedList::get(int index, int& value) const {
    if (index < 0 || index >= size ) {
        return false;
    }

    Node* temp = head;
    for (int i = 0; i < index; i++) {
        temp = temp -> next;
    }
    value = temp -> value;

    return true;
}

void LinkedList::clear() {
    while (head != nullptr){
        Node* temp = head;
        head = head -> next;
        delete temp; 
    }

    head =  tail = nullptr; 
    size = 0;
}