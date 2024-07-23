//
// Created by 51676 on 2024/7/23.
//

#ifndef CS_WANGDAO_LINKEDQUEUE_H
#define CS_WANGDAO_LINKEDQUEUE_H

#include <stdlib.h>

typedef int ElementType;

// 链式队列的结点
typedef struct linkedNode {
    ElementType data;
    struct linkedNode *next;
} LinkedNode;

// 链式队列
typedef struct linkedQueue {
//    LinkedNode *data;
    LinkedNode *front, *rear;
} LinkedQueue;

// 初始化-带头结点的队列
void initLinkedQueueWithHead(LinkedQueue &Q) {
    LinkedNode *head = (LinkedNode *) malloc(sizeof(LinkedNode));
    head->data = 0;
    head->next = NULL;
    Q.front = Q.rear = head;
}

// 初始化-不带头结点的队列
void initLinkedQueueWithoutHead(LinkedQueue &Q) {
    Q.front = Q.rear = NULL;
}


// 是否为空-带头结点
bool isLinkedQueueEmptyWithHead(LinkedQueue Q) {
    bool isEmpty = Q.front->next == NULL;
    // 由于是带头结点的, 所以front始终指向头结点
    // 所以 还可以使用Q.front == Q.rear 即Q.rear是否指向Q.front来判断链队中是否有其他节点
//    isEmpty = Q.front == Q.rear;
    return isEmpty;
}

// 是否为空-不带头结点
bool isLinkedQueueEmptyWithoutHead(LinkedQueue Q) {
    bool isEmpty = Q.front == NULL;
    // 也可以使用Q.rear == NULL 来判断, 即尾指针所指向的队尾元素为NULL
//    isEmpty = Q.rear == NULL;
    return isEmpty;
}

// 入队-带头结点
bool enLinkedQueueWithHead(LinkedQueue &Q, ElementType e) {
    // 这里不像顺序队列那样需要判断当前队列是否队满
    LinkedNode *tmp = (LinkedNode *) malloc(sizeof(LinkedNode));
    tmp->data = e;
    tmp->next = NULL;
    // 由于队列的特性, 所以只能在rear入队,
    // 即只能使用尾插法, 不能使用头插法
    // 由于是带头结点的队列, 所以不需要特殊处理 从空->非空时的结点改变
    Q.rear->next = tmp;
    Q.rear = tmp;
    return true;
}

// 入队-不带头结点
bool enLinkedQueueWithoutHead(LinkedQueue &Q, ElementType e) {
    // 这里不像顺序队列那样需要判断当前队列是否队满
    LinkedNode *tmp = (LinkedNode *) malloc(sizeof(LinkedNode));
    tmp->data = e;
    tmp->next = NULL;
    // 由于队列的特性, 所以只能在rear入队,
    // 即只能使用尾插法, 不能使用头插法
    // 由于是不带头结点的队列, 所以需要特殊处理 从空->非空时的结点改变
    if (Q.front == NULL || Q.rear == NULL) { // 判断当前队列为空
        Q.front = Q.rear = tmp;
    } else {
        Q.rear->next = tmp;
        Q.rear = tmp;
    }
    return true;
}

// 出队-带头结点
bool deLinkedQueueWithHead(LinkedQueue &Q, ElementType &e) {
    // 判断队列是否为空
    if (Q.front->next == NULL || Q.front == Q.rear) {
        return false;
    }
    // 出队
    LinkedNode *tmp = Q.front->next;
    e = tmp->data;
    Q.front->next = tmp->next;
    // 需要判断 当前tmp结点是否为最后一个节点,
    // 如果是的, 说明rear指针也要指向当前tmp节点, 需要修改rear指针,
    // 因为在free(tmp) 后, rear指针指向会有问题
    // 两种判断方式 1. tmp->next == NUll; 2.rear == tmp
    if (tmp->next == NULL) {
        Q.rear = Q.front;
    }
    free(tmp);
    return true;
}

// 出队-不带头结点
bool deLinkedQueueWithoutHead(LinkedQueue &Q, ElementType &e) {
    // 判断队列是否为空
    if (Q.front == NULL || Q.rear == NULL) {
        return false;
    }
    // 出队
    LinkedNode *tmp = Q.front;
    e = tmp->data;
    Q.front = tmp->next;
    // 需要判断 当前tmp结点是否为最后一个节点,
    // 如果是的, 说明rear指针也要指向当前tmp节点, 需要修改rear指针,
    // 因为在free(tmp) 后, rear指针指向会有问题
    // 两种判断方式 1. tmp->next == NUll; 2.rear == tmp
    if (Q.front == NULL) {
        Q.rear = Q.front;
    }
    // 下面判断条件 与 Q.front == NULL 起到同样效果
//    if (Q.rear == tmp) {
//        Q.rear = NULL;
//    }
    free(tmp);
    return true;
}


#endif //CS_WANGDAO_LINKEDQUEUE_H
