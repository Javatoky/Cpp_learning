#ifndef BST_H
#define BST_H
class BST {
private:
    struct Node {
        int value;
        Node* left;
        Node* right;

        Node(int value);
    };

    Node* root;
    int size;

    void release(Node* pointer);
    bool insertIntoNode(Node*& pointer, int value);
    int removeHelper(const Node* pointer) const;
    bool removeFromNode(Node*& pointer, int value);
    void preOrderVisitNode(const Node* pointer, int* arr, int& index) const;
    void inOrderVisitNode(const Node* pointer, int* arr, int& index) const;
    void postOrderVisitNode(const Node* pointer, int* arr, int& index) const;

public:
    BST();
    ~BST();
    BST(const BST& other);
    BST& operator=(const BST& other);

    int getSize() const;
    bool isEmpty() const;

    bool insert(int value);
    bool remove(int value);
    bool contains(int value) const;
    bool findMax(int& value) const;
    bool findMin(int& value) const;

    int* preOrder(int& length) const;          //树内分配内存，外部释放，引用传回长度
    int* inOrder(int& length) const;           //树内分配内存，外部释放，引用传回长度
    int* postOrder(int& length) const;         //树内分配内存，外部释放，引用传回长度
    
    void clear();
};

#endif