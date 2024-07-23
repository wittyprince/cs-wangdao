//
// Created by 51676 on 2024/7/16.
//

#include <stdio.h>
#include "LinkedList.h"

// 头插法 reverse
bool reverseLinkedList(LinkedList &L) {
    LNode *p = L->next; // 工作指针，相当于游标
    LNode *q; // 用于接收p的后继节点, 防止断链
    L->next = NULL;
    while (p != NULL) {
        q = p->next; // 用于接收p的后继节点, 防止断链
        // 头插法, 把p插入到链表头部
        p->next = L->next;
        L->next = p;
        // 游标后移
        p = q;
    }

    return true;
}


int main() {

    LinkedList L;
    initLinkedList2(L);
    for (int i = 1; i < 6; ++i) {
        headInsert(L, i);
    }
    printLinkedList(L);
    printf("1===\n");

    reverseLinkedList(L);
    printLinkedList(L);


    return 0;
}
