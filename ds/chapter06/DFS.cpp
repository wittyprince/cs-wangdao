//
// Created by 51676 on 2024/8/5.
//

// 深度有限遍历

#include <stdio.h>
#include <stdlib.h>

// 数据结构
// 边/弧节点
#define ALMaxSize 10

typedef struct arcNode {
    int index; // 邻接顶点位置编号
    struct arcNode *nextArc; // 邻接边
    // InfoType info; // 边中包含的信息, 如权值等
} ArcNode;
// 顶点节点
typedef struct vexNode {
    char data; // 顶点信息
    ArcNode *firstArc; // 顶点的第一个邻接边
} VexNode;
// 邻接表
typedef struct alGraph{
    VexNode *vertices[ALMaxSize]; // 顶点指针数组
    int vexNum; // 顶点数目
    int arcNum; // 边数目
} ALGraph;

void visitVexNode(VexNode *vexNode) {
    printf("%3c", vexNode->data);
}

/**
 * 深度优先遍历
 * @param G 邻接表
 * @param v 开始访问的顶点编号, 从1开始
 * @param visited 是否被遍历过的标记数组
 */
void DFS(ALGraph G, int v, bool visited[]) {
    if (v < 1 || v > G.vexNum) {
        printf("the v value: [%d] is wrong", v);
        return;
    }
    VexNode *tmpVexNode = G.vertices[v];
    visitVexNode(tmpVexNode);
    visited[v] = true;

    ArcNode *tmpArcNode = tmpVexNode->firstArc;
    while (tmpArcNode != NULL) {
        if (!visited[tmpArcNode->index]) {
//            visitVexNode(tmpVexNode);
//            visited[v -1] = true;
            DFS(G, tmpArcNode->index, visited);
        }
        tmpArcNode = tmpArcNode->nextArc;
    }
}

void DFSTraverse(ALGraph G) {
    int MaxSize = G.vexNum;
    bool visited[MaxSize];
    for (int i = 0; i < MaxSize; ++i) {
        visited[i] = false;
    }
    for (int i = 1; i <= G.vexNum; ++i) {
        if (!visited[i]) {
            DFS(G, i, visited);
        }
    }

}

int main() {

    ALGraph G;

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

    G.arcNum = 7;

    DFSTraverse(G);




    return 0;
}