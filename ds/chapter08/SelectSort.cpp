//
// Created by 51676 on 2024/8/19.
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

// 简单选择排序 - 不稳定的 - 选择类排序
// 每次选择一个最小的(或 最大的)元素
void selectSort(int a[], int length) {
    for (int i = 0; i < length; ++i) {
        int min = i;
        for (int j = i + 1; j < length; ++j) {
            if (a[j] < a[min]) {
                min = j;
            }
        }
        if (min != i) {
            swap(a[i], a[min]);
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
    selectSort(a, length);
    printArray(a, length);
    return 0;
}