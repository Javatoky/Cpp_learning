#include<iostream>
#include "SeqList.h"

int main() {
    SeqList list;
    int tempValue;
    bool flag = list.get(3, tempValue);
    std::cout << "Get the value of the empty list." <<std::endl;
    if (!flag){
        std::cout << "Failed" << std::endl;
    }
    std::cout << "\n" << std::endl;
    //预期：失败
    
    list.pushBack(4);
    list.pushBack(7);
    list.pushBack(3);
    std::cout << "The length of the list:" << std::endl;
    std::cout << list.getSize() << std::endl;
    std::cout << "\n" << std::endl;
    //预期：3
    std::cout << "All values of this list:" << std::endl;
    for (int i = 0; i < list.getSize(); i++) {
        list.get(i, tempValue);
        std::cout << tempValue << std::endl;
    }
    std::cout << "\n" << std::endl;
    //预期：4 7 3

    list.insert(0, 9);
    list.insert(2, 6);
    list.insert(5, 5);
    
    flag = list.insert(7, 8);
    if (!flag) {
        std::cout << "Insert in the index '7', failed." << std::endl;
    }
    std::cout << "\n" << std::endl;
    //预期：插入值'7'：失败
    std::cout << "All values of this list:" << std::endl;
    for (int i = 0; i < list.getSize(); i++) {
        list.get(i, tempValue);
        std::cout << tempValue << std::endl;
    }
    std::cout << "\n" << std::endl;
    //预期：9 4 6 7 3 5
    SeqList list2;
    list2.insert(0, 10);
    list2.get(0, tempValue);
    std::cout << "Test the inserting of empty list:" << std::endl;
    std::cout << tempValue << std::endl;
    std::cout << "\n" << std::endl;
    //预期：10

    list2.pushBack(4);
    list2.pushBack(7);
    list2.pushBack(3);
    if (list2.getSize() == list2.getCapacity()) {
        std::cout << "The size of the second list is equal to its actual capacity." << std::endl;
    }
    list2.insert(2, 5);
    list2.get(2, tempValue);
    std::cout << tempValue << std::endl;
    std::cout << "Full capacity insert test passed,:SeqList insert successfully in this situation." << std::endl;
    std::cout << "All values of this list2:" << std::endl;
    for (int i = 0; i < list2.getSize(); i++) {
        list2.get(i, tempValue);
        std::cout << tempValue << std::endl;
    }
    std::cout << "\n" << std::endl;
    //预期：size 与 capacity相同，此时插入无异常。
    //10 4 2 7 3
    

    list.removeAt(0);
    list.removeAt(2);
    list.removeAt(3);
    flag = list.removeAt(4);
    if (!flag) {
        std::cout << "Remove the value of the index '4', failed." << std::endl;
    }
    std::cout << "\n" << std::endl;
    //预期：删除索引4的值：失败
    std::cout << "All values of this list: " << std::endl;
    for (int i = 0; i < list.getSize(); i++) {
        list.get(i, tempValue);
        std::cout << tempValue << std::endl;
    }
    std::cout << "\n" << std::endl;
    //预期：4 6 3

    int findSuccess = list.find(6);
    int findLose = list.find(9);
    std::cout << "Results of find:" << std::endl;
    std::cout << findSuccess <<std::endl;
    std::cout << findLose <<std::endl;
    std::cout << "\n" << std::endl;
    //预期：1 -1

    list.clear();
    if (list.isEmpty()) {
        std::cout << "Now, the list is empty." << std::endl;
    }
    //预期：现在表是空的
    std::cout << "\n" << std::endl;

    SeqList a;
    a.pushBack(1);
    a.pushBack(2);
    a.pushBack(3);
    std::cout << "All values of 'a': " << std::endl;
    for (int i = 0; i < a.getSize(); i++) {
        a.get(i, tempValue);
        std::cout << tempValue << std::endl;
    }
    SeqList b(a);       //测试拷贝初始化：是否是深拷贝
    std::cout << "All values of 'b', which copied 'a' by construction. " << std::endl;
    for (int i = 0; i < b.getSize(); i++) {
        b.get(i, tempValue);
        std::cout << tempValue << std::endl;
    }
    a.removeAt(1);
    std::cout << "All values of 'a' after remove at the index '1': " << std::endl;
    for (int i = 0; i < a.getSize(); i++) {
        a.get(i, tempValue);
        std::cout << tempValue << std::endl;
    }
    std::cout << "All values of 'b' after 'a' removing its element. " << std::endl;
    for (int i = 0; i < b.getSize(); i++) {
        b.get(i, tempValue);
        std::cout << tempValue << std::endl;
    }
    std::cout << "\n" << std::endl;

    SeqList c;
    c.pushBack(10);
    std::cout << "All values of 'c', before copied 'a'. " << std::endl;
    for (int i = 0; i < c.getSize(); i++) {
        c.get(i, tempValue);
        std::cout << tempValue << std::endl;
    }
    c = a;
    a.clear();
    if (a.isEmpty()) {
        std::cout << "Now, 'a' is empty." << std::endl;
    }
    std::cout << "All values of 'c', after copied 'a' by '='. " << std::endl;
    for (int i = 0; i < c.getSize(); i++) {
        c.get(i, tempValue);
        std::cout << tempValue << std::endl;
    }
    std::cout << "\n" << std::endl;

    std::cout << "'c' copy itself" << std::endl;
    std::cout << "Now, all values of 'c' are as follows:" << std::endl;
    for (int i = 0; i < c.getSize(); i++) {
        c.get(i, tempValue);
        std::cout << tempValue << std::endl;
    }
}