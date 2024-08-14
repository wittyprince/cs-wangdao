//
// Created by 51676 on 2024/8/14.
//
#include <stdio.h>
#include <stdlib.h>

// 指定节点在二叉排序树中的层次

typedef int ElementType;

typedef struct bstNode {
    ElementType data;
    struct bstNode *left, *right;
} BSTNode, *BST;

/**
 * 指定节点在二叉排序树中的层次
 *    - 能找到 ?
 *    - 找不到 ?
 * @param root
 * @param treeNode
 */
int level(BST root, BSTNode *treeNode) {
    BSTNode *t = root;
    int level = 0;
//    if (root != NULL) {
//        level++;
//    }
    while (t != NULL) {
        level++;
        if (t->data == treeNode->data) {
            return level;
        } else {
            if (treeNode->data < t->data) {
                t = t->left;
            } else if (treeNode->data > t->data){
                t = t->right;
            }/* else {
                printf("===========");
            }*/
        }
    }
    return level;
}

int main() {
    BST root = (BST)calloc(1, sizeof(BSTNode));
    root->data = 4;
    BSTNode *t21 = (BST)calloc(1, sizeof(BSTNode));
    t21->data = 2;
    BSTNode *t22 = (BST)calloc(1, sizeof(BSTNode));
    t22->data = 5;
//    BSTNode *t31 = (BST)calloc(1, sizeof(BSTNode));
//    t31->data = 1;
//    BSTNode *t32 = (BST)calloc(1, sizeof(BSTNode));
//    t32->data = 3;
//    BSTNode *t33 = (BST)calloc(1, sizeof(BSTNode));
//    t33->data = 6;
    root->left = t21;
    root->right = t22;
//    t21->left = t31;
//    t21->right = t32;
//    t22->right = t33;

    BSTNode *p = (BST)calloc(1, sizeof(BSTNode));
    p->data = 0;

    int a = level(root, p);
    printf("%d\n", a);

    return 0;
}