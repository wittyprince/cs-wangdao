//
// Created by 51676 on 2024/8/13.
//

// m阶B树/m叉B树

#define M 5

typedef int ElementType;

typedef struct mNode {
    ElementType keys[M - 1]; // 最多M-1个关键字
    struct mNode *child[M]; // 最多5个孩子
    int num; // 节点中实际有几个关键字, 每个节点中的关键字个数都可能不相同
} MNode, *MTree;
