#include "HashTable.h"
#include <iostream>

bool testInsert() {
    std::cout << "\nTest: Insert" << std::endl;
    bool result = true;
    HashTable<int> table;

    table.insert(5);
    table.insert(18);

    if (!table.contains(5)) {
        result = false;
    }

    if (!table.contains(18)) {
        result = false;
    }

    if (table.contains(9)) {
        result = false;
    }

    if (result) {
        std::cout << "Successful!" << std::endl;
        return true;
    } else {
        std::cout << "Failed!" << std::endl;
        return false;
    }
}

bool testCollision() {
    std::cout << "\nTest: Collision after insert" << std::endl;
    HashTable<int> table;
    table.insert(3);
    table.insert(16);
    table.insert(29);
    table.insert(42);

    bool a = table.contains(3);
    bool b = table.contains(16);
    bool c = table.contains(29);
    bool d = table.contains(42);
    bool e = table.getSize() == 4;

    if (a&&b&&c&&d&&e) {
        std::cout << "Successful!" << std::endl;
        return true;
    } else {
        std::cout << "Failed!" << std::endl;
        return false;
    }
}

bool testExpand() {
    std::cout << "\nTest: Expand" << std::endl;
    
    HashTable<int> table;
    int oldBucketCount = table.getBucketCount();
    int elements[] = {13, 34, 17, 35, 2, 32, 8, 4, 21, 15};
    int len = sizeof(elements) / sizeof(elements[0]);

    //第10个元素插入触发扩容expand
    for (int i = 0; i < len; i++) {
        table.insert(elements[i]);
    }

    //验证桶数更新
    if (table.getBucketCount() <= oldBucketCount) {
        std::cout << "Failed at bucket count!" << std::endl;
        return false;
    }

    for (int i = 0; i < len; i++) {
        if (!table.contains(elements[i])) {
            std::cout << "Failed! Some elements not exist in new table." << std::endl;
            return false;
        }
    }

    //验证size不变
    if (!(table.getSize() == 10)) {
        std::cout << "Failed at size!" << std::endl;
        return false;
    }

    //验证表中元素数量与size相同
    if(!table.validateSize()) {
        std::cout << "Failed! The number of Nodes is wrong." << std::endl;
        return false;
    }

    std::cout << "Successful!" << std::endl;
    return true;
}

bool testClear() {
    std::cout << "\nTest: Clear" << std::endl;
    bool test1 = false;
    bool test2 = false;

    HashTable<int> table;
    table.insert(1);
    table.insert(15);
    table.insert(19);

    table.clear();
    bool a = !table.contains(1);
    bool b = !table.contains(15);
    bool c = !table.contains(19);
    
    if (a && b && c) {
        if (table.getSize() == 0) {
            test1 = true;
        }
    }

    HashTable<int> emptyTable;

    if (emptyTable.isEmpty()) {
        emptyTable.clear();
        if (!emptyTable.contains(67)) {
            emptyTable.insert(1);
            if (emptyTable.contains(1)) {
                test2 = true;
            }
        }
    }

    if (test1 && test2) {
        std::cout << "Successful!" << std::endl;
        return true;
    } else {
        std::cout << "Failed!" << std::endl;
        return false;
    }
}

bool testRemove() {
    std::cout << "\nTest: Remove" << std::endl;
    HashTable<int> a;

    a.insert(1);
    a.insert(14);
    a.insert(27);
    a.insert(6);
    a.insert(19);
    a.insert(32);
   
    bool test1 = !a.remove(67);
    bool test2 = !a.remove(40);
    bool test3 = a.remove(6) && !a.contains(6);
    bool test4 = a.remove(32) && !a.contains(32);
    bool test5 = a.remove(14) && !a.contains(14);
    bool test6 = a.getSize() == 3;
   
    if (test1 && test2 && test3 && test4 && test5 && test6) {
        std::cout << "Successful!" << std::endl;
        return true;
    } else {
        std::cout << "Failed" << std::endl;
        return false;
    }
}

bool testCopyConstruction() {
    std::cout << "\nTest: Copy construction" << std::endl;

    HashTable<int> emptyTable;
    HashTable<int> table = emptyTable;
    if (!table.isEmpty()) {
        std::cout << "Failed: It's not empty after copying a empty table" << std::endl;
        return false;
    }

    HashTable<int> a;
    int arr[] = {1,5,8,14,21,27};
    int len = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < len; i++) {
        a.insert(arr[i]);
    }
    HashTable<int> b = a;
    for (int i = 0; i < len; i++) {
        if (!b.contains(arr[i])) {
            std::cout << "Failed: Some values loss after copy construction." << std::endl;
            return false;
        }
    }
    if (!(a.getSize() == b.getSize())) {
        std::cout << "Failed: Size mismatch" << std::endl;
        return false;
    }

    b.remove(21);
    a.insert(10);
    if (b.contains(10) || !a.contains(21)) {
        std::cout << "Failed: Not independent!" << std::endl;
        return false;
    }

    std::cout << "Successful!" << std::endl;
    return true;
}

bool testCopyAssignment() {
    std::cout << "\nTest: Copy assignment" << std::endl;
    
    HashTable<int> emptyTable;
    HashTable<int> table;
    table = emptyTable;
    if (!table.isEmpty()) {
        std::cout << "Failed: It's not empty after copying a empty table" << std::endl;
        return false;
    }

    HashTable<int> a;
    a.insert(1);
    a.insert(2);
    a.insert(3);
    int size = a.getSize();
    a = a;
    for (int i = 1; i <= size; i++) {
        if (!a.contains(i)) {
            std::cout << "Failed: Table's values loss after copy itself." << std::endl;
            return false;
        }
    }

    HashTable<int> b;
    int arr[] = {1,5,8,14,21,27};
    int len = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < len; i++) {
        b.insert(arr[i]);
    }
    a = b;
    for (int i = 0; i < len; i++) {
        if (!a.contains(arr[i])) {
            std::cout << "Failed: Some values loss after copy construction." << std::endl;
            return false;
        }
    }
    if (!(a.getSize() == b.getSize())) {
        std::cout << "Failed: Size mismatch" << std::endl;
        return false;
    }

    b.remove(21);
    a.insert(10);
    if (b.contains(10) || !a.contains(21)) {
        std::cout << "Failed: Not independent!" << std::endl;
        return false;
    }

    std::cout << "Successful!" << std::endl;
    return true;
}

int main() {
    std::cout << "Test begins:" << std::endl;
    if (!testInsert()) {
        return 0;
    }
    if (!testCollision()) {
        return 0;
    }
    if (!testExpand()) {
        return 0;
    }
    if (!testClear()) {
        return 0;
    }
    if (!testRemove()) {
        return 0;
    }
    if (!testCopyConstruction()) {
        return 0;
    }
    if (!testCopyAssignment()) {
        return 0;
    }

    std::cout << "\nTest Over!" << std::endl;
}