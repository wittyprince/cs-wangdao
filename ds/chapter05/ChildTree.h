//
// Created by 51676 on 2024/8/1.
//

#ifndef CS_WANGDAO_CHILDTREE_H
#define CS_WANGDAO_CHILDTREE_H

// ref: https://www.cnblogs.com/desola/p/12707029.html

// 树的孩子表示法 - 顺序存储 + 链式存储
//      也可以用于表示森林, 但是需要改造,
//          即要保存多个根节点的位置rootIdx1, rootIdx2...
//              但是数组及数组长度可以沿用

#define ChildTreeMaxSize 10
typedef int ElementType;

// 孩子链表的孩子节点
typedef struct childTreeNode {
//    ElementType data; // 数据域-数据元素
//    int firstChild; // 第一个孩子节点的位置索引
    int childIndex; // 孩子节点在数组中的位置 - 数据域, 即用来存储某个节点在 <b>表头数组</b> 中的下标
    struct childTreeNode *next; // 下一个孩子 - 指针域, 用来存储该节点的下一个孩子节点的指针
} ChildTreeNode;

// 表头数组的(表头)节点
typedef struct childTreeBox {
    ElementType data; // 数据域-存储数据信息
    ChildTreeNode *firstChild; // 第一个孩子节点的指针 - 头指针域, 用来存储该节点的孩子链表的头指针
} ChildTreeBox;

// 树结构
typedef struct childTree {
    ChildTreeBox box[ChildTreeMaxSize]; // 节点数组
    int length; // 数组长度, 即节点数
    int rootIndex; // 根节点的位置
} ChildTree;

#endif //CS_WANGDAO_CHILDTREE_H
