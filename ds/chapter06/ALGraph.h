//
// Created by 51676 on 2024/8/2.
//

#ifndef CS_WANGDAO_ALGRAPH_H
#define CS_WANGDAO_ALGRAPH_H

// 邻接表 adjacency table
// 顺序 + 链式存储
//   所谓邻接表,
//      是指对图G中的每个顶点Vi建立一个单链表,
//      该单链表中的节点为依附于顶点Vi的边(对于有向图是以该顶点为尾的弧), 该单链表称为顶点Vi的边表.
//   边表的头指针和顶点的数据信息使用顺序存储方式, 基于数组实现, 称为顶点表.
// 简单理解:
//   1. 对图G中的所有顶点采用顺序存储结构, 构成一个数组, 该数组称为 <b>顶点表</b>.
//      该数组的节点元素信息为 数据域data + 指针域*first
//   2. 对图G中的每个顶点的 边 建立一个单链表,
//          即该单链表中的节点为 依附于该顶点的边(对于有向图是以该顶点为尾的弧)),
//          节点元素信息为: 邻接点域adjVex - 存储与该顶点相邻接的其他顶点
//                        指针域nextArc - 指向下一条边的边表节点
//      该单链表就称为该顶点的 <b>边表</b>(对于有向图则称为出边表).
//      顶点表中的指针域*first指向 边表的第一个节点.

#define ALMaxSize 100
typedef char VertexType;
// 边节点
typedef struct arcNode {
    int index; // 当前节点在数组vertices[]的下标索引
    struct arcNode *nextArc; // 指针域, 指向下一个节点在数组vertices[]的下标索引
    // InfoType info; // 边的权值
} ArcNode;

// 顶点节点
typedef struct vexNode {
    VertexType data; // 数据域, 节点中的数据信息
    ArcNode *firstArc;  // 指针域, 指向数组vertices[]的下标索引
} VexNode;

// 这段代码定义了一个新的数据类型 AdjList，
// 它是一个数组，数组的每个元素都是一个 VexNode 类型的结构体。
// 这个数组通常用来表示图的邻接表。
typedef VexNode AdjList[ALMaxSize];

// 图
typedef struct alGraph{
//    AdjList vertices; // 邻接表,
    // 顶点数组
//    VexNode adjList[ALMaxSize];
    VexNode vertices[ALMaxSize];
    int vexNum; // 图的顶点数
    int arcNum; // 图的边(弧)数
} ALGraph;


#endif //CS_WANGDAO_ALGRAPH_H
