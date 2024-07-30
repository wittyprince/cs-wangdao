//
// Created by 51676 on 2024/7/29.
//
#include <stdio.h>
#include <stdlib.h>
//#include "BinaryTree.h"

// ==========Tree struct start==========

typedef int TreeElementType;

typedef struct binaryTreeNode {
    TreeElementType data;
    struct binaryTreeNode *left, *right;
} BinaryTreeNode, *BinaryTree;

// 链表结构
typedef struct binaryTreeLinkedNode {
    BinaryTreeNode *treeData;
    struct binaryTreeLinkedNode *treeNext;
} BinaryTreeLinkedNode, *BinaryTreeLinkedList;

typedef struct binaryTreeQueue {
    BinaryTreeLinkedNode *front; // 队头指针, 指向队头元素
    BinaryTreeLinkedNode *rear; // 队尾指针, 指向队尾元素
} BinaryTreeQueue;

// ==========Tree struct end==========

// ==========Stack struct start==========
#define StackMaxSize 100
typedef struct stack {
    BinaryTreeNode* treeData[StackMaxSize]; // 栈中数据元素
    int top;  // 栈顶指针
} Stack;
// ==========Stack struct end==========


// ==========Stack method start==========
void initStack(Stack &S) {
    S.top = -1; // top = 0 表示BinaryTreeNode[]数组中的第一个元素
}

void push(Stack &S, BinaryTreeNode *treeNode) {
    // 判断栈满
    if (S.top + 1 >= StackMaxSize) {
        printf("\n===stack over flow===\n");
        return;
    }
    S.top++;
    S.treeData[S.top] = treeNode;
}

bool pop(Stack &S, BinaryTreeNode *&treeNode) {
    // 判断栈空
    if (S.top == -1) {
        printf("\n===stack is empty===\n");
        return false;
    }
    treeNode = S.treeData[S.top];
    S.top--;
    return true;
}

bool peek(Stack &S, BinaryTreeNode *&treeNode) {
    // 判断栈空
    if (S.top == -1) {
        printf("\n===stack is empty===\n");
        return false;
    }
    treeNode = S.treeData[S.top];
    return true;
}
// ==========Stack method end==========

// ==========Queue method start==========
void initQueue(BinaryTreeQueue &Q) {// 带头结点
    BinaryTreeLinkedNode *head = (BinaryTreeLinkedNode *) malloc(sizeof(BinaryTreeLinkedNode));
    head->treeData = NULL;
    head->treeNext = NULL;
    Q.front = Q.rear = head;
}

bool isQueueEmpty(BinaryTreeQueue &Q) {
    return Q.front == Q.rear || Q.front->treeNext == NULL/* || Q.rear->treeNext == NULL*/;
}

void enQueue(BinaryTreeQueue &Q, BinaryTreeNode *treeNode) {
    // 构造队列节点
    BinaryTreeLinkedNode *linkedNode = (BinaryTreeLinkedNode *) malloc(sizeof(BinaryTreeLinkedNode));
    linkedNode->treeData = treeNode;
    linkedNode->treeNext = NULL;
    // 入队
    Q.rear->treeNext = linkedNode;
    Q.rear = linkedNode;
}

bool deQueue(BinaryTreeQueue &Q, BinaryTreeNode *&treeNode) {
    // 判断队列是否为空
    if (Q.front == NULL || Q.rear == NULL) {
        return false;
    }
    // 判断队列是否只剩最后一个元素
    BinaryTreeLinkedNode *tmp = Q.front->treeNext;
    treeNode = tmp->treeData;
    Q.front->treeNext = tmp->treeNext;
    if (tmp->treeNext == NULL) {
        Q.rear = Q.front;
    }
    free(tmp);
    return true;
}
// ==========Queue method end==========

// ==========Tree method start==========
// 层序建树
void levelCreateTree(BinaryTree &tree) {
    // 读取一个整数, 用于创建根节点root
    int value;
    scanf("%d", &value);
    // 根节点
    BinaryTreeNode *root = (BinaryTreeNode *) malloc(sizeof(BinaryTreeNode));
    root->data = value;
    root->left = root->right = NULL;
    // 返回的tree指向根节点root
    tree = root;
    // 链表
    BinaryTreeLinkedList linkedList = (BinaryTreeLinkedNode *) malloc(sizeof(BinaryTreeNode));
    linkedList->treeData = root;
    linkedList->treeNext = NULL;
    // 链表尾结点指向当前链表, 用于尾插法
    BinaryTreeLinkedNode *tail = linkedList;
    // 当前节点, 指向当前待处理的节点
    BinaryTreeLinkedNode *current = linkedList;

    // 构造子树
    while (scanf("%d", &value) && value != 9999) {
        // 声明一个树节点
        BinaryTreeNode *tmpTree = (BinaryTreeNode *) malloc(sizeof(BinaryTreeNode));
        tmpTree->data = value;
        tmpTree->left = tmpTree->right = NULL;

        // 声明一个链表节点
        BinaryTreeLinkedNode *tmpLinkedNode = (BinaryTreeLinkedNode *) malloc(sizeof(BinaryTreeLinkedNode));
        tmpLinkedNode->treeData = tmpTree;
        tmpLinkedNode->treeNext = NULL;
        // 尾插法进入链表
        tail->treeNext = tmpLinkedNode;
        tail = tail->treeNext;

        // current, 把树节点入树
        BinaryTreeNode *currentTreeNode = current->treeData;
        if (currentTreeNode->left == NULL) {
            currentTreeNode->left = tmpTree;
        } else if (currentTreeNode->right == NULL) {
            currentTreeNode->right = tmpTree;
            current = current->treeNext;
        }
    }
}

