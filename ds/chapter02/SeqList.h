//
// Created by 51676 on 2024/7/23.
//

#ifndef CS_WANGDAO_SEQLIST_H
#define CS_WANGDAO_SEQLIST_H

#include <stdlib.h>
#include <stdio.h>

// 线性结构-线性表-顺序表-动态分配
#define InitSize 10  // 表长度的初始定义
typedef int ElementType;
typedef struct {
    ElementType *data; // 指示动态分配数组的指针
    int MaxSize;       // 数组的最大容量
    int length;        // 数组的当前个数
} SeqList;

void initSeqList(SeqList &L) {
    // 分配存储空间
    L.data = (ElementType *) malloc(sizeof(ElementType) * InitSize);
    L.length = 0; // 顺序表初始长度为0
    L.MaxSize = InitSize; // 初始容量
}

// 在第pos个位置上插入元素e
bool insertIntoSeqList(SeqList &L, int pos, ElementType e) {
    // 判断position的合法性 pos >= 1 and pos <= length + 1
    if (pos < 1 || pos > L.length + 1) {
        return false;
    }
    // 判断是否超过最大容量 length + 1 <= MaxSize
    // 这里先不考虑扩容问题
    if (L.length + 1 > L.MaxSize) {
        return false;
    }
    // 移动元素
    for (int j = L.length - 1; j >= pos -1; j--) {
        L.data[j + 1] = L.data[j];
    }
    // 插入元素
    L.data[pos - 1] = e;
    // 修改长度
    L.length++;
    return true;
}

// 删除第pos个位置上的元素, 并用e返回
bool deleteFromSeqList(SeqList &L, int pos, ElementType &e) {
    // 判断position的合法性 pos >= 1 and pos <= length
    if (pos < 1 || pos > L.length) {
        return false;
    }
    // 获取元素
    e = L.data[pos - 1];
    // 移动元素
    for (int j = pos - 1; j < L.length - 1; ++j) {
        L.data[j] = L.data[j + 1];
    }
    // 修改length
    L.length--;
    return true;
}

// 查找第一个元素值等于e的元素，并返回其位序
int locateElementFromSeqList(SeqList L, ElementType e) {
    for (int i = 0; i < L.length; ++i) {
        if (L.data[i] == e) {
            return i + 1;
        }
    }
    return 0;
}

void printSeqList(SeqList L) {
    for (int i = 0; i < L.length; ++i) {
        printf("%3d", L.data[i]);
    }
    printf("\n");
}

#endif //CS_WANGDAO_SEQLIST_H
