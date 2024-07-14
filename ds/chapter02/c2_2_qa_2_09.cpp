//
// Created by 51676 on 2024/7/14.
//
#include <stdio.h>

#define MaxSize 3

int main() {

    int A[MaxSize] = {1, 2, 3};
    int B[MaxSize] = {2, 3, 4};
    int C[MaxSize] = {-1, 0, 2};

    // 找出A[0],B[0],C[0]三个数中最大的元素
    int max = A[0] > B[0]
              ? A[0] > C[0] ? A[0] : C[0]
              : B[0] > C[0] ? B[0] : C[0];

    printf("max:%3d\n", max);

    int m = 0, n = 0, k = 0;
    for (; m < MaxSize && n < MaxSize && k < MaxSize;) {// 本方法不正确，因为只找到了第一个相等的元素, 这里先记录下，后期再优化
        if (A[0] == max) {
            while ((A[m] > B[n]) && (n < MaxSize)) {
                n++;
            }
            while ((A[m] > C[k]) && k < MaxSize) {
                k++;
            }
            if (B[n] == C[k]) {
                break;
            }
            m++;
        }
        if (B[0] == max) {
            while ((B[n] > A[m]) && (m < MaxSize)) {
                m++;
            }
            while ((B[n] > C[k]) && (k < MaxSize)) {
                k++;
            }
            if (A[m] == C[k]) {
                break;
            }
            n++;
        }
        if (C[0] == max) {
            while ((C[k] > A[m]) && (m < MaxSize)) {
                m++;
            }
            while (C[k] > B[n] && (n < MaxSize)) {
                n++;
            }
            if (A[m] == B[n]) {
                break;
            }
            k++;
        }
    }
    printf("%3d\n", m);
    printf("%3d\n", n);
    printf("%3d\n", k);
    printf("====\n");

    printf("%3d\n", A[m]);

    return 0;
}