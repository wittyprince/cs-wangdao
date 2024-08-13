//
// Created by 51676 on 2024/8/12.
//
// 红黑树
// 左根右, 根叶黑, 不红红, 黑路同
typedef struct rbNode {
    int key;
    struct rbNode *parent; // 父节点
    struct rbNode *left, *right;
    int color; // 节点颜色, 0-黑色, 1-红色
} RBNode, *RBTree;

int main() {

    return 0;
}