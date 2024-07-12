//
// Created by 51676 on 2024/7/12.
//

#include <stdio.h>

#define MaxSize 10

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

void printList(SqList L) {
    for (int i = 0; i < L.length; ++i) {
        printf("%3d", L.data[i]);
    }
    printf("\n");
}

/**
 * 思路：
 * 循环遍历顺序表L, 如果元素>=s, 且<=t, 那么用最后一个元素覆盖当前元素, 注意覆盖时, 最后一个元素也要判断不能在s~t之间
 * 如果发生覆盖, 那么length--;
 */
bool deleteBetween(SqList &L, ElementType s, ElementType t) {
    // s<t
    if (s >= t) {
        return false;
    }
    // L 不能为空
    if (L.length == 0) {
        return false;
    }

    // 双指针法 ?
    int i;
    for (i = 0; i < L.length; ++i) { // 遍历顺序表
        int j = L.length - 1;
        if (L.data[i] >= s && L.data[i] <= t) { // 如果存在 [s, t]
            while (L.data[j] >= s && L.data[j] <= t) { // 判断待覆盖的尾部元素要不能再[s, t]之间
                j--;
            }
            L.data[i] = L.data[j]; // 覆盖
            L.length--; // 发生覆盖后, 修改length
        }
    }

//    L.length = j; // 修改length

    return true;
}

int main() {

    SqList L;
    init(L);
    insert(L, 1, 1);
    insert(L, 2, 2);
    insert(L, 3, 3);
    insert(L, 4, 4);
    insert(L, 5, 5);
    insert(L, 6, 6);
    insert(L, 7, 7);
    insert(L, 8, 8);
    insert(L, 9, 9);
    insert(L, 10, 10);

    printList(L);
    deleteBetween(L, 2, 4);
    printList(L);


    return 0;
}
