//
// Created by 51676 on 2024/8/2.
//

#ifndef CS_WANGDAO_OLGRAPH_H
#define CS_WANGDAO_OLGRAPH_H

// ref: https://www.cnblogs.com/cuish/p/3764550.html

// 十字链表 Orthogonal List
//      链式存储结构
//      可以看成是【邻接表】和【逆邻接表】的结合。
// 图中每条弧对应一个【弧结点】，每个顶点对应一个【顶点结点】

/**
    弧结点
    --------------------------------------------
    | tailVex | headVex | hLink | tLink | info |
    --------------------------------------------
    tailVex: 弧尾结点 在图中的位置
    headVex: 弧头结点 在图中的位置
    hLink:   下一条与该弧有【相同弧头的弧】
    tLink:   下一条与该弧有【相同弧尾的弧】
    info:    弧的相关信息，权值等

    顶点结点
    -----------------------------
    | data | firstIn | firstOut |
    -----------------------------
    data:     该结点的数据
    firstIn:  第一条以该顶点为弧头的【弧结点】
    firstOut: 第一条以该顶点为弧尾的【弧结点】
 */

#define OLMaxSize 100 // //顶点最大数量

//数据结构
typedef int InfoType;
typedef int DataType;
typedef char VertexType;

// 弧节点
typedef struct arcNode {
    int tailVex; // 弧尾结点 在图中的位置
    int headVex; // 弧头结点 在图中的位置
    struct arcNode *hLink; // 下一条与该弧有【相同弧头的弧】
    struct arcNode *tLink; // 下一条与该弧有【相同弧尾的弧】
    InfoType info; // 弧的权值或其他信息
} ArcNode;

// 顶点节点
typedef struct vexNode {
    VertexType data; // 该结点的数据
    ArcNode *firstIn; // 第一条以该顶点为弧头的【弧结点】
    ArcNode *firstOut; // 第一条以该顶点为弧尾的【弧结点】
} VexNode;

// 十字链表 存储的有向图
typedef struct {
    VexNode vertices[OLMaxSize]; // 顶点向量数组
    int vexNum; // 顶点数
    int arcNum; // 弧数
} OLGraph;

#endif //CS_WANGDAO_OLGRAPH_H
