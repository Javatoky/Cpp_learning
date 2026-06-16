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

    int getHeight(const Node* pointer) const;           //获取节点高度
    void updateHeight(Node* pointer);                   //更新节点高度
    int getBalanceFactor(const Node* pointer) const;    //获取节点的平衡因子大小
    void rotateLeft(Node*& pointer);                    //树左旋
    void rotateRight(Node*& pointer);                   //树右旋
    bool insertIntoNode(Node*& pointer, int value);     //将值插入节点以及递归回溯更新
    void inOrderVisitNode(const Node* pointer, int* arr, int& index) const;     //中序遍历助手方法
    bool isAVLTreeHelper(const Node* pointer) const;    //判定是否为AVL树的助手方法
    void release(Node* pointer);                        //递归释放节点

public:
    AVL();
    ~AVL();
    AVL(const AVL& other);
    AVL& operator=(const AVL& other);

    bool insert(int value);                             //插入指定值
    int* inOrder(int& length) const;                    //中序遍历，返回数组，需要外部释放内存
    void clear();                                       //清空树中所有元素

    bool testRotateLeft();
    bool testRotateRight();
    bool isAVLTree() const;                             //判断树是否为AVL树
    bool testIsAVLTree();
};
#endif