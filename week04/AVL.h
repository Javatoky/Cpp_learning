#ifndef AVL_H
#define AVL_H
class AVL {
private:
    struct Node {
        int value;
        int height;
        Node* left;
        Node* right;

        Node(int value);
    };
    Node* root;
    int size;

    int getHeight(const Node* pointer) const;
    void updateHeight(Node* pointer);
    int getBalanceFactor(const Node* pointer) const;
    void rotateLeft(Node*& pointer);                    //树左旋，调用时bf必须为 -2
    void rotateRight(Node*& pointer);                   //树右旋，调用时bf必须为 2
    void release(Node* pointer);

public:
    AVL();
    ~AVL();
    AVL(const AVL& other);
    AVL& operator=(const AVL& other);

    void clear();

    bool testRotateLeft();
};
# endif