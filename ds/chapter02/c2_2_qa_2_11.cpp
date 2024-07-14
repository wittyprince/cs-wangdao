//
// Created by 51676 on 2024/7/14.
//
#include <stdio.h>
#include <stdlib.h>

#define MaxSize 5

void printArray(int a[], int length) {
    for (int i = 0; i < length; ++i) {
        printf("%3d", a[i]);
    }
    printf("\n");
}

int findMiddle(int A[], int B[]) {
    int lowA = 0, highA = MaxSize - 1;
    int lowB = 0, highB = MaxSize - 1;
    int midA, midB;
    while (lowA < highA && lowB < highB) {
        midA = (lowA + highA) / 2;
        midB = (lowB + highB) / 2;
        if (A[midA] < B[midB]) {
            lowA = midA;
            highB = midB;
        } else if (A[midA] > B[midB]) {
            highA = midA;
            lowB = midB;
        } else {
            return A[midA];
        }
    }

    if (lowA == highA) {
        if (lowB < highB) {
            if (A[midA] < B[lowB]) {
                return B[lowB];
            } else if (A[midA] > B[highB]) {
                return B[highB];
            } else {
                return A[midA];
            }
        }
    }

    if (lowB == highB) {
        if (B[midB] < A[lowA]) {
            return A[lowA];
        } else if (B[midB] > A[highA]) {
            return A[highA];
        } else {
            return B[midB];
        }
    }

    return -1; // 这里-1可能不准确，不能保证中位数 不等于 -1, 待完善

}

int main() {

    int A[MaxSize] = {11, 13, 15, 17, 19};
//    for (int i = 0; i < MaxSize; ++i) {
//        A[i] = i * 2;
//    }
    printArray(A, MaxSize);

    int B[MaxSize] = {2, 4, 6, 8, 20};
    printArray(B, MaxSize);

    int mid = findMiddle(A, B);
    printf("%3d\n", mid);





    return 0;
}