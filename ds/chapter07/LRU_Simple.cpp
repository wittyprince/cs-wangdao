//
// Created by 51676 on 2024/8/9.
//

#include <stdio.h>
#include <stdlib.h>

// 简易版LRU

void printArray(int a[], int length) {
    for (int i = 0; i < length; ++i) {
        printf("%3d", a[i]);
    }
    printf("\n");
}

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void searchAndExchange(int a[], int length, int target) {
    if (a[0] == target) {
        return;
    }
    for (int i = 1; i < length; ++i) {
        if (a[i] == target) {
            swap(a[i - 1], a[i]);
        }
    }
}

// ======================================
typedef struct linkedNode {
    int data;
    struct linkedNode *next;
} LinkedNode, *LinkedList;

void printLinkedList(LinkedList linkedList) {
    LinkedNode *firstNode = linkedList->next;
    while (firstNode != NULL) {
        printf("%3d",firstNode->data);
        firstNode = firstNode->next;
    }
    printf("\n");
}

void searchAndExchange2(LinkedList linkedList, int target) {
    if (linkedList == NULL) {
        return;
    }
    LinkedNode *previous = linkedList;
    LinkedNode *current = linkedList->next;
    if (current != NULL && current->data == target) {
        return;
    }
    previous = current;
    current = current->next;
    while (current != NULL && current->data != target) {
        previous = current;
        current = current->next;
    }
    if (current != NULL) {
        swap(previous->data, current->data);
    }
}
// ======================================

int main() {
    int a[] = {1, 2, 3, 4, 5};
    printArray(a, 5);

    searchAndExchange(a, 5, 6);
    printArray(a, 5);

    printf("\n====================\n");

    //==========================================
    LinkedList linkedList = (LinkedList)malloc(sizeof(LinkedNode));
    linkedList->data = 0;
    linkedList->next = NULL;
    LinkedNode *n1 = (LinkedNode *) calloc(1, sizeof(LinkedNode));
    n1->data = 1;
    LinkedNode *n2 = (LinkedNode *) calloc(1, sizeof(LinkedNode));
    n2->data = 2;
    LinkedNode *n3 = (LinkedNode *) calloc(1, sizeof(LinkedNode));
    n3->data = 3;
    LinkedNode *n4 = (LinkedNode *) calloc(1, sizeof(LinkedNode));
    n4->data = 4;
    LinkedNode *n5 = (LinkedNode *) calloc(1, sizeof(LinkedNode));
    n5->data = 5;
    linkedList->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = NULL;
    printLinkedList(linkedList);
    searchAndExchange2(linkedList, 6);
    printLinkedList(linkedList);



    return 0;
}

