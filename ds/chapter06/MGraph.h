//
// Created by 51676 on 2024/8/2.
//

#ifndef CS_WANGDAO_MGRAPH_H
#define CS_WANGDAO_MGRAPH_H

// 图的存储 - 邻接矩阵法

#define MaxVertexNum 100 // 顶点数目的最大值
typedef struct {
    char Vertex[MaxVertexNum]; // 顶点表
    int Edge[MaxVertexNum][MaxVertexNum]; // 邻接矩阵, 边表
    int vertexNum; // 图的当前顶点数
    int arcNum; // 图的当前边数/弧数
} MGraph;

// 带权图(网)-邻接矩阵法
#define INFINITY 99999999  // 可以使用int的最大值, 代表无穷大, 宏定义常量"无穷"
typedef char VertexType; // 顶点的数据类型
typedef int EdgeType; // 带权图中边上的权值的数据类型
typedef struct {
    VertexType Vertex[MaxVertexNum]; // 顶点
    EdgeType Edge[MaxVertexNum][MaxVertexNum]; // 边的权值
    int vertexNum; // 图中的当前顶点数
    int arcNum; // 图中的当前弧数
} MGraph2;


#endif //CS_WANGDAO_MGRAPH_H
