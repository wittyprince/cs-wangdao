//
// Created by 51676 on 2024/8/18.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArray(int a[], int length) {
    for (int i = 0; i < length; ++i) {
        printf("%3d,", a[i]);
    }
    printf("\n");
}


void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

// 冒泡排序 -不稳定的 - 交换排序
/**
 * 每趟冒泡的结果是把序列中的最小元素(或最大元素)放到了序列的最终位置
 */
void bubbleSort(int a[], int length) {
    for (int i = 0; i < length; ++i) {
        for (int j = length - 1; j > i; --j) {
            if (a[j] < a[j - 1]) {
                swap(a[j], a[j - 1]);
            }
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
    bubbleSort(a, length);
    printArray(a, length);
    return 0;
}