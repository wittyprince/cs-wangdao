//
// Created by 51676 on 2024/8/1.
//

#ifndef CS_WANGDAO_PARENTTREE_H
#define CS_WANGDAO_PARENTTREE_H

// 树的双亲表示法 - 顺序存储
//      也可以用于表示森林
//  注意: 与二叉树的顺序存储的区别
//  树的顺序存储结构中, 数组下标代表节点的标号, 下标中所存的parent指示了节点之间的关系。
//  二叉树的顺序存储结构中, 数组下标既代表了节点的编号, 又指示了二叉树中各节点之间的关系。
//  其实, 二叉树属于树, 所以二叉树也可以用树的存储结构来存储。
//  但, 树却不能用二叉树的存储结构来存储。
#define ParentTreeMaxSize 10
typedef int ElementType;
// 树的节点的定义
typedef struct parentTreeNode {
    ElementType data; // 数据域
    int parent; // parent的下标, 双亲位置域
} ParentTreeNode;

// 树的类型定义
typedef struct parentTree {
    ParentTreeNode data[ParentTreeMaxSize]; // 数组
    int length; // 数组的长度, 即节点数
} ParentTree;

#endif //CS_WANGDAO_PARENTTREE_H
