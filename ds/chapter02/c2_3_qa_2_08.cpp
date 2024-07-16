//
// Created by 51676 on 2024/7/16.
//

#include <stdio.h>
#include "LNode.h"

void extractSameElement(LinkedList L1, LinkedList L2, LinkedList &L3) {
    LNode *p = L1->next;
    LNode *q = L2->next;
    LNode *r3 = L3;
    while (p != NULL && q != NULL) {

        if (p->data < q->data) {
            p = p->next;
        } else if (p->data > q->data) {
            q = q->next;
        } else {
            LNode *tmp = (LNode *) malloc(sizeof (LNode));
            tmp->data = p->data;
            tmp->next = NULL;
            // 尾插法 插入L3
            r3->next = tmp;
            r3 = tmp;

            p = p->next;
            q = q->next;
        }

    }

    r3->next = NULL;
}

int main() {

    LinkedList L;
    initLinkedList2(L);
    LinkedList L2;
    initLinkedList2(L2);
    for (int i = 0; i < 12; i++) {
        if (i % 2 == 0) {
            tailInsert(L, 20 + i);
        } else {
            tailInsert(L2, 16 + 2 * i);
        }
    }
    printLinkedList(L);
    printLinkedList(L2);
    printf("1===\n");

    LinkedList L3;
    initLinkedList2(L3);

    extractSameElement(L, L2, L3);
    printLinkedList(L3);

    return 0;
}
