//
// Created by 51676 on 2024/7/14.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "SqList.h"

#define MaxSizeA 10
#define MaxSizeB 10

void printArray(int a[], int length) {
    for (int i = 0; i < length; ++i) {
        printf("%3d", a[i]);
    }
    printf("\n");
}
// 两个有序表 合并为 一个有序表
int main() {
    int a[MaxSizeA], b[MaxSizeB];
//    srand(time(NULL));
    for (int i = 0; i < MaxSizeA; ++i) {
        a[i] = i * 2;
    }
    for (int i = 0; i < MaxSizeB; ++i) {
        b[i] = i * 3;
    }
    printArray(a, MaxSizeA);
    printArray(b, MaxSizeB);

    int c[MaxSizeA + MaxSizeB];
    int m, n, k = 0;
    for (m = 0, n = 0; m < MaxSizeA && n < MaxSizeB; ) {
        if (a[m] <= b[n]) {
            c[k] = a[m];
            m++;
            k++;
        } else {
            c[k] = b[n];
            n++;
            k++;
        }
    }
    while (m < MaxSizeA) {
        c[k] = a[m];
        m++;
        k++;
    }
    while (n < MaxSizeB) {
        c[k] = b[n];
        n++;
        k++;
    }

    printArray(c, MaxSizeA + MaxSizeB);


    return 0;
}
