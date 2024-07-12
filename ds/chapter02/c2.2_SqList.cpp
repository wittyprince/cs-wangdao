//
// Created by 51676 on 2024/7/12.
//

#include <stdio.h>
#include <stdlib.h>

// 线性表-顺序表
#define MaxSize 5

typedef int ElementType;

typedef struct {
    ElementType data[MaxSize];
    int length; // 当前长度
} SqList;


void init(SqList &L) {
    L.length = 0; // 初始长度为0
}

bool insert(SqList &L, int position, ElementType e) {
    // 判断position的合法性 position >= 1 and position <= length + 1
    if (position < 1 || position > L.length + 1) {
        return false;
    }

    // 判断是否超过最大容量 length + 1 <= MaxSize
    if (L.length + 1 > MaxSize) {
        return false;
    }

    // 移动元素 position - 1处开始的元素, 均需向后移动
    for (int j = L.length; j >= position; j--) {
        L.data[j] = L.data[j - 1];
    }

    // 插入 position - 1处插入元素
    L.data[position - 1] = e;

    // 长度变更 length++;
    L.length++;

    return true;
}

bool deleteFromSqList(SqList &L, int pos, ElementType &e) {
    if(pos < 1 || pos >= L.length) {
        return false;
    }
    e = L.data[pos - 1];
    for (int j = pos; j < L.length; ++j) {
        L.data[j - 1] = L.data[j];
    }
    L.length--;
    return true;
}

int locateElement(SqList L, ElementType e) {
    for (int i = 0; i < L.length; ++i) {
        if (L.data[i] == e) {
            return i + 1;
        }
    }
    return 0;
}

void printList(SqList L) {
    for (int i = 0; i < L.length; ++i) {
        printf("%3d", L.data[i]);
    }
    printf("\n");
}

int main() {

    SqList L;
    init(L);
    insert(L, 1, 1);
    insert(L, 2, 2);
    insert(L, 3, 3);
    insert(L, 2, 5);
    printList(L);
    ElementType deletedElement;
    deleteFromSqList(L, 3, deletedElement);
    printf("%3d\n", deletedElement);
    printList(L);
    return 0;
}