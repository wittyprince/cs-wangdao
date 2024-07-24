//
// Created by 51676 on 2024/7/24.
//

#ifndef CS_WANGDAO_SSTRING_H
#define CS_WANGDAO_SSTRING_H

#include <stdio.h>

// 串-定长顺序存储表示-静态分配内存空间
#define MaxLength 255

// 注意王道书上的ch[]的第1个位置(即索引为0的位置)留空,
// 数据从第2个位置(即索引为1的位置)开始存储数据
typedef struct sString {
    char ch[MaxLength]; // 每个分量存储一个字符
    int length; // 串的实际长度
} SString;

// 赋值操作
bool strAssign(SString &S, char chars[]) {
    int i = 0;
    for (; chars[i] != '\0'; i++) {
        S.ch[i + 1] = chars[i];
    }
    S.length = i;
    return true;
}

// 求子串
bool subString(SString &sub, SString S, int pos, int length) {
    // 注意王道书上的ch[]的第1个位置(即索引为0的位置)留空,
    // 数据从第2个位置(即索引为1的位置)开始存储数据
    // 判断 pos 及 length 的合法性
    if (pos < 1) {
        return false;
    }
    if (pos + length - 1 > S.length) {
        return false;
    }

    for (int j = pos; j < pos + length; ++j) {
        sub.ch[j - pos + 1] = S.ch[j];
    }
    sub.length = length;
    return true;
}

int strCompare(SString S, SString T) {
    int i = 1;
    while (i <= S.length) {
        if (S.ch[i] != T.ch[i]) {
            return S.ch[i] - T.ch[i];
        }
        i++;
    }
    return S.length - T.length;
}

void printSString(SString S) {
    for (int i = 1; i <= S.length; ++i) {
        printf("%c", S.ch[i]);
    }
    printf("\n");
}

#endif //CS_WANGDAO_SSTRING_H
