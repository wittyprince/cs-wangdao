//
// Created by 51676 on 2024/8/2.
//
#include <stdio.h>
#include <stdlib.h>

// 树的广度优先遍历
// Breadth-First-Search

#define MaxVexNum 10

typedef char VertexType;

// 图中的 边节点
typedef struct arcNode {
    int index; // 邻接点域, 存储与头结点顶点Vi邻接的顶点的编号, 即邻接顶点在数组vertices[]的编号或下标索引(具体含义可调整)
    struct arcNode *nextArc; // 指针域, 指向下一个边节点
    // InfoType info; // 边的权值
} ArcNode;

// 图中的 顶点节点
typedef struct vexNode{
    VertexType data; // 数据域, 节点中的数据信息
    ArcNode *firstArc; // 与当前节点链接的单链表的第一个边节点
} VexNode;

// 邻接表数据结构
typedef struct alGraph {
    VexNode *vertices[MaxVexNum];
    int vexNum; // 顶点数
    int arcNum; // 边数
} ALGraph; //


// 借助队列进行广度优先遍历/
// 队列节点
typedef struct vexLinkedNode {
    VexNode *vexData; //
    struct vexLinkedNode *vexNext; //
} VexLinkedNode, *VexLinkedList;
// 队列
typedef struct vexQueue {
    VexLinkedNode *front, *rear; // 头/尾指针
} VexQueue;

// ===================================================

void visitVexNode(VexNode *vexNode) {
    printf("%3c", vexNode->data);
}

// 图G中顶点x的第一个邻接点, 若有, 返回顶点号, 若没有或顶点x不存在, 返回-1
int firstNeighbor(ALGraph G, VexNode x) {
    return -1;
}

// 假设图G中顶点y是顶点x的一个邻接点, 返回除了y外, 顶点x的下一个邻接点的顶点号,
//      若y是x的最后一个邻接点, 则返回-1
int nextNeighbor(ALGraph G, VexNode x, VexNode y) {
    return -1;
}

// 初始化一个带头结点的队列
void initQueue(VexQueue &Q) {
    VexLinkedNode *head = (VexLinkedNode *) calloc(1, sizeof(VexLinkedNode));
    Q.front = Q.rear = head;
}

bool isQueueEmpty(VexQueue Q) {
    return Q.front == Q.rear || Q.front->vexNext == NULL;
}

void enQueue(VexQueue &Q, VexNode *vexNode) {
    // 构造队列节点
    VexLinkedNode *tmp = (VexLinkedNode *) malloc(sizeof(VexLinkedNode));
    tmp->vexData = vexNode;
    tmp->vexNext = NULL;
    // 入队
    Q.rear->vexNext = tmp;
    Q.rear = tmp;
}

bool deQueue(VexQueue &Q, VexNode *&vexNode) {
    // 判断队列是否为空
    if (Q.front == Q.rear || Q.front->vexNext == NULL) {
        return false;
    }

    VexLinkedNode *tmp = Q.front->vexNext;
    vexNode = tmp->vexData;

    // 判断队列是否只剩一个元素
    Q.front->vexNext = tmp->vexNext;
    if (tmp->vexNext == NULL) {
        Q.rear = Q.front;
    }
    free(tmp);
    return true;
}


void BFS(ALGraph G, int v) {
    if (G.vexNum <= 0) {
        return;
    }
    bool visited[G.vexNum + 1]; // 被遍历标记数组, 为了方便使用, 从下标1开始存储
    for (int i = 1; i < G.vexNum + 1; ++i) {
        visited[i] = false;
    }
    VexNode **vertices = G.vertices;

    // 队列
    VexQueue Q;
    initQueue(Q);

    VexNode *tmpVexNode = vertices[v];
    visitVexNode(tmpVexNode);
    visited[v] = true;

    enQueue(Q, tmpVexNode);
    while (!isQueueEmpty(Q)) {
        deQueue(Q, tmpVexNode);
        ArcNode *arcNode = tmpVexNode->firstArc;
        while (arcNode != NULL) {
            if (!visited[arcNode->index]) {
                visitVexNode(vertices[arcNode->index]);
                visited[arcNode->index] = true;
                enQueue(Q, vertices[arcNode->index]);
            }
            arcNode = arcNode->nextArc;
        }

    }
}

