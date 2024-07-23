//
// Created by 51676 on 2024/7/22.
//

#ifndef CS_WANGDAO_SQQUEUE_H
#define CS_WANGDAO_SQQUEUE_H

#define QueueMaxSize 50

typedef int ElementType;
// 顺序队列(循环队列)
typedef struct {
    ElementType data[QueueMaxSize];
    int front; // 队头指针, 指向队头元素
    int rear;  // 队尾指针, 指向队尾元素的下一个位置
} SqQueue;

void initSqQueue(SqQueue &Q) {
    Q.front = Q.rear = 0;
}

// 为了区分队满还是队空, 有三种处理方式
// 1. 牺牲一个存储单元来区分是队满还是队空, 入队时少用一个队列单元, 较常用.(本体示例选择此种方式)
// 2. 增加一个size字段, 来表示数据成员个数。插入成功时size加1, 删除成功时, size减1.
// 3. 增加一个tag字段, 表示是插入操作还是删除操作。tag = 1表示插入操作, tag = 0 表示删除操作。
bool isSqQueueEmpty(SqQueue Q) {
    // 这里使用 Q.front == Q.rear, 而不是 Q.front % MaxSize == Q.rear % MaxSize;
    // 是应为 在enSqQueue()方法 和 deSqQueue()方法中对 Q.rear 和 Q.front 做了处理
    return Q.front == Q.rear;
}

bool isSqQueueFull(SqQueue Q) {
    // 这里使用的是 Q.front, 而不是 Q.front % QueueMaxSize, 是因为 在入队enSqQueue() 方法时对Q.front做了处理
    // 即 Q.rear = (Q.rear + 1) % QueueMaxSize; 已经做了处理
    return (Q.rear + 1) % QueueMaxSize == Q.front;
}

bool enSqQueue(SqQueue &Q, ElementType e) {
    // 判断队满
    if ((Q.rear + 1) % QueueMaxSize == Q.front) {
        return false;
    }
    Q.data[Q.rear] = e;
    // 由于在出队时, 可能会假溢出的情况, 即假想中的循环队列,
    // 所以 这里不能简单的++, 而是要进行加1取模运算
//    Q.rear++;
    Q.rear = (Q.rear + 1) % QueueMaxSize;
    return true;
}

bool deSqQueue(SqQueue &Q, ElementType &e) {
    // 判断队空
    if (Q.front == Q.rear) {
        return false;
    }
    e = Q.data[Q.front];
    // 同入队操作类似, 出队时也有可能出现价溢出的情况
    // 所以 这里也不能简单的++, 而是要进行加1取模运算
//    Q.front++;
    Q.front = (Q.front + 1) % QueueMaxSize;
    return true;
}

#endif //CS_WANGDAO_SQQUEUE_H
