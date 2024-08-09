//
// Created by 51676 on 2024/8/7.
//
#include <stdio.h>
#include <stdlib.h>

// 二分查找/折半查找
int binarySearch(int a[], int low, int high, int target) {
    int mid;
    while (low <= high) {
        mid = low + high;
        if (a[mid] == target) {
            return mid;
        } else if (a[mid] > target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

int binarySearchRecursive(int a[], int low, int high, int target) {
    int mid = (low + high) / 2;
    if (/*mid >=0 && */low <= high) {
        if (a[mid] == target) {
            return mid;
        } else if (a[mid] > target) {
            return binarySearchRecursive(a, low, mid - 1, target);
        } else {
            return binarySearchRecursive(a, mid + 1, high, target);
        }
    }
    return -1;
}


int main() {

    int a[] = {-1,0,3,5,9,12};

    int target = binarySearch(a, 0, 5, 2);
    printf("%d\n", target);

    int target2 = binarySearchRecursive(a, 0, 5, 3);
    printf("%d\n", target2);


    return 0;
}