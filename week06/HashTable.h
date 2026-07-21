#ifndef HASHTABLE_H
#define HASHTABLE_H

template<typename K>
class HashTable {
private:
    struct Node {
        K key;
        Node* next;

        Node(const K& key);
    };
    Node** data;
    int bucketCount;
    int size;

    int hashFunction(const K& key) const;
    void clearAllNode();
    void expand();

public:
    HashTable();
    HashTable(const HashTable& other);
    ~HashTable();
    HashTable& operator=(const HashTable& other);

    int getSize() const;
    bool isEmpty() const;

    bool insert(const K& key);
    bool remove(const K& key);
    bool contains(const K& key) const;

    void clear();
};
#endif


template<typename K>
HashTable<K>::Node::Node(const K& key): key(key), next(nullptr) {}

template<typename K>
HashTable<K>::HashTable(): bucketCount(13), size(0) {
    data = new Node* [bucketCount];
    for (int i = 0; i < bucketCount; i++) {
        data[i] = nullptr;
    }
}

template<typename K>
HashTable<K>::HashTable(const HashTable& other): bucketCount(other.bucketCount), size(other.size) {
    data = new Node*[bucketCount];

    for(int i = 0; i < bucketCount; i++) {
        Node* pointer = other.data[i];
        if (pointer == nullptr) {
            continue;
        }

        Node* prior = new Node(pointer->key);
        Node* rear = prior;
        while (true) {
            pointer = pointer->next;
            if (pointer == nullptr) {
                break;
            }

            rear->next = new Node(pointer->key);
        }

        data[i] = prior;
    }
}

template<typename K>
HashTable<K>& HashTable<K>::operator=(const HashTable& other) {
    if (this == &other) {
        return *this;
    }

    clearAllNode();
    delete[] data;
    bucketCount = other.bucketCount;
    size = other.size;
    data = new Node*[bucketCount];

    if (size == 0) {
        return *this;
    }

    for (int i = 0; i< bucketCount; i++) {
        Node* pointer = other.data[i];
        if (pointer == nullptr) {
            continue;
        }

        Node* prior = new Node(pointer->key);
        Node* rear = prior;
        while (true) {
            pointer = pointer->next;
            if (pointer == nullptr) {
                break;
            }

            rear->next = new Node(pointer->key);
        }

        data[i] = prior;
    }

    return *this;
}

template<typename k>
HashTable<k>::~HashTable() {
    clearAllNode();
    delete[] data;
}

template<typename K>
int HashTable<K>::hashFunction(const K& key) const {
    int index = key % bucketCount;
    if (index < 0) {
        index = 0 - index;
    }

    return index;
}


template<typename K>
void HashTable<K>::clearAllNode() {
    for(int i = 0; i < bucketCount; i++) {
        Node* pointer = data[i];
        Node* temp = nullptr;
        while(pointer != nullptr) {
            temp = pointer;
            pointer = pointer->next;
            delete temp;
        }

        data[i] = nullptr;
    }
}

template<typename K>
void HashTable<K>::expand() {
    int oldBucketCount = bucketCount;
    bucketCount = 2 * bucketCount + 1;
    Node** newData = new Node*[bucketCount];
    for (int i = 0; i < bucketCount; i++) {
        newdata[i] = nullptr;
    }

    for(int i = 0; i < oldBucketCount; i++) {
        if (data[i] == nullptr) {
            continue;
        }

        Node* temp = data[i];
        Node* pointer = temp->next;
        while (true) {
            int index = hashFunction(temp->key);
            Node* next = newData[i];
            newData[i] = temp;
            temp->next = next;

            if (pointer == nullptr) {
                break;
            } else {
                temp = pointer;
                pointer = pointer->next;
            }
        }
    }

    delete[] data;
    data = newdata;
}

template<typename K>
int HashTable<K>::getSize() const {
    return size;
}


template<typename K>
bool HashTable<K>::isEmpty() const {
    return size == 0;
}

template<typename K>
bool HashTable<K>::insert(const K& key) {
    int index = hashFunction(key);

    if (data[index] == nullptr) {
        data[index] = new Node(key);
        size++;
        return true;
    }

    Node* pointer = data[index];
    while (true) {
        if (pointer->key != key) {
            if (pointer->next == nullptr) {
                pointer->next = new Node(key);
                size++;

                double loadFactor = double(size) / double(bucketCount);
                if (loadFactor > 0.75) {
                    expand();
                }

                return true;
            } else {
                pointer = pointer->next;
            }
        } else {
            return false;
        }
    }
}

template<typename K>
bool HashTable<K>::contains(const K& key) const {
    int index = hashFunction(key);

    if (data[index] == nullptr) {
        return false;
    }

    Node* pointer = data[index];
    while (true) {
        if (pointer->key == key) {
            return true;
        } else {
            if (pointer->next == nullptr) {
                return false;
            } else {
                pointer = pointer->next;
            }
        }
    }
}

template<typename K>
bool HashTable<K>::remove(const K& key) {
    int index = hashFunction(key);

    if (data[index] == nullptr) {
        return false;
    }

    if (data[index]->key == key) {
        Node* temp = data[index];
        data[index] = temp->next;
        delete temp;
        size--;
        return true;
    }

    Node* prev = data[index];
    Node* next = prev->next;

    while (true) {
        if (next == nullptr) {
            return false;
        }

        if (next->key == key) {
            prev->next = next->next;
            delete next;
            size--;
            return true;
        }

        prev = next;
        next = next->next;
    }
}

template<typename K>
void HashTable<K>::clear() {
    clearAllNode();
    size = 0;
}