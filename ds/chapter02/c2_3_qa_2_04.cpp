//
// Created by 51676 on 2024/7/16.
//

#include <stdio.h>
#include "LinkedList.h"

bool deleteBetween(LinkedList &L, ElementType a, ElementType b) {

//    LNode *p = L->next; // 工作指针, 相当于游标
    LNode *prior = L;

    while (prior != NULL && prior->next != NULL) {
        LNode *p = prior->next;
        if (p->data >= a && p->data <= b) {
            prior->next = p->next;
            free(p);
        } else {
            prior = p;
        }
    }
    return true;
}

bool deleteBetween2(LinkedList &L, ElementType a, ElementType b) {

    LNode *p = L->next; // 工作指针, 相当于游标
    LNode *prior = L;

    while (prior != NULL && p != NULL) {
        LNode *q = p;
        if (p->data >= a && p->data <= b) {
            prior->next = p->next;
            free(q);
            p = prior->next;
        } else {
            prior = p;
            p = p->next;
        }
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

    deleteBetween2(L, 1, 3);
    printLinkedList(L);


    return 0;
}
