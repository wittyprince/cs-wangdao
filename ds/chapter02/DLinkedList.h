//
// Created by 51676 on 2024/7/24.
//

#ifndef CS_WANGDAO_DLINKEDLIST_H
#define CS_WANGDAO_DLINKEDLIST_H

typedef int ElementType;

typedef struct dNode {
    ElementType data;
    struct dNode *prior, *next;
} DNode, *DLinkedList;

#endif //CS_WANGDAO_DLINKEDLIST_H
