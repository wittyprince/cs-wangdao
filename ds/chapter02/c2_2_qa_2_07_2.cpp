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

    int A[m + n];
    for (int i = 0; i < m + n; ++i) {
        A[i] = i;
    }
    printArray(A, m + n);

    // 先整体逆置
    reverse(A, 0, m + n -1);
    printArray(A, m + n);

    // 再分别对 a, b 进行逆置 即可
    reverse(A, 0, n - 1);
    printArray(A, n);

    reverse(A, n, n + m -1);
    for (int k = n; k < n + m; ++k) {
        printf("%3d", A[k]);
    }
    printf("\n");

    return 0;
}