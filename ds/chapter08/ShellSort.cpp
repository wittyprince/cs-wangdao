//
// Created by 51676 on 2024/8/16.
//

// 希尔排序
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArray(int a[], int length) {
    for (int i = 0; i < length; ++i) {
        printf("%3d", a[i]);
    }
    printf("\n");
}

void shellSort(int a[], int length) {
    int k;
    int i, j, tmp, idx;
    // 处理步长
    for (int step =  length / 2; step >= 1; step = step / 2) {
        // 循环遍历处理在一个步长内的数据
        for (k = 0; k < step; k++) {
            // 处理相邻距离为步长的其他数据--即当成一个特殊的序列
            // 以下为直接插入排序代码
            // 循环结束条件 i < k + step - 1 ?
            for (i = k; i < length; i = i + step) {
                idx = i + 1 * step;
                if (idx < length) {
                    tmp = a[idx];
                    for (j = i; j >= 0; j = j - step) { // 遍历找到索引为i+1的元素需要插入的位置
                        if (tmp < a[j]) {
                            a[j + 1 * step] = a[j];
                            idx = j;
                        }
                    }
                    a[idx] = tmp;
                }
            }
//            printArray(a, length);
        }
    }
}

int main() {

    int length = 9;
    int a[9] = {3, 6, 7, 9, 2, 1, 10, 8, 0};
    srand(time(NULL));
    for (int i = 0; i < length; ++i) {
        a[i] = rand() % 100;
    }
    printArray(a, length);
    shellSort(a, length);
    printArray(a, length);

    return 0;
}