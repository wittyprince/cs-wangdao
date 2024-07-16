//
// Created by 51676 on 2024/7/16.
//

#include <stdio.h>
#include "LNode.h"

LNode * getMin(LinkedList &L) {
    LNode *p = L->next;
    LNode *min = p;
    while (p != NULL) {
        if (min->data > p->data) {
            min = p;
        }
        p = p->next;
    }
    return min;
}

bool deleteX(LinkedList &L, LNode *x) {
    LNode *p = L->next;
    LNode *prior = L;
    LNode *min = x;
//    for (; prior != NULL && p != NULL;) {
//        if (p->data == min->data) {
//            break;
//        }
//        prior = p;
//        p = p->next;
//    }
    while (prior != NULL && p != NULL) {
        if (p->data == min->data) {
            break;
        }
        prior = p;
        p = p->next;
    }
    // 这里一定存在最小值, 所以p不为空
    prior->next = p->next;
    free(p);
    return true;
}

bool getMinAndDelete(LinkedList &L) {
    LNode *p = L->next;
    LNode *prior = L;
    LNode *min = p;
    LNode *priorMin = prior;
    while (prior != NULL && p != NULL) {
        if (min->data > p->data) {
            min = p;
            priorMin = prior;
        }
        prior = p;
        p = p->next;
    }
    printf("%3d\n", min->data);

    priorMin->next = min->next;
    free(min);

    return true;
}

int main() {
    LinkedList L;
    initLinkedList2(L);
    headInsert(L, 1);
    headInsert(L, 2);
    headInsert(L, 3);
    headInsert(L, 4);
    headInsert(L, 5);

    printLinkedList(L);
    printf("1===\n");

    LNode *minNode = getMin(L);
    printf("%3d\n", minNode->data);

//    deleteX(L, minNode);
    getMinAndDelete(L);
    printLinkedList(L);

    return 0;
}