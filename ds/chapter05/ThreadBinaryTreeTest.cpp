//
// Created by 51676 on 2024/7/30.
//
#include "ThreadBinaryTree.h"

int main() {

    // 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 9999

    ThreadBinaryTree root = NULL;
//    levelCreateTree(root);
    root = (ThreadBinaryTreeNode *) calloc(1, sizeof(ThreadBinaryTreeNode));
    root->data = 1;

    ThreadBinaryTreeNode *left = (ThreadBinaryTreeNode *) calloc(1, sizeof(ThreadBinaryTreeNode));
    left->data = 2;
    ThreadBinaryTreeNode *right = (ThreadBinaryTreeNode *) calloc(1, sizeof(ThreadBinaryTreeNode));
    right->data = 3;
    root->leftChild = left;
    root->rightChild = right;

    ThreadBinaryTreeNode *left_right = (ThreadBinaryTreeNode *) calloc(1, sizeof(ThreadBinaryTreeNode));
    left_right->data = 4;
    left->rightChild = left_right;
    ThreadBinaryTreeNode *right_left = (ThreadBinaryTreeNode *) calloc(1, sizeof(ThreadBinaryTreeNode));
    right_left->data = 5;
    right->leftChild = right_left;

    printf("\n===levelOrder===\n");
    levelOrder(root);

//    inThreadCreateTree(root);
//    printf("\n===inOrder===\n");
//    inOrder(root);
//    printf("\n===\n");
//
//    ThreadBinaryTreeNode * firstNode = getFirstNode(root);
//    printf("firstNode:%3d\n", firstNode->data);
//
//    ThreadBinaryTreeNode * nextNode = getNextNode(root);
//    printf("nextNode:%3d\n", nextNode == NULL ? 0 : nextNode->data);
//
//    printf("\n===inOrderNonRecursive===\n");
//    inOrderNonRecursive(root);
//    printf("\n");
//
//    ThreadBinaryTreeNode * lastNode = getPreviousNode(right_left);
//    printf("lastNode:%3d\n", lastNode == NULL ? 0 : lastNode->data);
//
//    printf("\n===reverseInOrderNonRecursive===\n");
//    reverseInOrderNonRecursive(root);

    preThreadCreateTree(root);
    printf("\n===preOrder===\n");
    preOrder(root);
    printf("\n===preOrderNonRecursive===\n");
    preOrderNonRecursive(root);

    return 0;
}