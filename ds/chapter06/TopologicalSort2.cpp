//
// Created by 51676 on 2024/8/7.
//

#include <stdio.h>
#include <stdlib.h>

// 利用DFS实现有向无环图的拓扑排序
// 可以基于 【邻接表】, 也可以基于 【邻接矩阵】 实现
// 这里使用 邻接矩阵 方式
#define VexMaxSize 10

typedef struct mGraph {
    char vertices[VexMaxSize];
    int edges[VexMaxSize][VexMaxSize];
    int vexNum;
    int edgeNum;
} MGraph;

void visitVexNode(char vexNode) {
    printf("%3c", vexNode);
}

void DFS(MGraph G, int v, bool visited[], int &time, int finishTime[]) {
    if (!visited[v]) {
        visitVexNode(G.vertices[v]);
        visited[v] = true;
    }
    // 编号为v的顶点所在的行, 编号从0开始
    int row = v;
    for (int j = 0; j < G.vexNum; ++j) {
        int edgeWeight = G.edges[row][j];
        if (edgeWeight == 1 && !visited[j]) {
//            visitVexNode(G.vertices[j]);
//            visited[j] = true;
            DFS(G, j, visited, time, finishTime);
        }
    }
    time = time + 1;
    finishTime[v] = time;
}

void DFSTraverse(MGraph G) {
    bool visited[G.vexNum];
    for (int i = 0; i < G.vexNum; ++i) {
        visited[i] = false;
    }
    int time = 0;
    int finishTime[G.vexNum];
    for (int i = 0; i < G.vexNum; ++i) {
        if (!visited[i]) {
            DFS(G, i, visited, time, finishTime);
        }
    }

    printf("\n=====\n");
    for (int i = 0; i < G.vexNum; ++i) {
        // 按finishTime从大至小进行输出, 即可得到拓扑排序序列 a b d c e
        printf("%3d", finishTime[i]); //  5  4  2  3  1
    }
}

bool topologicalSort2(MGraph G) {
    DFSTraverse(G);
    return true;
}

int main() {

    /**
     *  1 ----> 4
     *  |     ↑ | \
     *  |   /   |  ↓
     *  |  /    |   5
     *  | /     |  ↑
     *  ↓/     ↓  /
     *  2-----> 3
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
    G.edges[0][2] = 9999;
    G.edges[0][3] = 1;
    G.edges[0][4] = 9999;

    G.edges[1][0] = 9999;
    G.edges[1][1] = 0;
    G.edges[1][2] = 1;
    G.edges[1][3] = 1;
    G.edges[1][4] = 9999;

    G.edges[2][0] = 9999;
    G.edges[2][1] = 9999;
    G.edges[2][2] = 0;
    G.edges[2][3] = 9999;
    G.edges[2][4] = 1;

    G.edges[3][0] = 9999;
    G.edges[3][1] = 9999;
    G.edges[3][2] = 1;
    G.edges[3][3] = 0;
    G.edges[3][4] = 1;

    G.edges[4][0] = 9999;
    G.edges[4][1] = 9999;
    G.edges[4][2] = 9999;
    G.edges[4][3] = 9999;
    G.edges[4][4] = 0;

    G.edgeNum = 6;

    DFSTraverse(G);

    return 0;
}
