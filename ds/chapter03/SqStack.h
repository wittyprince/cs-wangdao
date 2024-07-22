//
// Created by 51676 on 2024/7/22.
//

#ifndef CS_WANGDAO_SQSTACK_H
#define CS_WANGDAO_SQSTACK_H

#define StackMaxSize 50

typedef int ElementType;

typedef struct {
    ElementType data[StackMaxSize];
    int top; // 指向栈顶元素
} SqStack;

void initSqStack(SqStack &S) {
    S.top = -1;
}

bool stackEmpty(SqStack S) {
    return S.top == -1;
}

bool push(SqStack &S, ElementType e) {
    // 判断栈满
    // 注意top是从-1开始的
    if (S.top + 1 == StackMaxSize) {
        return false;
    }
    S.top++;
    S.data[S.top] = e;
    return true;
}

bool pop(SqStack &S, ElementType &e) {
    // 判断栈空
    if (S.top == -1) {
        return false;
    }
    e = S.data[S.top];
    S.top--;
    return true;
}

bool getTop(SqStack S, ElementType &e) {
    // 判断栈空
    if (S.top == -1) {
        return false;
    }
    e = S.data[S.top];
    return true;
}

#endif //CS_WANGDAO_SQSTACK_H
