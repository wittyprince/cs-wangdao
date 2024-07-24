//
// Created by 51676 on 2024/7/24.
//

#ifndef CS_WANGDAO_HSTRING_H
#define CS_WANGDAO_HSTRING_H

// 串-堆分配存储表示-动态内存分配
typedef struct hString {
    char *ch;       // 按串长分配存储区, ch指向串的基地址
    int length;     // 串的长度
} HString;

#endif //CS_WANGDAO_HSTRING_H
