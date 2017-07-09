//
// Created by yupenglei on 2017/7/9.
//

#ifndef CPRIMEPLUS_QUEUE_H
#define CPRIMEPLUS_QUEUE_H

#include <stdbool.h>

typedef struct item {
    long arrive;//顾客到达时间
    int processTime;//该顾客咨询时间
} Item;
//typedef int Item;
#define MAXQUEUE 10
typedef struct node {
    Item item;
    struct node *next;
} Node;

typedef struct queue {
    Node *front;
    Node *rear;
    int items;
} Queue;

void InitializeQueue(Queue *pq);

bool QueueIsFull(const Queue *pq);

bool QueueIsEmpty(const Queue *pq);

int QueueItemCount(const Queue *pq);

bool EnQueue(Item item, Queue *pq);

bool DeQueue(Item *pitem, Queue *pq);

void EmptyTheQueue(Queue *pq);

#endif //CPRIMEPLUS_QUEUE_H
