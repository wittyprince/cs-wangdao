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
        if (b[i] < b[j]) {
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
