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
    int leftRotationCount;
    int rightRotationCount;
    int rebalanceCount;

    Node* cloneNode(const Node* pointer);               //递归拷贝节点
    int getHeight(const Node* pointer) const;           //获取节点高度
    void updateHeight(Node* pointer);                   //更新节点高度
    int getBalanceFactor(const Node* pointer) const;    //获取节点的平衡因子大小
    void rotateLeft(Node*& pointer);                    //树左旋
    void rotateRight(Node*& pointer);                   //树右旋
    void rotateAsNeeded(Node*& pointer);                //根据情况进行旋转
    bool insertIntoNode(Node*& pointer, int value);     //将值插入节点以及递归回溯平衡
    int findSubTreeMax(const Node* pointer) const;      //删除的助手方法：查找子树最大值  
    bool removeFromNode(Node*& pointer, int value);     //删除指定值的节点以及递归回溯平衡
    bool checkNodeHeight(const Node* pointer) const;    //检查节点的height是否正确
    bool verifyInOrder() const;                               //验证中序遍历顺序为升序，确认其有二分性质
    bool validateNodeBalanceFactor(const Node* pointer) const;                  //验证节点的平衡因子
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
    bool remove(int value);                             //删除指定值
    void clear();                                       //清空树中所有元素
    
    int* preOrder(int& length) const;                   //前序遍历，返回数组，需要外部释放内存
    int* inOrder(int& length) const;                    //中序遍历，返回数组，需要外部释放内存
    int* postOrder(int& length) const;                  //后序遍历，返回数组，需要外部释放内存

    bool isAVLTree() const;                             //判断树是否为AVL树
    int getRotationCount() const;                       //获取上一次删除触发的基础旋转次数
    int getRebalanceCount() const;                      //获取上一次删除触发的再平衡次数
    bool testRotateLeft();
    bool testRotateRight();
    bool testIsAVLTree();
};
#endif