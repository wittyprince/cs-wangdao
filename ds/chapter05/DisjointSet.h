//
// Created by 51676 on 2024/8/1.
//

#ifndef CS_WANGDAO_DISJOINTSET_H
#define CS_WANGDAO_DISJOINTSET_H

// DisjointSet 并查集

#define DisjointSetMaxSize 10

typedef int ElementType;

typedef struct disjointSet {
    ElementType ufSet[DisjointSetMaxSize]; // 集合元素数组
    int length; // 数组长度
} DisjointSet;

// 初始化-把每个元素初始化为 单元数 集合
void initUFSet(DisjointSet S) {
    for (int i = 0; i < S.length; ++i) {
        S.ufSet[i] = -1;
    }
}

/**
 * 查找下标为index的节点所属根节点的下标
 */
int findUFSet(DisjointSet S, int index) {
    while (S.ufSet[index] >= 0) { // 循环寻找index的跟
        index = S.ufSet[index];
    }
    return index; // 根的数组下标 小于 0
}

void unionUFSet(DisjointSet S, int root1Index, int root2Index) {
    // 要求root1和root2是不同的集合
    if (root1Index == root2Index) {
        return;
    }
    // 将root2链接到root1下面
    S.ufSet[root2Index] = root1Index;
}

// 如果用根节点的绝对值表示树的节点的总数
// 那么unionUFSet可以优化: 把小树合并到大树
void unionUFSet2(DisjointSet S, int root1Index, int root2Index) {
    // 要求root1和root2是不同的集合
    if (root1Index == root2Index) {
        return;
    }
    if (S.ufSet[root2Index] > S.ufSet[root1Index]) {
        S.ufSet[root1Index] += S.ufSet[root2Index];
        S.ufSet[root2Index] = root1Index;
    } else {
        S.ufSet[root2Index] += S.ufSet[root1Index];
        S.ufSet[root1Index] = root2Index;
    }
}

#endif //CS_WANGDAO_DISJOINTSET_H
