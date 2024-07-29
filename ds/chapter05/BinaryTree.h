//
// Created by 51676 on 2024/7/25.
//

#ifndef CS_WANGDAO_BINARYTREE_H
#define CS_WANGDAO_BINARYTREE_H

// 二叉树
#include <stdio.h>

//typedef int ElementType;
typedef struct elementType {
    int value;
} ElementType;

// 顺序存储结构的树节点
typedef struct treeNode {
    ElementType value; // 节点中的数据元素
    bool isEmpty; // 节点是否为空
} TreeNode;

// 链式存储结构的树节点
typedef struct binaryTreeNode {
    ElementType data; // 数据域
    struct binaryTreeNode *left, *right; // 左孩子指针, 右孩子指针
//    struct binaryTreeNode *parent; // 父节点指针, 根据情况可以有
} BinaryTreeNode, *BinaryTree;

// 用于构造数的辅助队列
// 辅助队列-链式队列的结点
typedef struct binaryTreeLinkedNode {
    BinaryTreeNode *treeData;                // 数据域, 树的某一个节点的地址
    struct binaryTreeLinkedNode *treeNext;   // 指针
} BinaryTreeLinkedNode, *BinaryTreeLinkedList;

// 队列主要用于树结点的出队操作, 如果只是入队遍历, 其实单链表也可以
//typedef struct binaryTreeLinkedQueue {
//    BinaryTreeLinkedNode *front; // 头指针
//    BinaryTreeLinkedNode *rear;  // 尾指针
//} BinaryTreeLinkedQueue;

#endif //CS_WANGDAO_BINARYTREE_H
