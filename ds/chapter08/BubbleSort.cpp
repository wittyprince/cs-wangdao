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
        // 优化-如果第i轮遍历没有任何数据交换, 那么i~n之后的轮次均无需再比较
        bool alreadySorted = true;
        for (int j = length - 1; j > i; --j) {
            if (a[j] < a[j - 1]) {
                swap(a[j], a[j - 1]);
                alreadySorted = false;
            }
        }
        if (alreadySorted) {
            return;
        }
    }
}

int main() {
    int length = 9;
//    int a[9] = {3, 6, 7, 9, 2, 1, 10, 8, 0};
    // 有序表, 最好时间复杂度为O(n)
    int a[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
//    srand(time(NULL));
//    for (int i = 0; i < length; ++i) {
//        a[i] = rand() % 100;
//    }
    printArray(a, length);
    bubbleSort(a, length);
    printArray(a, length);
    return 0;
}