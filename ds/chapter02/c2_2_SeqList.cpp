//
// Created by 51676 on 2024/7/12.
//

#include <stdlib.h>

#define InitSize 10

typedef int ElementType;

typedef struct {
    ElementType *data;
    int length; // 当前长度
    int MaxSize; // 最大容量, 当达到最大容量或者即将达到最大容量时, 需进行扩容
} SeqList;

void init(SeqList &L) {
    L.data = (ElementType *) malloc(sizeof(ElementType) * InitSize);
    L.length = 0; // 初始长度为0
    L.MaxSize = InitSize; // 初始存储容量
}

int main() {

    return 0;
}