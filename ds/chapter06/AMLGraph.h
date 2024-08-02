//
// Created by 51676 on 2024/8/2.
//

#ifndef CS_WANGDAO_AMLGRAPH_H
#define CS_WANGDAO_AMLGRAPH_H

// ref: https://www.cnblogs.com/Trojan00/p/8964609.html

//邻接多重表(Adjacency MultiList)主要用于存储无向图.

#define AMLMaxSize 100 // 最大顶点数

typedef int InfoType;
typedef char VertexType;

// 边节点
typedef struct edgeNode {
    int iVex; // 该边依附于的两个顶点在数组中的下标索引
    struct edgeNode *iLink; // 指向下一条依附于顶点iVex的边
    int jVex; // 该边依附于的两个顶点在数组中的下标索引
    struct edgeNode *jLink; // 指向下一条依附于顶点jVex的边
    InfoType info; // 存放边的相关信息, 如权值等
} EdgeNode;

// 顶点节点
typedef struct vexNode {
    VertexType data; // 数据域 - 存放该顶点节点的信息
    EdgeNode *firstEdge; // 指针域 - 指向第一条依附于该顶点的边
} VexNode;


typedef struct {
    VexNode vertices[AMLMaxSize]; //
    int vexNum; // 无向图的顶点数
    int edgeNum; // 无向图的边数
} AMLGraph;


#endif //CS_WANGDAO_AMLGRAPH_H
