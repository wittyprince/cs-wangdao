//
// Created by 51676 on 2024/7/30.
//
#include "ThreadBinaryTree.h"

int main() {

    // 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 9999

    ThreadBinaryTree root = NULL;
    levelCreateTree(root);

    inThreadCreateTree(root);
    printf("===\n");
    levelOrder(root);

    return 0;
}