//
// Created by 51676 on 2024/8/5.
//

#include <stdio.h>
// 弗洛伊德算法
int main() {

    int INFINITY = 99;
    int n = 5;
    int A[n][n];
    int Path[n][n];

    // A[][]
    A[0][0] = 0;
    A[0][1] = INFINITY;
    A[0][2] = 1;
    A[0][3] = INFINITY;
    A[0][4] = 10;

    A[1][0] = INFINITY;
    A[1][1] = 0;
    A[1][2] = INFINITY;
    A[1][3] = 1;
    A[1][4] = 5;

    A[2][0] = INFINITY;
    A[2][1] = 1;
    A[2][2] = 0;
    A[2][3] = INFINITY;
    A[2][4] = 7;

    A[3][0] = INFINITY;
    A[3][1] = INFINITY;
    A[3][2] = INFINITY;
    A[3][3] = 0;
    A[3][4] = 1;

    A[4][0] = INFINITY;
    A[4][1] = INFINITY;
    A[4][2] = INFINITY;
    A[4][3] = INFINITY;
    A[4][4] = 0;

    // Path[][]
    Path[0][0] = -1;
    Path[0][1] = -1;
    Path[0][2] = -1;
    Path[0][3] = -1;
    Path[0][4] = -1;

    Path[1][0] = -1;
    Path[1][1] = -1;
    Path[1][2] = -1;
    Path[1][3] = -1;
    Path[1][4] = -1;

    Path[2][0] = -1;
    Path[2][1] = -1;
    Path[2][2] = -1;
    Path[2][3] = -1;
    Path[2][4] = -1;

    Path[3][0] = -1;
    Path[3][1] = -1;
    Path[3][2] = -1;
    Path[3][3] = -1;
    Path[3][4] = -1;

    Path[4][0] = -1;
    Path[4][1] = -1;
    Path[4][2] = -1;
    Path[4][3] = -1;
    Path[4][4] = -1;

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (A[i][j] > A[i][k] + A[k][j]) {
                    A[i][j] = A[i][k] + A[k][j];
                    Path[i][j] = k;
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%3d", A[i][j]);
        }
        printf("\n");
    }
    printf("=========\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%3d", Path[i][j]);
        }
        printf("\n");
    }

    return 0;
}
