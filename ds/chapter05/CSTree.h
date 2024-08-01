//
// Created by 51676 on 2024/8/1.
//

#ifndef CS_WANGDAO_CSTREE_H
#define CS_WANGDAO_CSTREE_H

// 树的孩子兄弟表示法 - 链式存储
//      基于二叉链表实现
//  也可以用于表示森林
// 用途: 可以实现树转化为二叉树的操作, 易于查找节点的孩子,
//      缺点是查找当前节点的父节点比较麻烦, 可以通过增加parent域指向父节点来方便查找父节点
typedef int ElementType;

typedef struct csTreeNode {
    ElementType data; // 数据域
    struct csTreeNode *firstChild; // 第一个孩子
    struct csTreeNode *sibling; // 右兄弟
} CSTreeNode, *CSTree;

#endif //CS_WANGDAO_CSTREE_H
