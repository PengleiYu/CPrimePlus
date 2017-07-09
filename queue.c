//
// Created by yupenglei on 2017/7/9.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"

static void CopyToNode(Item item, Node *pnew);

static void CopyToItem(Item *item, Node *pt);

void InitializeQueue(Queue *pq) {
    pq->front = pq->rear = NULL;
    pq->items = 0;
}

bool QueueIsFull(const Queue *pq) {
    return pq->items == MAXQUEUE;
}

bool QueueIsEmpty(const Queue *pq) {
    return pq->items == 0;
}

int QueueItemCount(const Queue *pq) {
    return pq->items;
}

bool EnQueue(Item item, Queue *pq) {
    Node *pnew;
    if (QueueIsFull(pq)) {
        return false;
    }
    pnew = malloc(sizeof(Node));
    if (pnew == NULL) {
        fprintf(stderr, "Unable to allocate memory\n");
        exit(1);
    }
    CopyToNode(item, pnew);
    pnew->next = NULL;
    if (QueueIsEmpty(pq)) {
        pq->front = pnew;
    } else pq->rear->next = pnew;
    pq->rear = pnew;
    pq->items++;
    return true;
}

bool DeQueue(Item *pitem, Queue *pq) {
    Node *pt;
    if (QueueIsEmpty(pq)) {
        return false;
    }
    CopyToItem(pitem, pq->front);
    pt = pq->front;
    pq->front = pt->next;
    pq->items--;
    free(pt);
    if (QueueIsEmpty(pq)) {
        pq->rear = NULL;
    }
    return true;
}

void EmptyTheQueue(Queue *pq) {
    Item dummy;
    while (!QueueIsEmpty(pq)) {
        DeQueue(&dummy, pq);
    }
}

static void CopyToNode(Item item, Node *pnew) {
    pnew->item = item;
}

static void CopyToItem(Item *item, Node *pt) {
    *item = pt->item;
}

