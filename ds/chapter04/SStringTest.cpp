//
// Created by 51676 on 2024/7/24.
//

#include <stdio.h>
#include "SString.h"

// 模式匹配-简单方式(暴力方式)
int index(SString S, SString T) {
    int i = 1, j = 1;
    // 循环结束的条件有两个：
    // 1. 匹配成功：
    //      j = T.length + 1;
    // 2. 匹配不成功
    //      j = 1
    while (i <= S.length && j <= T.length) {
        if (S.ch[i] == T.ch[j]) {
            i++;
            j++;
        } else {
            i = i -j + 2;
            j = 1;
        }
    }
    if (j > T.length) {
        return i - T.length; // 也可以写为 i - j + 1
    }
    return 0;
}

// 模式匹配-KMP
int index_KMP(SString S, SString T, int next[]) {
    int i = 1, j = 1;
    // 循环结束的条件有两个：
    // 1. 匹配成功：
    //      j = T.length + 1;
    // 2. 匹配不成功
    //      j = next[j], next[j]的取值范围是1~T.length-1
    while (i <= S.length && j <= T.length) {
        if (j == 0 || S.ch[i] == T.ch[j]) {
            i++;
            j++;
        } else {
            j = next[j];
        }
    }
    if (j > T.length) {
        return i - T.length;
    }
    return 0;
}

void getNext(SString T, int next[]) {
    int i = 1; // next[]数组的下标, 从1开始
    int j = 0; // 与主串对齐的位置
    next[1] = 0; //
    while (i < T.length) {
        if (j == 0 || T.ch[i] == T.ch[j]) {
            ++i;
            ++j;
            next[i] = j; // 若pi = pj, 则 next[j + 1] = next[j] + 1;
        } else {
            j = next[j]; // 否则, 令 j = next[j], 继续循环
        }
    }
}

/**
 * 计算nextval[]数组
 * @param T 模式串
 * @param next[] next[]数组
 * @param nextval[] nextval[]数组
 */
void getNextvalArray(SString T, int next[], int nextval[]) {
    nextval[1] = 0;
    for (int j = 2; j <= T.length; ++j) {
        if (T.ch[next[j]] == T.ch[j]) {
            nextval[j] = nextval[next[j]];
        } else {
            nextval[j] = next[j];
        }
    }
}


int main() {

    char c1 = 'a';
//    char c2[5] = "abcde"; // 注意此种赋值方法有问题, 需要使用c2[] 或者 c2[6]
//    char c3[6] = 'abcde'; // 注意此种赋值方法有问题, 单引号只能是单个字符
    char c4[6] = "abcde"; // 注意此种赋值方法有问题,
    char c5[] = "abc"; // 注意此种赋值方法有问题,


    SString S;
    strAssign(S, c4);
    printSString(S);

    SString T;
    strAssign(T, c5);
    printSString(T);

    int pos = index(S, T);
    printf("%d\n", pos);

    SString S0;
    strConcat(S0, S, T);
    printSString(S0);

    // 注意next[]数组的第1个位置(即索引为0)不参与KMP计算
    int next[] = {0, 0, 1, 1};
    pos = index_KMP(S, T, next);
    printf("%d\n", pos);



    char ch6[] = "aaaab";
    SString  T6;
    strAssign(T6, ch6);
    printSString(T6);

    int next6[] = {0, 0, 1, 2, 3, 4};
    int nextval6[6];
    getNextvalArray(T6, next6, nextval6);

    for (int k = 1; k < 6; ++k) {
        printf("%3d", nextval6[k]);
    }
    printf("\n");

    return 0;
}