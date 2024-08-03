//
// Created by 51676 on 2024/8/3.
//

#include "MGraph.h"

int main() {
    MGraph G;
    G.vertex[0] = 'a';
    G.vertex[1] = 'b';
    G.vertex[2] = 'c';
    G.vertex[3] = 'd';
    G.vertexNum = 4;

    G.edge[0][0] = 0;
    G.edge[0][1] = 1;
    G.edge[0][2] = 1;
    G.edge[0][3] = 0;

    G.edge[1][0] = 0;
    G.edge[1][1] = 0;
    G.edge[1][2] = 0;
    G.edge[1][3] = 0;

    G.edge[2][0] = 0;
    G.edge[2][1] = 0;
    G.edge[2][2] = 0;
    G.edge[2][3] = 1;

    G.edge[3][0] = 1;
    G.edge[3][1] = 0;
    G.edge[3][2] = 0;
    G.edge[3][3] = 0;

    G.arcNum = 4;

    return 0;
}
