//
// Created by 51676 on 2024/7/15.
//

#ifndef CS_WANGDAO_LINKEDLIST_H
#define CS_WANGDAO_LINKEDLIST_H

#include <stdlib.h>
#include <stdio.h>

typedef int ElementType;

// 单链表的数据结构-节点
typedef struct lnode {
    ElementType data;
    struct lnode *next;
} LNode;

// 把(LNode *)重命名为 LinkedList
typedef LNode *LinkedList;

// 初始化-带头结点的单链表
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

// 初始化-不带头结点的单链表
bool initLinkedListWithoutHead(LinkedList &L) {
    L = NULL;
    return true;
}

// 是否为空-带头结点
bool isLinkedListEmpty(LinkedList L) {
    return L->next == NULL;
}

// 是否为空-不带头结点
bool isLinkedListEmptyWithoutHead(LinkedList L) {
    return L == NULL;
}

// 求表长
int lengthOfLinkedList(LinkedList L) {
    int length = 0;
    LNode *p = L; // 游标指针p
    while (p->next != NULL) { // 这里从p->next开始, 是因为L是带头结点的单链表
        p = p->next;
        length++;
    }
    return length;
}

// 按序号查找结点
LNode *getElement(LinkedList L, int pos) {
    LNode *p = L; // 游标指针p指向当前扫描到的结点
    int i = 0; // 记录当前节点的位序, 头结点是第0个结点
    while (p != NULL && i < pos) {
        p = p->next;     // 最后一次遍历时, 这里p会等于p->next
        i++;
    }
    return p;
}

// 按值查找结点
LNode *locateElement(LinkedList L, ElementType e) {
    LNode *p = L->next; // 跳过头结点, 从第一个节点开始查找
    while (p != NULL && p->data != e) {
        p = p->next;
    }
    return p;
}

// 按位序插入-带头结点
// 在第pos个位置上插入元素e
// 方法一: 后插操作, 在某结点 后面 插入一个新结点。
//      本示例使用的是后插操作。
//      只不过把pos-1位置上的结点当做"某节点", 即 找到第 pos -1 个结点, 然后在其后插入新结点(包含元素e的)
// 方法二: 前插操作, 在某节点 前面 插入一个新节点。
//      如果把pos位置上的结点当做"某结点", 在其前面进行插入新结点操作, 此时即为前插操作。
//      但是前插操作也可以转换为后插操作, 即通过遍历找到pos位置的前一个节点pos-1, 然后对其进行后插操作即可。
// 方法三: 交换值域的方式
//      在pos位置上插入一个新结点, 本意是在pos前面插入新结点,
//      那么我们可以转换为在pos位置后面插入新结点, 然后把pos位置上的值域与新结点的值域进行互换, 可以达到目的。
//      此方法的好处是时间复杂度为O(1)
bool insertIntoLinkedList(LinkedList &L, int pos, ElementType e) {
    if (pos < 1) { // 位置pos从1开始
        return false;
    }
    LNode *p = L; // 游标, 指向当前扫描到的节点
    int i = 0; // 当前游标p指向的是第几个结点, 头结点是第0个结点
    // 经过遍历 i < pos -1 得到的p为要插入位置的前一个节点, 即第pos-1个结点
    while (p != NULL && i < pos -1) {
        p = p->next;
        i++;
    }
    // 如果p为NULL, 那么表明要插入位置的前一个节点为NULL, 要插入位置为无效位置
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

// 按位序插入-不带头结点
bool insertIntoLinkedListWithoutHead(LinkedList &L, int pos, ElementType e) {
    if (pos < 1) { // 位置pos从1开始
        return false;
    }
    LNode *tmp = (LNode *) malloc(sizeof(LNode));
    tmp->data = e;
    tmp->next = NULL;

    // 如果要插入的位置为1, 那么需要改变L的指向
    // 否则, L的指向不会发生改变(指向第一个节点)
    // 所以这里需要根据pos是否为1来进行处理
    if (pos == 1) { // 其实这里包含了L为空的情形
        tmp->next = L;
        L = tmp;
        return true;
    }

    // 如果当前链表为NULL, 那么直接作为第一个结点插入
//    if (L == NULL) {
//        L = tmp;
//        return true;
//    }

    // 处理完是否为第一个节点的特殊情况后, 后续节点处理方式与带头结点的类似
    int j = 1; // 变量
    LNode *cursor = L; // 游标
    while (cursor != NULL && j < pos -1) { // 找到pos位置前一个元素
        cursor = cursor->next;
        j++;
    }
    // 如果p为NULL, 那么表明要插入位置的前一个节点为NULL, 要插入位置为无效位置
    if (cursor == NULL) {
        return false;
    }
    tmp->next = cursor->next;
    cursor->next = tmp;
    return true;
}

// 删除第pos个位置上的结点, 并用e返回被删除节点的值
// 方法一: 找前驱结点, 然后删除该前驱结点的后继结点(即pos位置上的结点)
//      找到pos的前一个结点pos-1, 然后在对pos位置上的结点进行删除操作
// 方法二: 交换值域方式
//      找到pos的后继结点, 把pos位置上结点的值与其后继结点的值进行互换,
//      然后删除其后继几点即可。
//      此方法的好处是时间复杂度为O(1)
bool deleteFromLinkedList(LinkedList &L, int pos, ElementType &e) {
    if (pos < 1) { // 位置pos从1开始
        return false;
    }
    LNode *p = L; // 游标, 指向当前扫描到的节点
    int i = 0; // 记录当前游标p的位序, 头结点是第0个结点
    // 经过遍历 i < pos -1 得到的p为要删除位置的前一个节点
    // 即第pos-1个结点, 即此时p为第pos-1个结点, i = pos -1;
    while (p != NULL && i < pos -1) {
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

// 头插法-带头结点
//      逆向建立单链表
bool headInsert(LinkedList &L, ElementType e) {
    LNode *q = (LNode *) malloc(sizeof(LNode));
    q->data = e;
    q->next = L->next;
    L->next = q;
    return true;
}

// 头插法-带头结点
//      逆向建立单链表
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
    q->next = NULL;
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

void printLinkedList(LinkedList L) {
    LNode *p = L->next;
    while (p != NULL) {
        printf("%3d", p->data);
        p = p->next;
    }
    printf("\n");
}

void printLinkedListWithoutHead(LinkedList L) {
    LNode *p = L;
    while (p != NULL) {
        printf("%3d", p->data);
        p = p->next;
    }
    printf("\n");
}

#endif //CS_WANGDAO_LINKEDLIST_H
