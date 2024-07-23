//
// Created by 51676 on 2024/7/23.
//

#include <stdio.h>
#include "LinkedQueue.h"

int main() {
    LinkedQueue Q;
    initLinkedQueueWithoutHead(Q);
    enLinkedQueueWithoutHead(Q, 1);
    ElementType e;
    deLinkedQueueWithoutHead(Q, e);

    return 0;
}