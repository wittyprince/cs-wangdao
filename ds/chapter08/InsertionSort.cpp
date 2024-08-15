//
// Created by 51676 on 2024/8/16.
//

// 直接插入排序
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArray(int a[], int length) {
    for (int i = 0; i < length; ++i) {
        printf("%3d", a[i]);
    }
    printf("\n");
}

/**
 * 直接插入排序
 * @param a 待排序数组
 * @param length 待排序数组长度
 */
void insertionSort(int a[], int length) {
    int i, j, tmp, idx;
    for (i = 0; i < length - 1; ++i) {
        idx = i + 1;
        tmp = a[idx];
        for (j = i; j >= 0; j--) { // 遍历找到索引为i+1的元素需要插入的位置
            if (tmp < a[j]) {
                a[j + 1] = a[j];
                idx = j;
            }
        }
        a[idx] = tmp;
    }
}

int main() {
    int length = 8;
    int a[8] = {3, 6, 7, 9, 2, 1, 10, 8};
//    srand(time(NULL));
//    for (int i = 0; i < length; ++i) {
//        a[i] = rand() % 100;
//    }
    printArray(a, length);
    insertionSort(a, length);
    printArray(a, length);

    return 0;
}
