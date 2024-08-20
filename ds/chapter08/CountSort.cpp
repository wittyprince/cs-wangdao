//
// Created by 51676 on 2024/8/20.
//

// ref: https://www.bilibili.com/video/BV1KU4y1M7VY/?vd_source=61c56aae555920b10cbb8868534d9aa0
// ref: https://www.bilibili.com/video/BV1sU4y1R7pm/?vd_source=61c56aae555920b10cbb8868534d9aa0

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MaxSize 9

void printArray(int a[], int length) {
    for (int i = 0; i < length; ++i) {
        printf("%3d,", a[i]);
    }
    printf("\n");
}

// 计数排序
// 通过【计数】而不是【比较】来进行排序
// 仅适用于【跨度较小】的【正整数】序列
void countSort(int a[], int length) {
    if (length < 2) {
        return;
    }
    // 寻找最小与最大的元素
    int min = a[0];
    int max = a[0];
    for (int i = 1; i < length; ++i) {
        if (a[i] < min) {
            min = a[i];
        }
        if (a[i] > max) {
            max = a[i];
        }
    }

    // 分配一个长度为 cLength = max - min + 1 的数组存储计数, 并初始化为0
    // 计数数组c
    int cLength = max - min + 1;
//    int *cArray = (int *) malloc(sizeof(int) * cLength);
    int c[cLength];
    for (int i = 0; i < cLength; ++i) {
        c[i] = 0;
    }

    // 统计计数
    for (int i = 0; i < length; ++i) {
        c[a[i] - min]++;
    }

    // 统计计数的累加值
    // 把计数数组 变为 为累计数组, 目的是 用累计数组来确定输出结果数组中元素的位置
    int acc[cLength];
    acc[0] = c[0];
    for (int i = 1; i < cLength; ++i) {
        acc[i] = c[i] + acc[i - 1];
    }

    // 创建一个临时数组保存结果
//    int *bArray = (int *) malloc(sizeof(int) * length);
    int b[length];
    // 将元素放到正确的位置上
    for (int i = 0; i < length; ++i) {
        // 这里的 -1 是因为数组下标从0开始, 如果从1开始那么就不用-1
        b[acc[a[i] - min] - 1] = a[i];
        acc[a[i] - min]--; // 这里的减减是因为如果有相同的元素, 那么需要做向前移动一个位置
    }
    
    // 将结果复制回原数组
    for (int i = 0; i < length; ++i) {
        a[i] = b[i];
    }
}

int main() {
    int length = MaxSize;
    int a[MaxSize] = { 93,  96, 97, 96, 95, 99, 97, 98, 95};
    srand(time(NULL));
    for (int i = 0; i < length; ++i) {
        a[i] = rand() % 100;
    }
    printArray(a, length);
    countSort(a, length);
    printArray(a, length);

    return 0;
}