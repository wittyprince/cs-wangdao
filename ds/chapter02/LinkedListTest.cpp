//
// Created by 51676 on 2024/7/23.
//

#include "LinkedList.h"

int main() {
    LinkedList L;
    initLinkedListWithoutHead(L);
    insertIntoLinkedListWithoutHead(L, 1, 1);
    insertIntoLinkedListWithoutHead(L, 2, 2);

    printLinkedListWithoutHead(L);

    return 0;
}