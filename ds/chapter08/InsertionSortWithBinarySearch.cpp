//
// Created by 51676 on 2024/8/16.
//

// 排序-插入排序-直接插入排序-使用二分查找方式

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArray(int a[], int length) {
    for (int i = 0; i < length; ++i) {
        printf("%3d,", a[i]);
    }
    printf("\n");
}

// 排序-插入排序-直接插入排序
void insertionSort(int a[], int length) {
//    int i, j, idx;
    for (int i = 1; i < length; ++i) {
        int idx = i;
        int tmp = a[idx];
        for (int j = i - 1; j >= 0; --j) {
            if (tmp < a[j]) {
                a[j + 1] = a[j];
                idx = j;
            }
        }
        a[idx] = tmp;
    }
}

// 排序-插入排序-直接插入排序-使用二分查找方式
void insertionSortWithBinarySearch(int a[], int length) {
    for (int i = 1; i < length; ++i) {
        int idx = i;
        int tmp = a[idx];
        // 把以下改为折半查找
//        for (int j = i - 1; j >= 0; --j) {
//            if (tmp < a[j]) {
//                a[j + 1] = a[j];
//                idx = j;
//            }
//        }
        // 折半查找, 找到要插入的位置idx
        int low = 0, high = i - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            /*if (a[mid] == tmp) { // 这里为了保证查找的稳定性, 对于 a[mid] == tmp的情况不做处理, 继续进行查找, 找到从后往前第一个大于tmp的元素的下标low
                idx = mid + 1;
                break;
            } else */if (a[mid] > tmp) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        // 待插入的位置为：
        //  1. 找到mid时, 为 mid + 1
        //  2. 找不到mid时, 为 low 或者 high + 1
        idx = idx == i ? low : idx;
//        idx = idx == i ? high + 1 : idx;
        // 移动元素
        for (int k = i; k > idx; --k) {
            a[k] = a[k - 1];
        }
        // 插入元素
        a[idx] = tmp;
    }
}

int main() {

    int length = 9;
//    int a[9] = {3, 6, 7, 9, 2, 1, 10, 8, 0};
    int a[9] = {54, 14, 87, 72, 33, 54, 30, 22, 13};
//    srand(time(NULL));
//    for (int i = 0; i < length; ++i) {
//        a[i] = rand() % 100;
//    }
    printArray(a, length);
    insertionSortWithBinarySearch(a, length);
    printArray(a, length);

    return 0;
}