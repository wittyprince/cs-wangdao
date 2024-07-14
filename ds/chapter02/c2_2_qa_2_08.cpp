//
// Created by 51676 on 2024/7/14.
//

#include <stdio.h>
#include <stdlib.h>

#include "SqList.h"

#define m 5

void printArray(int a[], int length) {
    for (int i = 0; i < length; ++i) {
        printf("%3d", a[i]);
    }
    printf("\n");
}

void binarySearch(int a[], int length, int e) {
    int mid, low = 0, high = length -1;
    while (low <= high) {
        mid = low + (high - low) / 2;
        if (a[mid] == e) {
            return;
        } else if (a[mid] < e) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if (a[mid] == e && mid != length - 1) {
        int tmp = a[mid];
        a[mid] = a[mid + 1];
        a[mid + 1] = tmp;
    }
    if (low > high) {
        for (int i = length - 1; i > high; --i) {
            a[i + 1] = a[i];
        }
        a[high + 1] = e;

    }
}

int main() {

    int A[m + 1];
    for (int i = 0; i < m; ++i) {
        A[i] = i * 2;
    }
    printArray(A, m);

    binarySearch(A, m, 3);
    printArray(A, m + 1);


    return 0;
}
