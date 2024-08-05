//
// Created by 51676 on 2024/8/5.
//

#include <stdio.h>

// 深度优先遍历-邻接矩阵

#define VexMaxSize 5

typedef struct mGraph{
    char vertices[VexMaxSize]; // 顶点表
    int edges[VexMaxSize][VexMaxSize]; // 边表, 邻接矩阵
    int vexNum;
    int edgeNum;
} MGraph;

void visitVexNode(char vexNode) {
    printf("%3c", vexNode);
}

/**
 * 深度优先遍历
 * @param G 邻接矩阵
 * @param v 待访问的节点编号, 从0开始
 * @param visited 是否已被访问过的数组标记
 */
void DFS2(MGraph G, int v, bool visited[]) {
    if (v < 0 || v > G.vexNum) {
        printf("the v value: [%d] is wrong\n", v);
        return;
    }
    char tmpVertex = G.vertices[v];
    visitVexNode(tmpVertex);
    visited[v] = true;
    // 找当前节点v的邻接节点
    //    即为v节点的同行或同列中不为边权值不为1的元素节点
    for (int j = 0; j < G.vexNum; ++j) {
        int edgeWight = G.edges[v][j];
        char tmpV = G.vertices[j];
        if (edgeWight == 1 && !visited[j]) {
            DFS2(G, j, visited);
        }
    }
}

void DFS2Traverse(MGraph G) {
    int MaxSize = G.vexNum;
    bool visited[MaxSize];
    for (int i = 0; i < MaxSize; ++i) {
        visited[i] = false;
    }
    for (int i = 0; i < G.vexNum; ++i) {
        if (!visited[i]) {
            DFS2(G, i, visited);
        }
    }
}

int main() {

    /**
     *  1 ---- 2
     *  |    / |
     *  |  3   |
     *  | / \  |
     *  4     5
     *
     */
    MGraph G;
    G.vertices[0] = 'a';
    G.vertices[1] = 'b';
    G.vertices[2] = 'c';
    G.vertices[3] = 'd';
    G.vertices[4] = 'e';
    G.vexNum = 5;

    G.edges[0][0] = 0;
    G.edges[0][1] = 1;
    G.edges[0][2] = 0;
    G.edges[0][3] = 1;
    G.edges[0][4] = 0;

    G.edges[1][0] = 1;
    G.edges[1][1] = 0;
    G.edges[1][2] = 1;
    G.edges[1][3] = 0;
    G.edges[1][4] = 1;

    G.edges[2][0] = 0;
    G.edges[2][1] = 1;
    G.edges[2][2] = 0;
    G.edges[2][3] = 1;
    G.edges[2][4] = 1;

    G.edges[3][0] = 1;
    G.edges[3][1] = 0;
    G.edges[3][2] = 1;
    G.edges[3][3] = 0;
    G.edges[3][4] = 0;

    G.edges[4][0] = 0;
    G.edges[4][1] = 1;
    G.edges[4][2] = 1;
    G.edges[4][3] = 0;
    G.edges[4][4] = 0;

    G.edgeNum = 6;

    DFS2Traverse(G);


    return 0;
}