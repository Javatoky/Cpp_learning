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

    Node* cloneNode(const Node* pointer);               //递归拷贝节点
    int getHeight(const Node* pointer) const;           //获取节点高度
    void updateHeight(Node* pointer);                   //更新节点高度
    int getBalanceFactor(const Node* pointer) const;    //获取节点的平衡因子大小
    void rotateLeft(Node*& pointer);                    //树左旋
    void rotateRight(Node*& pointer);                   //树右旋
    bool insertIntoNode(Node*& pointer, int value);     //将值插入节点以及递归回溯更新
    bool isAVLTreeHelper(const Node* pointer) const;    //判定是否为AVL树的助手方法
    void preOrderVisitNode(const Node* pointer, int* arr, int& index) const;    //前序遍历助手方法
    void inOrderVisitNode(const Node* pointer, int* arr, int& index) const;     //中序遍历助手方法
    void postOrderVisitNode(const Node* pointer, int* arr, int& index) const;   //后序遍历助手方法
    void release(Node* pointer);                        //递归释放节点

public:
    AVL();
    ~AVL();
    AVL(const AVL& other);
    AVL& operator=(const AVL& other);

    bool isEmpty() const;                               //判断书是否为空
    bool insert(int value);                             //插入指定值
    void clear();                                       //清空树中所有元素
    
    int* preOrder(int& length) const;                   //前序遍历，返回数组，需要外部释放内存
    int* inOrder(int& length) const;                    //中序遍历，返回数组，需要外部释放内存
    int* postOrder(int& length) const;                  //后序遍历，返回数组，需要外部释放内存

    bool testRotateLeft();
    bool testRotateRight();
    bool testIsAVLTree();
    bool isAVLTree() const;                             //判断树是否为AVL树
};
#endif