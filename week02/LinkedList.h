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
    LinkedList(const LinkedList& other);
    LinkedList& operator=(const LinkedList& other);
    ~LinkedList();

    int getSize() const;                        //获取表长
    bool isEmpty() const;                       //判断是否为空

    void pushBack(int value);                   //插入元素：在链表的尾部
    bool insert(int index, int value);          //插入元素：在指定索引处
    bool removeAt(int index);                   //移除指定索引的元素
    int find(int value) const;                  //查找指定元素，返回第一个元素的索引；没有则返回-1
    bool get(int index, int& value) const;      //获取指定索引处的值，成功返回true，失败返回false
    void clear();                               //清空整个表
};

#endif