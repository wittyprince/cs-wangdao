//
// Created by 51676 on 2024/8/20.
//

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


void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

// 具体合并的方法
//     这里把数组a[]分成两部分来看 low ~ mid, mid+1 ~ high
//     把这两部分(已经有序)合并为一个新的有序序列
void merge(int a[], int low, int mid, int high) {

    // 声明一个静态变量, 无论递归多少次都只有一个数组b[]
    static int b[MaxSize];
    for (int m = low; m <= high; ++m) {
        b[m] = a[m]; // 把数组a[]的值赋值给数组b[]
    }

    int i, j, idx = low;
    for (i = low, j = mid+1; i <= mid && j <= high; ) {
        if (b[i] <= b[j]) { // 这里增加=, 是为了保持 排序的稳定性, 因为在原数组中i在j之前
            a[idx] = b[i];
            i++;
            idx++;
        } else {
            a[idx] = b[j];
            j++;
            idx++;
        }
    }
    while (i <= mid) {
        a[idx] = b[i];
        i++;
        idx++;
    }
    while (j <= high) {
        a[idx] = b[j];
        j++;
        idx++;
    }
}

// 归并排序
// 将两个或两个以上的有序表合并为一个新的有序表
//      其实本代码中mergeSort算法的实现方式, 与mergeSort的定义有区别
//      本代码中是每次除以2, 然后再合并; 原定义是 相邻的两两合并
//      如 [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
//      一、每次除以2为 1~5, 6~10
//                 1~3, 4~5, 6~8, 9~10
//                 1~2, 3, 4, 5, 6~7, 8, 9, 10
//                 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
//      然后再合并  1~2, 3, 4, 5, 6~7, 8, 9, 10
//                 1~3, 4~5, 6~8, 9~10
//                 1~5, 6~10
//                 1~10
//      --------------------------------------
//      二、相邻两两合并为 1~2, 3~4, 5~6, 7~8, 9~10
//                       1~4, 5~8, 9~10
//                       1~8, 9~10
//                       1~10
void mergeSort(int a[], int low, int high) {
//    int low = 0, high = length - 1;
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}


int main() {
    int length = MaxSize;
    int a[MaxSize] = {3, 6, 7, 9, 2, 1, 10, 8, 0};
    srand(time(NULL));
    for (int i = 0; i < length; ++i) {
        a[i] = rand() % 100;
    }
    printArray(a, length);
    mergeSort(a, 0, length -1);
    printArray(a, length);

    return 0;
}
