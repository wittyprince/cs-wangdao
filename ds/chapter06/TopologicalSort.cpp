//
// Created by 51676 on 2024/8/7.
//

#include <stdio.h>
#include <stdlib.h>

// 拓扑排序算法
#define AlMaxSize 10
typedef struct arcNode {
    int index;
    struct arcNode *nextArc;
} ArcNode;

typedef struct vexNode {
    char data;
    ArcNode *firstArc;
} VexNode;

typedef struct alGraph {
    VexNode *vertices[AlMaxSize];
    int vexNum;
    int arcNum;
} ALGraph;

typedef struct stack {
    VexNode *stackData[AlMaxSize];
    int top;
} Stack;

void initStack(Stack &S) {
    S.top = -1;
}

bool isStackEmpty(Stack S) {
    return S.top == -1;
}

void pushIntoStack(Stack &S, VexNode *vexNode) {
    // 判断栈满
    if (S.top + 1 > AlMaxSize) {
        printf("The Stack is full...");
        return;
    }
    // 入栈
    S.top++;
    S.stackData[S.top] = vexNode;
}

void popFromStack(Stack &S, VexNode *&vexNode) {
    // 判断栈空
    if (S.top == -1) {
        printf("The Stack is empty...");
        return;
    }
    vexNode = S.stackData[S.top];
    S.top--;
}

void visitVexNode(VexNode *vexNode) {
    printf("%3c", vexNode->data);
}

void topologicalSort(ALGraph G, int deg[]) {
    // 可以借助【栈】, 也可以借助 【队列】 或 【数组】
    // 是因为入度为0的节点, 他们没有前后顺序要求
    Stack S;
    initStack(S);
    // G个顶点节点的入度数组degrees[]
    //   1. 对于邻接表
    //   2. 对于邻接矩阵
    //TODO 这里需要处理
    int *degrees = deg;

    // 把所有度为0的节点入栈
    // 下标节点从1开始
    for (int i = 1; i <= G.vexNum; ++i) {
        if (degrees[i] == 0) {
            pushIntoStack(S, G.vertices[i]);
        }
    }
    int count = 0; // 统计访问的节点数
    // 处理栈中数据
    VexNode *tmpVexNode;
    while (!isStackEmpty(S)) {
        popFromStack(S, tmpVexNode);
        // 访问
        count++;
        visitVexNode(tmpVexNode);
        // 处理, 把tmpVexNode的边表中的节点的度都减1
        ArcNode *tmpArcNode = tmpVexNode->firstArc;
        while (tmpArcNode != NULL) {
            // 度减1
            int index = tmpArcNode->index;
            degrees[index] = degrees[index] - 1;
//            degrees[index]--; // 可以?
            if (degrees[index] == 0) {
                pushIntoStack(S, G.vertices[index]);
            }
            tmpArcNode = tmpArcNode->nextArc;
        }
    }

    printf("\n=====\n");

    if (count == G.vexNum) {
        printf("success");
    } else {
        // 排序失败, 有向图中有回路
        printf("fail");
    }
}

int main() {
    ALGraph G;

    VexNode *v1 = (VexNode *)malloc(sizeof (VexNode));
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

    ArcNode *a12 = (ArcNode *) malloc(sizeof (ArcNode));
    a12->index = 2;
    ArcNode *a14 = (ArcNode *) malloc(sizeof (ArcNode));
    a14->index = 4;
    a12->nextArc = a14;
    a14->nextArc = NULL;
    v1->firstArc = a12;

    ArcNode *a23 = (ArcNode *) malloc(sizeof (ArcNode));
    a23->index = 3;
    ArcNode *a24 = (ArcNode *) malloc(sizeof (ArcNode));
    a24->index = 4;
    a23->nextArc = a24;
    a24->nextArc = NULL;
    v2->firstArc = a23;

    ArcNode *a35 = (ArcNode *) malloc(sizeof (ArcNode));
    a35->index = 5;
    a35->nextArc = NULL;
    v3->firstArc = a35;

    ArcNode *a43 = (ArcNode *) malloc(sizeof (ArcNode));
    a43->index = 3;
    ArcNode *a45 = (ArcNode *) malloc(sizeof (ArcNode));
    a45->index = 5;
    a43->nextArc = a45;
    a45->nextArc = NULL;
    v4->firstArc = a43;

    v5->firstArc = NULL;

    G.arcNum = 7;

    int vexNum = 5;
    int degrees[6] = {9999, 0, 1, 2, 2, 2};

    topologicalSort(G, degrees);

    return 0;
}