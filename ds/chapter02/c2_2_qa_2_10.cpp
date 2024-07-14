//
// Created by 51676 on 2024/7/14.
//

#include <stdio.h>
#include <stdlib.h>

#define m 12
#define n 10

void printArray(int a[], int length) {
    for (int i = 0; i < length; ++i) {
        printf("%3d", a[i]);
    }
    printf("\n");
}

void swap(int &x, int &y) {
    int tmp = x;
    x = y;
    y = tmp;
}

// start, end 为 开始, 结束 下标
void reverse(int a[], int start, int end) {
    int cursor = start;
    while (cursor <= (start + end) / 2) {
        swap(a[cursor], a[end - (cursor - start)]);
        cursor++;
    }
}


int main() {

    int A[m];
    for (int i = 0; i < m; ++i) {
        A[i] = i * 2;
    }
    printArray(A, m);

    //TODO 同07题, 待验证


    return 0;
}