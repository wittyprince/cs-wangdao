//
// Created by 51676 on 2024/7/24.
//

#ifndef CS_WANGDAO_BSTRING_H
#define CS_WANGDAO_BSTRING_H

// 串-块链存储表示
// 存储密度低：每个字符1B, 每个指针4B
typedef struct b1String {
    char ch; // 每个节点存一个字符
    struct b1String *next; // 指针
} B1String;

// 串-块链存储表示
// 存储密度高一点：每个字符4B, 每个指针4B
typedef struct b4String {
    char ch[4]; // 每个节点存多个字符
    struct b4String *next; // 指针
} B4String;

#endif //CS_WANGDAO_BSTRING_H
