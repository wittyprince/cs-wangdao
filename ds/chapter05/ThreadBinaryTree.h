//
// Created by 51676 on 2024/7/30.
//

#ifndef CS_WANGDAO_THREADBINARYTREE_H
#define CS_WANGDAO_THREADBINARYTREE_H

#include <stdlib.h>
#include <stdio.h>

// 线索二叉树
// ==========Tree struct start==========
typedef int ElementType;

typedef struct threadBinaryTreeNode {
    ElementType data;
    struct threadBinaryTreeNode *leftChild, *rightChild;
    int leftThread, rightThread;
} ThreadBinaryTreeNode, *ThreadBinaryTree;

typedef struct threadBinaryTreeLinkedNode {
    ThreadBinaryTreeNode *treeData;
    struct threadBinaryTreeLinkedNode *treeNext;
} ThreadBinaryTreeLinkedNode, ThreadBinaryTreeLinkedList;

typedef struct threadBinaryTreeQueue {
    ThreadBinaryTreeLinkedNode *front;
    ThreadBinaryTreeLinkedNode *rear;
} ThreadBinaryTreeQueue;
// ==========Tree struct end==========

// ==========Queue method end==========
void initQueue(ThreadBinaryTreeQueue &Q) {
    ThreadBinaryTreeLinkedNode *head = (ThreadBinaryTreeLinkedNode *) malloc(sizeof(ThreadBinaryTreeLinkedNode));
    head->treeData = NULL;
    head->treeNext = NULL;
    Q.front = Q.rear = head;
}

bool isQueueEmpty(ThreadBinaryTreeQueue Q) {
    return Q.front == Q.rear || Q.front->treeNext == NULL;
}

void enQueue(ThreadBinaryTreeQueue &Q, ThreadBinaryTreeNode *treeNode) {
    if (treeNode == NULL) {
        return;
    }
    ThreadBinaryTreeLinkedNode *linkedNode = (ThreadBinaryTreeLinkedNode *) malloc(sizeof(ThreadBinaryTreeLinkedNode));
    linkedNode->treeData = treeNode;
    linkedNode->treeNext = NULL;
    Q.rear->treeNext = linkedNode;
    Q.rear = Q.rear->treeNext;
}

bool deQueue(ThreadBinaryTreeQueue &Q, ThreadBinaryTreeNode *&treeNode) {
    // 判断队列是否为空
    if (Q.front == Q.rear || Q.front->treeNext == NULL) {
        return false;
    }

    // 判断队列是否只剩一个元素
    ThreadBinaryTreeLinkedNode *tmp = Q.front->treeNext;
    treeNode = tmp->treeData;
    Q.front->treeNext = tmp->treeNext;
    if (tmp->treeNext == NULL) {
        Q.rear = Q.front;
    }
    free(tmp);
    return true;
}

// ==========Queue method start==========

// ==========Tree method start==========
// 中序线索化
void visit(ThreadBinaryTreeNode *&current, ThreadBinaryTreeNode *&pre) {
    // 处理左子树, 如果左子树为空, 对左子树进行线索化
    // 这里没有对current进行右子树判断及处理,
    // 这是因为将current.leftChild的处理放在了后续pre.rightChild中进行了处理
    if (current->leftChild == NULL) {
        current->leftChild = pre;
        current->leftThread = 1;
    }
    if (pre != NULL && pre->rightChild == NULL) {
        pre->rightChild = current; // 建立前驱结点的后继
        pre->rightThread = 1;
    }
    pre = current;
}

void inThread(ThreadBinaryTreeNode *root, ThreadBinaryTreeNode *&pre) {
    if (root != NULL) {
        inThread(root->leftChild, pre);
        visit(root, pre);
        inThread(root->rightChild, pre);
    }
}

void inThreadCreateTree(ThreadBinaryTree root) {
    ThreadBinaryTreeNode *pre = NULL;
    if (root != NULL) {
        inThread(root, pre);
        //pre.rightChild
        if (pre->rightChild == NULL) {
            pre->rightThread = 1; // 处理遍历的最后一个节点, 线索化
        }
    }
}

