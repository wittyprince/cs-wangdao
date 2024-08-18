//
// Created by 51676 on 2024/8/18.
//

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

int partition(int a[], int low, int high) {
    // 每次都取第一个元素作为基准
    int pivot = a[low];
    int i, j;
    for (i = low, j = high; j > i; ) {
        // 从后往前, 找到第一个小于pivot的元素, 进行交换
        //   如果从i=0开始, 那么这一步j--是可以取到0的
        //   如果i>0, 那么说明已经有元素被对比过了
        while (a[j] > pivot && j > i) {
            j--;
        }
        a[i] = a[j];
//        if (i != j) { // 这里if里的i++的想法是从i+1个位置接着向后判断, 如果不用i++, 那么就是在i的位置处要判断一次, 这里多判断一个也不影响最后结果
//            a[i] = a[j];
//            i++;
//        }

        // 从前往后, 找到第一个大于pivot的元素, 进行交换
        while (a[i] < pivot && i < j) {
            i++;
        }
        a[j] =  a[i];
//        if (i != j) { // 这里同上的解释
//            a[j] =  a[i];
//            j--;
//        }
    }
    // 此时 i = j
    a[i] = pivot;
    return i;
}

// 快速排序 - 不稳定的 - 交换类排序 - 内部排序中 性能最好的
void quickSort(int a[], int low, int high) {
    if (low < high) {
        // 这里的partition()方法目的是找到pivot的最终位置
        int pivotPosition = partition(a, low, high);
//        printArray(a, 9);
        quickSort(a, low, pivotPosition - 1);
        quickSort(a, pivotPosition + 1, high);
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
    quickSort(a, 0, length - 1);
    printArray(a, length);
    return 0;
}