//
// Created by 51676 on 2024/7/16.
//

#include <stdio.h>
#include "LinkedList.h"

void splitLinkedList(LinkedList L, LinkedList &A, LinkedList &B) {
    // 判断L->next 是否为空

    LNode *p = L->next; // 工作节点, 相当于游标, 奇数
    LNode *q = p->next; // 工作节点, 相当于游标, 偶数
    LNode *pNext;
    LNode *qNext;
    LNode *ar = A; // A的尾指针
    while (p != NULL && q != NULL) {
        pNext = p->next->next; // 用于接收p的后继节点, 防止断链
        qNext = q->next->next; // 用于接收q的后继节点, 防止断链
//        q = p->next;
        // 尾插法 插入到A
        p->next = NULL;
        ar->next = p;
        ar = p;

        // 头插法 插入到B
        q->next = B->next;
        B->next = q;

        p = pNext;
        q = qNext;
        if (p->next == NULL || q->next == NULL) {
            // 尾插法 插入到A
            p->next = NULL;
            ar->next = p;
            ar = p;

            // 头插法 插入到B
            q->next = B->next;
            B->next = q;
            break;
        }
    }

    ar->next = NULL;

}

void splitLinkedList2(LinkedList L, LinkedList &A, LinkedList &B) {
    LNode *p = L->next;
    LNode *ar = A, *pNext, *qNext;
    while (p != NULL) {
        pNext = p->next; // 用于接收p的后继节点, 防止断链

        // 尾插法 处理A
        p->next = NULL;
        ar->next = p;
        ar = p;

        p = pNext; // 这里处理B
        if (p != NULL) {
            // 头插法 处理 B
            qNext = p->next; // 用于接收q的后继节点, 防止断链
            p->next = B->next;
            B->next = p;

            p = qNext;
        }

    }

}


int main() {

    LinkedList L;
    initLinkedList2(L);
    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) {
            tailInsert(L, 20 + i);
        } else {
            tailInsert(L, 10 + i);
        }
    }
    printLinkedList(L);
    printf("1===\n");

    LinkedList A;
    initLinkedList2(A);
    LinkedList B;
    initLinkedList2(B);

    splitLinkedList2(L, A, B);
    printLinkedList(A);
    printLinkedList(B);


    return 0;
}
