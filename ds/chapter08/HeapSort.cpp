//
// Created by 51676 on 2024/8/19.
//

// 堆排序 - 不稳定 - 选择类排序
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArray(int a[], int length) {
    for (int i = 0; i < length; ++i) {
        printf("%3d,", a[i]);
    }
    printf("\n");
}


void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

/**
 * 调整堆
 *    本方法只负责调整以idxOfRoot为根节点的树及其子树
 *    不负责从idxOfLastRoot = length / 2 - 1;开始遍历到idxOfRoot = 0的所有节点树
 *    所以要分清职责
 */
void adjust(int a[], int idxOfRoot, int length) {
    // 数组下标从0开始
    // 非叶子节点下标为 0 ~ length/2 - 1
    // 叶子节点下标为 length/2 ~ length - 1
    int dadIdx = idxOfRoot;// idxOfRoot 的最大值为 length / 2 - 1;
    int sonIdx = dadIdx * 2 + 1; // 左孩子

    while (sonIdx < length) {
        // sonIdx + 1 < length 判断是否有右孩子
        if (sonIdx + 1 < length && a[sonIdx] < a[sonIdx + 1]) {
            sonIdx = sonIdx + 1; // 取值较大的
        }
        // 大顶堆
        if (a[dadIdx] < a[sonIdx]) {
            swap(a[dadIdx], a[sonIdx]);
            // 如果发生了调整, 为防止上面swap交换后, 子树不满足大顶堆, 需要遍历调整子树
            dadIdx = sonIdx;
            sonIdx = dadIdx * 2 + 1;
        } else {
            // 如果未发生交换, 说明该子树不需要调整
            break; // 防止 while (sonIdx < length) 死循环
        }
    }
}

/**
 * 建堆
 */
void buildMaxHeap(int a[], int length) {
    // 数组下标从0开始
    int idxOfLastRoot = length / 2 - 1;
    // 非叶子节点下标为 0 ~ length/2 - 1
    // 叶子节点下标为 length/2 ~ length - 1
    for (int i = idxOfLastRoot; i >=0; --i) {
        adjust(a, i, length);
    }
}

// 堆排序
void heapSort(int a[], int length) {
    // 1. 创建堆
    buildMaxHeap(a, length);
    // 2. 交换堆顶元素与堆尾元素
    swap(a[0], a[length - 1]);
    // 3. 继续调整堆, 使之成为大顶堆, 然后再交换
    int leftElementNum = length - 1;
    while (leftElementNum > 0) {
        // 调整剩余元素为大顶堆
        //      注意：由于上面第一遍已经把全部调整了一遍以满足大顶堆条件, 所以这里只需要调整根节点为0及其后续子节点即可
        adjust(a, 0, leftElementNum);
        // 交换
        swap(a[0], a[leftElementNum - 1]);
        // 改变循环遍历条件
        leftElementNum--;
    }
}

int main() {
    int length = 9;
    int a[9] = {3, 6, 7, 9, 2, 1, 10, 8, 0};
    srand(time(NULL));
    for (int i = 0; i < length; ++i) {
        a[i] = rand() % 100;
    }
    printArray(a, length);
    heapSort(a, length);
    printArray(a, length);
    return 0;
}