void visit(BinaryTreeNode *node) {
    printf("%3d", node->data);
}

// 中序遍历
void inOrder(BinaryTree root) {
    if (root != NULL) {
        inOrder(root->left);
        visit(root);
        inOrder(root->right);
    }
}

void handleLeftTreeNode(Stack &S, BinaryTreeNode *leftNode) {
    // 处理左节点
//    BinaryTreeNode *leftNode = root;
    while (leftNode != NULL) {
        push(S, leftNode);
        leftNode = leftNode->left;
    }
}

// 中序遍历-非递归遍历
void inOrderNonRecursive(BinaryTree root) {
    // 借助栈
    Stack S;
    initStack(S);

    // 处理左节点
    BinaryTreeNode *leftNode = root;
//    while (leftNode != NULL) {
//        push(S, leftNode);
//        leftNode = leftNode->left;
//    }
    handleLeftTreeNode(S, leftNode);

    // 处理栈中元素
    BinaryTreeNode *cursorNode = NULL;
//    pop(S, cursorNode);
    while (pop(S, cursorNode) && cursorNode != NULL) {
        visit(cursorNode);
        handleLeftTreeNode(S, cursorNode->right);
//        pop(S, cursorNode);
    }
}

// 前序遍历
void preOrder(BinaryTree root) {
    if (root != NULL) {
        visit(root);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void visitRootAndHandleLeft(Stack &S, BinaryTreeNode *treeNode) {
    while (treeNode != NULL) {
        visit(treeNode);
        push(S, treeNode);
        treeNode = treeNode->left;
    }
}

// 前序遍历-非递归
void preOrderNonRecursive(BinaryTree root) {
    Stack S;
    initStack(S);
    visitRootAndHandleLeft(S, root);
    BinaryTreeNode *currentTreeNode = NULL;
    while (pop(S, currentTreeNode) && currentTreeNode != NULL) {
        visitRootAndHandleLeft(S, currentTreeNode->right);
    }
}

// 后序遍历
void postOrder(BinaryTree root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        visit(root);
    }
}
//TODO 后序遍历-非递归
void postOrderNonRecursive(BinaryTree root) {
    Stack S;
    initStack(S);
    // 处理左节点
//    BinaryTreeNode *leftNode = root;
    BinaryTreeNode *pre = NULL;
    BinaryTreeNode *current = root;
    while (current != NULL && current->left != NULL) {
        push(S, current);
        pre = current;
        current = current->left;
    }
    if (current->right != NULL) {
        visit(current->right);
    }
    visit(current);
    // 处理右节点
    BinaryTreeNode *rightNode = pre->right;

    printf("===");

//    handleLeftTreeNode(S, root);
//    BinaryTreeNode *currentTreeNode = NULL;
//    while (peek(S, currentTreeNode) && currentTreeNode != NULL) {
//        handleLeftTreeNode(S, currentTreeNode->right);
//        pop(S, currentTreeNode); // 这里使用pop进行弹出操作后, currentTreeNode节点指向会发生变化, 重新栈顶的元素了
//        visit(currentTreeNode);
//    }
}

void levelOrder(BinaryTree root) {
    // 初始化队列
    BinaryTreeQueue Q;
    initQueue(Q);
    // 入队
    enQueue(Q, root);
    BinaryTreeNode *tmpTreeNode = NULL;
    while (!isQueueEmpty(Q)) {
        // 出队并访问
        deQueue(Q, tmpTreeNode);
        visit(tmpTreeNode);
        if (tmpTreeNode->left != NULL) {
            enQueue(Q, tmpTreeNode->left);
        }
        if (tmpTreeNode->right != NULL) {
            enQueue(Q, tmpTreeNode->right);
        }
    }
}
// ==========Tree method end==========

int main() {

    // 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 9999

    BinaryTree root = NULL;
    levelCreateTree(root);

//    printf("\n=========inOrder==========\n");
//    inOrder(root);
//
//    printf("\n=========inOrderNonRecursive==========\n");
//    inOrderNonRecursive(root);

//    printf("\n=========preOrder==========\n");
//    preOrder(root);
//    printf("\n=========preOrderNonRecursive==========\n");
//    preOrderNonRecursive(root);

//    printf("\n=========postOrder==========\n");
//    postOrder(root);
//    printf("\n=========postOrderNonRecursive==========\n");
//    postOrderNonRecursive(root);

    printf("\n=========levelOrder==========\n");
    levelOrder(root);



    return 0;
}
