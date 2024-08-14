//
// Created by 51676 on 2024/8/14.
//

#include <stdio.h>
#include <stdlib.h>

// 判断给定的二叉树是否是二叉排序树

typedef int ElementType;

typedef struct bstNode {
    ElementType data;
    struct bstNode *left, *right;
} BSTNode, *BST;

/**
 * 二叉排序树：
 *     或者是一棵空树, 或者具有下列特性：
 *         1. 若左子树非空, 则左子树上的所有节点的值均 小于 根节点的值。
 *         2. 若右子树非空, 则右子树上的所有节点的值均 大于 根节点的值。
 *         3. 左、右子树也分别是一棵二叉排序树。
 * 即 左 < 根 < 右
 *
 * 中序遍历法
 * previous: 当前节点的中序前驱
 */
bool inOrderRecurse(BST root, int &previous) {
    // 为空
    if (root == NULL) {
        return true;
    }
    bool b1 = false, b2 = false;
    // 左子树
    b1 = inOrderRecurse(root->left, previous);
    // 以下类似visit()函数
    if (!b1 || previous > root->data) {
        return false;
    }
    previous = root->data; // 更新中序前驱
    // 右子树
    b2 = inOrderRecurse(root->right, previous);
    return b2;
}

bool judgeBST(BST root) {
    int previous = -9999; // 这里假设-9999为最小值, 其逻辑上可以认为是升序序列的第一个元素的前驱
    return inOrderRecurse(root, previous);
}

int main() {

    BST root = (BST)calloc(1, sizeof(BSTNode));
    root->data = 5;
    BST t21 = (BST)calloc(1, sizeof(BSTNode));
    t21->data = 4;
    BST t22 = (BST)calloc(1, sizeof(BSTNode));
    t22->data = 8;
    BST t31 = (BST)calloc(1, sizeof(BSTNode));
    t31->data = 1;
    BST t32 = (BST)calloc(1, sizeof(BSTNode));
    t32->data = 7;
    BST t33 = (BST)calloc(1, sizeof(BSTNode));
    t33->data = 9;
    root->left = t21;
    root->right = t22;
    t21->left = t31;
    t21->right = t32;
    t22->right = t33;

    bool b = judgeBST(root);
    printf("%d", b);

    return 0;
}