// 层序建树
void levelCreateTree(ThreadBinaryTree &tree) {
    int value;
    scanf("%d", &value);
    ThreadBinaryTreeNode *root = (ThreadBinaryTreeNode *) malloc(sizeof(ThreadBinaryTreeNode));
    root->data = value;
    root->leftChild = root->rightChild = NULL;
    root->leftThread = root->rightThread = 0;

    tree = root;

    ThreadBinaryTreeLinkedNode *linkedList = (ThreadBinaryTreeLinkedNode *) malloc(sizeof(ThreadBinaryTreeLinkedNode));
    linkedList->treeData = root;
    linkedList->treeNext = NULL;
    ThreadBinaryTreeLinkedNode *tail = linkedList;
    ThreadBinaryTreeLinkedNode *current = linkedList;
    while (scanf("%d", &value) && value != 9999) {
        ThreadBinaryTreeNode *tmpTreeNode = (ThreadBinaryTreeNode *) calloc(1, sizeof(ThreadBinaryTreeNode));
        tmpTreeNode->data = value;

        ThreadBinaryTreeLinkedNode *tmpLinkedNode = (ThreadBinaryTreeLinkedNode *) malloc(sizeof(ThreadBinaryTreeLinkedNode));
        tmpLinkedNode->treeData = tmpTreeNode;
        tmpLinkedNode->treeNext = NULL;

        tail->treeNext = tmpLinkedNode;
        tail = tail->treeNext;

        // 左右子树
        ThreadBinaryTreeNode *currentTreeNode = current->treeData;
        if (currentTreeNode->leftChild == NULL) {
            currentTreeNode->leftChild = tmpTreeNode;
        } else if (currentTreeNode->rightChild == NULL) {
            currentTreeNode->rightChild = tmpTreeNode;
            current = current->treeNext;
        }
    }
}

void visitTreeNode(ThreadBinaryTreeNode *treeNode) {
    printf("%3d", treeNode->data);
}

void levelOrder(ThreadBinaryTree root) {
    ThreadBinaryTreeQueue Q;
    // 初始化Q
    initQueue(Q);
    // 入队
    enQueue(Q, root);
    ThreadBinaryTreeNode *treeNode = NULL;
    while (!isQueueEmpty(Q)) {
        deQueue(Q, treeNode);
        visitTreeNode(treeNode);
        if (treeNode->leftChild != NULL && treeNode->leftThread == 0) {
            enQueue(Q, treeNode->leftChild);
        }
        if (treeNode->rightChild != NULL && treeNode->rightThread == 0) {
            enQueue(Q, treeNode->rightChild);
        }
    }
}

// 找到以当前节点currentNode为根的子树中的, 第一个被中序遍历的节点
ThreadBinaryTreeNode *getFirstNode(ThreadBinaryTreeNode *currentNode) {
    while (currentNode != NULL && currentNode->leftThread == 0) {
        currentNode = currentNode->leftChild;
    }
    return currentNode;
}

// 在中序线索二叉树中找到当前节点currentNode的后继节点
ThreadBinaryTreeNode *getNextNode(ThreadBinaryTreeNode *currentNode) {
    if (currentNode->rightThread == 1) {
        return currentNode->rightChild;
    }
    return getFirstNode(currentNode->rightChild);
}

// 线索二叉树-中序遍历-非递归
void inOrderNonRecursive(ThreadBinaryTree root) {
    // 1. 找到根节点root的第一个要被遍历的节点
    ThreadBinaryTreeNode *firstNode = getFirstNode(root);
    ThreadBinaryTreeNode *nextNode = getNextNode(firstNode);
    // 2. 循环遍历firstNode的后继节点, 即可
    for (ThreadBinaryTreeNode* i = firstNode; i != NULL; i = getNextNode(i)) {
        visitTreeNode(i);
    }
}

// 线索二叉树-中序遍历-递归
void inOrder(ThreadBinaryTree root) {
    if (root != NULL) {
        if (root->leftThread == 0) {
            inOrder(root->leftChild);
        }
        visitTreeNode(root);
        if (root->rightThread == 0) {
            inOrder(root->rightChild);
        }
    }
}

// ==========Tree method end==========

#endif //CS_WANGDAO_THREADBINARYTREE_H