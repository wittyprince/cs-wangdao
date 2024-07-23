//
// Created by 51676 on 2024/7/15.
//
#include <stdio.h>

#include "LinkedList.h"

// 删除链表中所有值为e的节点
bool deleteTheElement(LinkedList &L, ElementType e) {
    LNode *prior = L;
    while (prior != NULL && prior->next != NULL) {
        LNode *p = prior->next;
        if (p->data == e) {
            prior->next = p->next;
            free(p);
        } else {
            prior = prior->next;
        }
    }
    return true;
}

int main() {

    LinkedList L;
    initLinkedList2(L);
//    int length = lengthOfLinkedList(L);
//    printf("%3d\n", length);
    headInsert(L, 1);
    headInsert(L, 2);
    headInsert(L, 3);
    headInsert(L, 3);
    headInsert(L, 5);

    printLinkedList(L);
    printf("1===\n");
    deleteTheElement(L, 3);
    printLinkedList(L);





    return 0;
}