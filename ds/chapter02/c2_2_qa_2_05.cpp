//
// Created by 51676 on 2024/7/12.
//

#include "SqList.h"

// 删除 有序顺序表 中重复的元素
bool deleteDuplicate(SqList &L) {
    // 注意是 有序的
    if (L.length == 0) {
        return false;
    }
    int cursor = 0;
    int k = 0; // k代表有序表中不相等元素的个数
    for (int i = 1; i < L.length; i++) {
        if (L.data[cursor] != L.data[i]) {
            k++;
            L.data[k] = L.data[i];
            cursor = i;
        }
    }
    L.length = k + 1;

    return true;
}

int main() {

    SqList L;
    initSqList(L);
    insertIntoSqList(L, 1, 1);
    insertIntoSqList(L, 2, 2);
    insertIntoSqList(L, 3, 2);
    insertIntoSqList(L, 4, 2);
    insertIntoSqList(L, 5, 2);
    insertIntoSqList(L, 6, 6);
    insertIntoSqList(L, 7, 6);
    insertIntoSqList(L, 8, 9);
    insertIntoSqList(L, 9, 9);
    insertIntoSqList(L, 10, 10);

    printSqList(L);
    deleteDuplicate(L);
    printSqList(L);

    return 0;
}
