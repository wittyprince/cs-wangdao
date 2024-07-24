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

int index_KMP(SString S, SString T, int next[]) {

    return 0;
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


    return 0;
}