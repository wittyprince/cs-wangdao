//
// Created by 51676 on 2024/7/26.
//
#include <stdlib.h>
#include "BinaryTree.h"

//#define MaxSize 10


void visit(BinaryTreeNode *node) {
    printf("%3d", node->data.value);
}

// 先序遍历
void preOrder(BinaryTree root) {
    if (root != NULL) {
        visit(root);
        preOrder(root->left);
        preOrder(root->right);
    }
}

// 中序遍历
void inOrder(BinaryTree root) {
    if (root != NULL) {
        inOrder(root->left);
        visit(root);
        inOrder(root->right);
    }
}

void postOrder(BinaryTree root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        visit(root);
    }
}

int main() {

    // 声明一个二叉树数组
    TreeNode tree[10];

    // 定义一棵空树
    BinaryTree root = NULL;
    // 插入根结点
    root = (BinaryTree) malloc(sizeof(BinaryTreeNode));
    // {}这种赋值方式是因为BinaryTreeNode的数据域data的数据类型ElementType声明为了结构体struct
    // 数据类型ElementType声明为简单类型, 如int, 则直接使用root->data = 1; 即可
    int rootValue;
    scanf("%d", &rootValue);
    root->data = {rootValue};
    root->left = NULL;
    root->right = NULL;
//    // 插入新结点
//    // 1.声明新结点
//    BinaryTreeNode *tmp = (BinaryTreeNode *) malloc(sizeof(BinaryTreeNode));
//    tmp->data = {2};
//    tmp->left = NULL;
//    tmp->right = NULL;
//    // 2.关联结点
//    root->left = tmp;

    // 声明一个链表-
    BinaryTreeLinkedList treeLinkedList = (BinaryTreeLinkedNode *) malloc(sizeof(BinaryTreeLinkedNode));
    treeLinkedList->treeData = root;
    treeLinkedList->treeNext = NULL;
    BinaryTreeLinkedNode *tail = treeLinkedList; // 声明一个尾指针
    BinaryTreeLinkedNode *current = treeLinkedList; // 声明一个游标, 表示当前正在处理的树节点

    int value;
    while (scanf("%d", &value) && value != 9999) {
        // 树节点, 用于接收数据
        BinaryTreeNode *tmp1 = (BinaryTreeNode *) malloc(sizeof(BinaryTreeNode));
        tmp1->data = {value};
        tmp1->left = tmp1->right = NULL;

        // 链表节点, 用于遍历
        BinaryTreeLinkedNode *tmp2 = (BinaryTreeLinkedNode *) malloc(sizeof(BinaryTreeLinkedNode));
        tmp2->treeData = tmp1;
        tmp2->treeNext = NULL;
        // 尾插法进入链表
        tail->treeNext = tmp2;
        tail = tmp2;

        // 判断要插入的树节点的位置 及 调整当前正在处理的树节点current
        BinaryTreeNode *currentTreeNode = current->treeData;
//        if (root == NULL) {
//            root = tmp1;
//            tail->next = tmp2;
//            tail = tmp2;
//        } else {
            if (currentTreeNode->left == NULL) {
                currentTreeNode->left = tmp1;
            } else if (currentTreeNode->right == NULL) {
                currentTreeNode->right = tmp1;
                // 右子树时, 要把current向后移动一个位置
                current = current->treeNext;
            }
//        }

    }



    inOrder(root);


    return 0;
}