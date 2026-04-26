#ifndef SEQLIST_H
#define SEQLIST_H
class SeqList {
private:
    int* data;
    int capacity;
    int size;

    void expand();                          //扩展内部容量

public:
    SeqList();
    ~SeqList();
    SeqList(const SeqList& other);
    SeqList& operator=(const SeqList& other);

    int getSize() const;                    //获取表长            
    bool isEmpty() const;                   //判定是否为空
    int getCapacity() const;                //测试使用的函数：获取capacity值

    void pushBack(int value);               //在尾部插入值
    bool insert(int index, int value);      //在指定位置插入
    bool removeAt(int index);               //删除指定位置的值
    int find(int value) const;              //查找某个值的位置
    bool get(int index, int& value) const;  //取某个位置的值（通过引用参数取用）
    void clear();                           //清空表内元素
};
#endif