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


int main() {

    int a[] = {-1,0,3,5,9,12};

    int target = binarySearch(a, 0, 5, 2);
    printf("%d", target);


    return 0;
}