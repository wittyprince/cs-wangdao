//
// Created by 51676 on 2024/7/12.
//


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MaxSize 7

typedef int ElementType;

typedef struct {
    ElementType data[MaxSize];
    int length;
} SqList;

void init(SqList &L) {
    L.length = 0;
}

int main() {

    SqList L;
    init(L);
//    L.data = {3, 87, 2, 93, 78, 56, 61, 38, 12, 40};
    srand(time(NULL));
    for (int i = 0; i < MaxSize; ++i) {
        L.data[i] = i;
        L.length++;
    }
    L.data[2] = 1;
//    int k = L.length -1;

    for (int j = 0; j < L.length; ++j) {
        if (L.data[j] == 1) {
//            L.data[j] = L.data[k];
//            k--;
            //TODO 注意, 这里需要再判断L.data[L.length -1]也不能等于给定的数x
            L.data[j] = L.data[L.length -1];
            L.length--;
        }
    }

    for (int m = 0; m < L.length; ++m) {
        printf("%d\n", L.data[m]);
    }


    return 0;
}
