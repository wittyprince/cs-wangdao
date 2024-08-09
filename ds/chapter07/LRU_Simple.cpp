//
// Created by 51676 on 2024/8/9.
//

#include <stdio.h>

// 简易版LRU

void printArray(int a[], int length) {
    for (int i = 0; i < length; ++i) {
        printf("%3d", a[i]);
    }
    printf("\n");
}

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void searchAndExchange(int a[], int length, int target) {
    if (a[0] == target) {
        return;
    }
    for (int i = 1; i < length; ++i) {
        if (a[i] == target) {
            swap(a[i - 1], a[i]);
        }
    }
}

int main() {
    int a[] = {1, 2, 3, 4, 5};
    printArray(a, 5);

    searchAndExchange(a, 5, 6);
    printArray(a, 5);

    return 0;
}

