//
// Created by 51676 on 2024/7/15.
//

#ifndef CS_WANGDAO_LNODE_H
#define CS_WANGDAO_LNODE_H

#include <stdlib.h>

typedef int ElementType;

typedef struct lnode {
    ElementType data;
    struct lnode *next;
} LNode;

typedef LNode *LinkedList;

bool initLinkedList(LNode *&L) {
    L = (LNode *) malloc(sizeof(LNode));
    L->next = NULL;
    L->data = 0;
    return true;
}

bool initLinkedList2(LinkedList &L) {
    L = (LNode *) malloc(sizeof(LNode));
    L->next = NULL;
    L->data = 0;
    return true;
}

int lengthOfLinkedList(LinkedList L) {
    int length = 0;
    LNode *p = L; // 游标指针p
    while (p->next != NULL) {
        p = p->next;
        length++;
    }
    return length;
}

LNode *getElement(LinkedList L, int pos) {
    LNode *p = L;
    int i = 0;
    while (p != NULL && i < pos) {
        p = p->next;
        i++;
    }
    return p;
}

LNode *locateElement(LinkedList L, ElementType e) {
    LNode *p = L->next;
    while (p != NULL && p->data != e) {
        p = p->next;
    }
    return p;
}

bool insertIntoLinkedList(LinkedList &L, int pos, ElementType e) {
    if (pos < 1) { // 位置pos从1开始
        return false;
    }
    int i = 0;
    LNode *p = L; // 游标
    while (p != NULL && i < pos -1) { // 经过遍历 i < pos -1 得到的p为要插入位置的前一个节点
        p = p->next;
        i++;
    }
    // 如果p为NULL, 那么表名要插入位置的前一个节点为NULL, 要插入位置为无效位置
    if (p == NULL) {
        return false;
    }
    LNode *q = (LNode *)malloc(sizeof(LNode));
    q->data = e;
    q->next = NULL;

    q->next = p->next;
    p->next = q;
    return true;
}

bool deleteFromLinkedList(LinkedList &L, int pos, ElementType &e) {
    if (pos < 1) { // 位置pos从1开始
        return false;
    }
    int i = 0;
    LNode *p = L; // 游标
    while (p != NULL && i < pos -1) { // 经过遍历 i < pos -1 得到的p为要删除位置的前一个节点
        p = p->next;
        i++;
    }
    // 如果p为NULL, 那么表名要删除位置的前一个节点为NULL, 要删除位置为无效位置
    if (p == NULL) {
        return false;
    }
    LNode *q = p->next;
    p->next = q->next;

    e = q->data;
    free(q);
    return true;
}

bool headInsert(LinkedList &L, ElementType e) {
    LNode *q = (LNode *) malloc(sizeof(LNode));
    q->data = e;
    q->next = L->next;
    L->next = q;
    return true;
}

bool insertHead2(LinkedList &L) {
    // 如果L是初始化过的带头结点的链表, 下面两句给L赋值头结点的操作可以省略.
//    L = (LNode *) malloc(sizeof(LNode));
//    L->next = NULL;
    int value;
    scanf("%d", &value);
//    p->data = value;
//    p->next = NULL;
//    L->next = p;
    while (value != 9999) {
        LNode *q = (LNode *) malloc(sizeof(LNode));
        q->data = value;
        q->next = L->next;
        L->next = q;
        scanf("%d", &value);
    }
}

bool tailInsert(LinkedList &L, ElementType e) {
    LNode *p = L;
    while (p->next != NULL) {
        p = p->next;
    }
    LNode *q = (LNode *) malloc(sizeof(LNode));
    q->data = e;
    p->next = q;
    return true;
}

bool tailInsert2(LinkedList &L) {
    // 如果L是初始化过的带头结点的链表, 下面两句给L赋值头结点的操作可以省略.
//    L = (LNode *) malloc(sizeof(LNode));
//    L->next = NULL;
    int value;
    scanf("%d", &value);
    LNode *tail = L;
    while (value != 9999) {
        LNode *q = (LNode *) malloc(sizeof(LNode));
        q->data = value;
        q->next = NULL;

        tail->next = q;
        tail = q;
        scanf("%d", &value);
    }

    return true;
}

#endif //CS_WANGDAO_LNODE_H
