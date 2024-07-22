//
// Created by 51676 on 2024/7/22.
//

#ifndef CS_WANGDAO_LINKEDSTACK_H
#define CS_WANGDAO_LINKEDSTACK_H

typedef int ElementType;

typedef struct linkedNode {
    ElementType data; // 数据域
    struct linkedNode *next; // 指针域
} LinkedStack;

#endif //CS_WANGDAO_LINKEDSTACK_H
