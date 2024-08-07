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

// ==========Queue method start==========
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

// ==========Queue method end==========

// ==========Tree method start==========
// =====================中序线索二叉树 start=====================
// 中序线索化
void visit(ThreadBinaryTreeNode *&current, ThreadBinaryTreeNode *&pre) {
    // 处理左子树, 如果左子树为空, 对左子树进行线索化
    // 这里没有对current进行右子树判断及处理,
    // 这是因为将current.rightChild的处理放在了后续pre.rightChild中进行了处理
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

// 在中序线索二叉树中:
// 找到以当前节点currentNode为根的子树中的, 第一个被中序遍历的节点
//      即为从当前节点currentNode开始向左遍历, 直到最左节点,
//      注意: 最左节点可能是叶子节点, 也可能是非叶子节点
ThreadBinaryTreeNode *getFirstNode(ThreadBinaryTreeNode *currentNode) {
    while (currentNode != NULL && currentNode->leftThread == 0) {
        currentNode = currentNode->leftChild;
    }
    return currentNode;
}

// 在中序线索二叉树中找到当前节点currentNode的后继节点 - 中序后继
ThreadBinaryTreeNode *getNextNode(ThreadBinaryTreeNode *currentNode) {
    // 如果当前节点currentNode的右线索标识rightThread为1,
    //      即已经被线索化, 那么右孩子即为当前节点currentNode的后继节点
    if (currentNode->rightThread == 1) {
        return currentNode->rightChild;
    }
    // 如果当前节点currentNode的右线索标识rightThread==0,
    //      即未被线索化, 那么需要找到currentNode的右子树中第一个被访问的节点
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

// 在中序线索二叉树中:
// 找到以当前节点currentNode为根的子树中的, 最后一个被中序遍历的节点
//      即为从当前节点currentNode开始向右遍历, 直到最右节点,
//      注意: 最右节点可能是叶子节点, 也可能是非叶子节点
ThreadBinaryTreeNode *getTheLastNode(ThreadBinaryTreeNode *currentNode) {
    ThreadBinaryTreeNode *tmp = currentNode;
    while (tmp != NULL && tmp->rightThread == 0) {
        tmp = currentNode->rightChild;
    }
    return tmp;
}

// 在中序线索二叉树中找到当前节点currentNode的前驱节点 - 中序前驱
ThreadBinaryTreeNode *getPreviousNode(ThreadBinaryTreeNode *currentNode) {
    // 如果当前节点currentNode的左线索标识leftThread==1,
    //      即已经被线索化, 那么左孩子即为当前节点currentNode的前驱节点
    if (currentNode->leftThread == 1) {
        return currentNode->leftChild;
    }
    // 如果当前节点currentNode的左线索标识leftThread==0,
    //      即未被线索化, 那么需要找到currentNode的左子树中最后一个被访问的节点
    return getTheLastNode(currentNode->leftChild);
}

// 线索二叉树-逆向中序遍历-非递归
void reverseInOrderNonRecursive(ThreadBinaryTree root) {
    // 1. 找到根节点root的最后一个要被遍历的节点
    ThreadBinaryTreeNode *theLastNode = getTheLastNode(root);
    ThreadBinaryTreeNode *previousNode = getPreviousNode(theLastNode);
    // 2. 循环遍历firstNode的后继节点, 即可
    for (ThreadBinaryTreeNode* i = theLastNode; i != NULL; i = getPreviousNode(i)) {
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
// =====================中序线索二叉树 end=====================

// =====================先序线索二叉树 start=====================
// 先序遍历二叉树-线索化
void preThread(ThreadBinaryTree root, ThreadBinaryTreeNode *&pre) {
    if (root != NULL) {
        visit(root, pre);
        if (root->leftThread == 0) {
            preThread(root->leftChild, pre);
        }
        if (root->rightThread == 0) {
            preThread(root->rightChild, pre);
        }
    }
}

// 线索二叉树-先序遍历-创建树
void preThreadCreateTree(ThreadBinaryTree root) {
    ThreadBinaryTreeNode *pre = NULL;
    if (root != NULL) {
        //TODO The address of the local variable 'pre' may escape the function
        preThread(root, pre);
        if (pre->rightChild == NULL) {
            pre->rightThread = 1;
        }
    }
}

// 线索二叉树-先序遍历-找后继 - 先序后继
ThreadBinaryTreeNode *getNextNode4PreOrder(ThreadBinaryTreeNode *currentNode) {
    // 如果右节点被线索化, 那么右孩子即为当前节点currentNode的后继节点
    if (currentNode->rightThread == 1) {
        return currentNode->rightChild;
    }
    // 没被线索化, 说明一点有右孩子
    // 1. 如果有左孩子, 那么后继为左孩子
    //  注意: 这里要加上currentNode->leftThread == 0的判断,
    //      否则,currentNode->leftThread == 1的话, 左孩子被线索化为其前驱结点了
    if (currentNode->leftThread == 0 && currentNode->leftChild != NULL) {
        return currentNode->leftChild;
    }
    // 2. 如果左孩子为空, 那么后继为右孩子
    return currentNode->rightChild;
}

// 线索二叉树-先序遍历-非递归
void preOrderNonRecursive(ThreadBinaryTree root) {
    ThreadBinaryTreeNode *firstNode = root;
    for (ThreadBinaryTreeNode *i = firstNode; i != NULL; i = getNextNode4PreOrder(i)) {
        visitTreeNode(i);
    }
}

void preOrder(ThreadBinaryTree root) {
    if (root != NULL) {
        visitTreeNode(root);
        if (root->leftThread == 0) {
            preOrder(root->leftChild);
        }
        if (root->rightThread == 0) {
            preOrder(root->rightChild);
        }
    }
}

// =====================先序线索二叉树 end=====================

// =====================后序线索二叉树 start=====================
//  后续线索化
void postThread(ThreadBinaryTree root, ThreadBinaryTreeNode *&pre) {
    if (root != NULL) {
        if (root->leftThread == 0) {
            postThread(root->leftChild, pre);
        }
        if (root->rightThread == 0) {
            postThread(root->rightChild, pre);
        }
        visit(root, pre);
    }
}

void postThreadCreateTree(ThreadBinaryTree root) {
    ThreadBinaryTreeNode *pre = NULL;
    if (root != NULL) {
        postThread(root, pre);
        //处理最后一个节点pre
        if (pre->rightChild == NULL) {
            pre->rightThread = 1;
        }
    }
}

// 在后序线索二叉树中:
// 找到以当前节点currentNode为根的子树中的, 最后一个被后序遍历的节点
//      即为从当前节点currentNode开始向右遍历, 直到最右节点,
//      注意: 最右节点可能是叶子节点, 也可能是非叶子节点
ThreadBinaryTreeNode *getTheLastNode4PostOrder(ThreadBinaryTreeNode *currentNode) {
//    if (currentNode->rightChild != NULL) {
//        if (currentNode->rightThread == 0) {
//            return currentNode->rightChild;
//        }
//    }
    // 未被线索化, 说明currentNode原来的右子树leftChild不为空
    if (currentNode->rightThread == 0) {
        return currentNode->rightChild;
    }
    // 走到这里说明右子树为空, 被线索化, 线索化标识为1
//    if (currentNode->rightThread == 1) {
//        // 被线索化, 说明currentNode原来的rightChild为空
//    }
    // 返回左子树, 包括:
    //      1. 左子树被线索化
    //      2. 左子树未被线索化
    return currentNode->leftChild;
}

// 在后序线索二叉树中找到当前节点currentNode的前驱节点 - 后序前驱
ThreadBinaryTreeNode *getPreviousNode4PostOrder(ThreadBinaryTreeNode *currentNode) {
    // 如果左线索为1
    if (currentNode->leftThread == 1) {
        return currentNode->leftChild;
    }
    // 左线索不为1
    return getTheLastNode4PostOrder(currentNode);
}

// 逆序后续遍历
void reversePostOrderNonRecursive(ThreadBinaryTree root) {
    ThreadBinaryTreeNode *theLastNode = root;
    for (ThreadBinaryTreeNode * i = theLastNode; i != NULL ; i = getPreviousNode4PostOrder(i)) {
        visitTreeNode(i);
    }
}

void postOrder(ThreadBinaryTree root) {
    if (root != NULL) {
        if (root->leftThread == 0) {
            postOrder(root->leftChild);
        }
        if (root->rightThread == 0) {
            postOrder(root->rightChild);
        }
        visitTreeNode(root);
    }
}
// =====================先序线索二叉树 end=====================

// ==========Tree method end==========

#endif //CS_WANGDAO_THREADBINARYTREE_H