void BFSTraverse(ALGraph G, int index) {


}

int main() {

    ALGraph G;

//    VexNode v0 = {'a'};
//    VexNode *vp0 = v0; // 报错

//    VexNode* vertices[4]; //
    VexNode *v1 = (VexNode *)malloc(sizeof(VexNode));
    v1->data = 'a';
//    v1->firstArc = NULL;
    G.vertices[1] = v1;
    VexNode *v2 = (VexNode *)malloc(sizeof(VexNode));
    v2->data = 'b';
//    v2->firstArc = NULL;
    G.vertices[2] = v2;
    VexNode *v3 = (VexNode *)malloc(sizeof(VexNode));
    v3->data = 'c';
//    v3->firstArc = NULL;
    G.vertices[3] = v3;
    VexNode *v4 = (VexNode *)malloc(sizeof(VexNode));
    v4->data = 'd';
//    v4->firstArc = NULL;
    G.vertices[4] = v4;
    VexNode *v5 = (VexNode *)malloc(sizeof(VexNode));
    v5->data = 'e';
//    v4->firstArc = NULL;
    G.vertices[5] = v5;

    G.vexNum = 5;
//    G.vertices = vertices;

    ArcNode *a12 = (ArcNode *) malloc(sizeof(ArcNode));
    a12->index = 2;
    ArcNode *a15 = (ArcNode *) malloc(sizeof(ArcNode));
    a15->index = 5;
    a12->nextArc = a15;
    a15->nextArc = NULL;
    v1->firstArc = a12;

    ArcNode *a21 = (ArcNode *) malloc(sizeof(ArcNode));
    a21->index = 1;
    ArcNode *a23 = (ArcNode *) malloc(sizeof(ArcNode));
    a23->index = 3;
    ArcNode *a24 = (ArcNode *) malloc(sizeof(ArcNode));
    a24->index = 4;
    ArcNode *a25 = (ArcNode *) malloc(sizeof(ArcNode));
    a25->index = 5;
    a21->nextArc = a23;
    a23->nextArc = a24;
    a24->nextArc = a25;
    a25->nextArc = NULL;
    v2->firstArc = a21;

    ArcNode *a32 = (ArcNode *) malloc(sizeof(ArcNode));
    a32->index = 2;
    ArcNode *a34 = (ArcNode *) malloc(sizeof(ArcNode));
    a34->index = 4;
    a32->nextArc = a34;
    a34->nextArc = NULL;
    v3->firstArc = a32;

    ArcNode *a42 = (ArcNode *) malloc(sizeof(ArcNode));
    a42->index = 2;
    ArcNode *a43 = (ArcNode *) malloc(sizeof(ArcNode));
    a43->index = 3;
    ArcNode *a45 = (ArcNode *) malloc(sizeof(ArcNode));
    a45->index = 5;
    a42->nextArc = a43;
    a43->nextArc = a45;
    a45->nextArc = NULL;
    v4->firstArc = a42;

    ArcNode *a51 = (ArcNode *) malloc(sizeof(ArcNode));
    a51->index = 1;
    ArcNode *a52 = (ArcNode *) malloc(sizeof(ArcNode));
    a52->index = 2;
    ArcNode *a54 = (ArcNode *) malloc(sizeof(ArcNode));
    a54->index = 4;
    a51->nextArc = a52;
    a52->nextArc = a54;
    a54->nextArc = NULL;
    v5->firstArc = a51;

    BFS(G, 1); // 从1开始







    return 0;
}