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

// 链表节点
typedef struct bstLinkedNode {
    BSTNode *linkedNodeData;
    struct bstLinkedNode *linkedNodeNext;
} BSTLinkedNode, *BSTLinkedNodeList;


void visitBSTNode(BSTNode *node) {
    printf("%3d", node->data);
}

void levelOrder(BST root) {
    // 构造链表, 用于树的辅助遍历
    // 初始化带头结点的链表
    BSTLinkedNodeList linkedList = (BSTLinkedNodeList) malloc(sizeof(BSTLinkedNode));
    linkedList->linkedNodeData = 0;
    linkedList->linkedNodeNext = NULL;
    // 声明头结点
    BSTLinkedNode *head = linkedList;
    // 尾结点: 用于尾插法插入链表
    BSTLinkedNode *tail = linkedList;
    // 当前节点, 用于遍历
    BSTLinkedNode *current;

    // 构造根节点
    BSTLinkedNode *tmpLinkedNode = (BSTLinkedNode *) malloc(sizeof(BSTLinkedNode));
    tmpLinkedNode->linkedNodeData = root;
    tmpLinkedNode->linkedNodeNext = NULL;
    // 根节点 插入链表
    tail->linkedNodeNext = tmpLinkedNode;
    tail = tail->linkedNodeNext;

    // 遍历链表
    current = head->linkedNodeNext;
    while (current != NULL) {
        BSTNode *currentBSTNode = current->linkedNodeData;
        if (currentBSTNode != NULL) {
            // 遍历树节点
            visitBSTNode(currentBSTNode);

            // 把左、右孩子插入链表
            if (currentBSTNode->left != NULL) {
                // 构造节点
                tmpLinkedNode = (BSTLinkedNode *) malloc(sizeof(BSTLinkedNode));
                tmpLinkedNode->linkedNodeData = currentBSTNode->left;
                tmpLinkedNode->linkedNodeNext = NULL;
                // 节点 插入链表
                tail->linkedNodeNext = tmpLinkedNode;
                tail = tail->linkedNodeNext;
            }
            if (currentBSTNode->right != NULL) {
                // 构造节点
                tmpLinkedNode = (BSTLinkedNode *) malloc(sizeof(BSTLinkedNode));
                tmpLinkedNode->linkedNodeData = currentBSTNode->right;
                tmpLinkedNode->linkedNodeNext = NULL;
                // 节点 插入链表
                tail->linkedNodeNext = tmpLinkedNode;
                tail = tail->linkedNodeNext;
            }
        }
        current = current->linkedNodeNext;
    }
}

void inOrder(BST root) {
    if (root != NULL) {
        inOrder(root->left);
        visitBSTNode(root);
        inOrder(root->right);
    }
}

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

// 二叉排序树-插入-递归方式
bool BST_Insert(BST &T, ElementType e) {
    if (T == NULL) {
        BSTNode *node = (BSTNode *) malloc(sizeof(BSTNode));
        node->data = e;
        node->left = node->right = NULL;
        T = node;
        return true;
    }
    if (T->data == e) {
        //TODO 如果相等, 具体的处理策略带确定
        printf("the value [%3d] has been already existed!\n", e);
        return false;
    }
    if (T->data > e) {
        return BST_Insert(T->left, e);
    } else {
        return BST_Insert(T->right, e);
    }
}

void createBST(BST &tree, int a[], int n) {
    for (int i = 0; i < n; ++i) {
        BST_Insert(tree, a[i]);
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
        printf("%3d\n", node2->data);
    } else {
        printf("search failed\n");
    }


    BST root = NULL;
    BST_Insert(root, 6);
    BST_Insert(root, 2);
    BST_Insert(root, 8);
    BST_Insert(root, 1);
    BST_Insert(root, 4);
    BST_Insert(root, 3);
    inOrder(n6);

    printf("\n===\n");
    BST r1 = NULL;
    int a[] = {45, 24, 53, 45, 12, 24};
    createBST(r1, a, 5);
    inOrder(r1);

    return 0;
}