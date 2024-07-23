//
// Created by 51676 on 2024/7/16.
//

#include <stdio.h>
#include "LinkedList.h"

void deleteDuplicate(LinkedList &L) {
    LNode *prior = L;
    LNode *p;
    while (prior != NULL && prior->next != NULL) {
        p = prior->next;
        if (prior->data == p->data) {
            prior->next = p->next;
            free(p);
        } else {
            prior = prior->next;
        }
    }

}

int main() {

    LinkedList L;
    initLinkedList2(L);
    tailInsert(L, 7);
    tailInsert(L, 10);
    tailInsert(L, 10);
    tailInsert(L, 21);
    tailInsert(L, 30);
    tailInsert(L, 42);
    tailInsert(L, 42);
    tailInsert(L, 42);
    tailInsert(L, 51);
    tailInsert(L, 70);
    printLinkedList(L);
    printf("1===\n");

    deleteDuplicate(L);
    printLinkedList(L);


    return 0;
}
