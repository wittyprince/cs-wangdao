//
// Created by 51676 on 2024/8/8.
//

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct bstNode {
    ElementType data;
    struct bstNode *left, *right;
} BSTNode, *BST;

// 二叉排序树-非递归方式
BSTNode *BST_Search(BST T, ElementType e) {
    while (T != NULL && T->data != e) {
        if (T->data > e) {
            T = T->left;
        } else {
            T = T->right;
        }
    }
    return T;
}

// 二叉排序树-递归方式
BSTNode *BST_Search_Recursive(BST T, ElementType e) {
    if (T == NULL || T->data == e) {
        return T;
    }
    if (T->data > e) {
        return BST_Search_Recursive(T->left, e);
    } else {
        return BST_Search_Recursive(T->right, e);
    }
}

int main() {

    BSTNode *n1 = (BSTNode *) calloc(1, sizeof (BSTNode));
    n1->data = 1;
    BSTNode *n2 = (BSTNode *) calloc(1, sizeof (BSTNode));
    n2->data = 2;
    BSTNode *n3 = (BSTNode *) calloc(1, sizeof (BSTNode));
    n3->data = 3;
    BSTNode *n4 = (BSTNode *) calloc(1, sizeof (BSTNode));
    n4->data = 4;
    BSTNode *n6 = (BSTNode *) calloc(1, sizeof (BSTNode));
    n6->data = 6;
    BSTNode *n8 = (BSTNode *) calloc(1, sizeof (BSTNode));
    n8->data = 8;

    n6->left = n2;
    n6->right = n8;
    n2->left = n1;
    n2->right = n4;
    n4->left = n3;

    BSTNode * node = BST_Search(n6, 3);
    if (node != NULL) {
        printf("%3d\n", node->data);
    } else {
        printf("search failed");
    }

    BSTNode * node2;
    node2 = BST_Search_Recursive(n6, 3/*, node2*/);
    if (node2 != NULL) {
        printf("%3d", node2->data);
    } else {
        printf("search failed\n");
    }


    return 0;
}