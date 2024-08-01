//
// Created by 51676 on 2024/8/1.
//

#ifndef CS_WANGDAO_CSTREE_H
#define CS_WANGDAO_CSTREE_H

// 树的孩子兄弟表示法 - 链式存储
//      基于二叉链表实现
//  也可以用于表示森林
typedef int ElementType;

typedef struct csTreeNode {
    ElementType data; // 数据域
    struct csTreeNode *firstChild; // 第一个孩子
    struct csTreeNode *sibling; // 右兄弟
} CSTreeNode, *CSTree;

#endif //CS_WANGDAO_CSTREE_H
