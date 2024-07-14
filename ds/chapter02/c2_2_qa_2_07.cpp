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

//    reverse(A, 5, 10);
//    printArray(A, m + n);

    int i, j;
    // 将a1 与 bn 进行交换, 这样得到的分别为 a 与 b 的逆置
    for (i = 0, j = m + n -1; i < m && j >= m; i++, j--) {
        int tmpA = A[i];
        A[i] = A[j];
        A[j] = tmpA;
    }
    printArray(A, m + n);
    // 把 a 或 b 剩余的元素逆置
    if (i < m) {
        reverse(A, i, m -1);
    }
    if (j >= m) {
        reverse(A, m, j);
    }
    printArray(A, m + n);

    // 再分别对 a, b 进行逆置 即可
//    int idxB = 0;
//    while (idxB < n / 2) {
//        swap(A[idxB], A[n - 1 - idxB]);
//        idxB++;
//    }
    reverse(A, 0, n - 1);
    printArray(A, n);

//    int idxA = n + 0;
//    while (idxA < n + m / 2) {
//        swap(A[idxA], A[n + m - 1 - (idxA - n)]);
//        idxA++;
//    }
    reverse(A, n, n + m -1);
    for (int k = n; k < n + m; ++k) {
        printf("%3d", A[k]);
    }
    printf("\n");

    return 0;
}