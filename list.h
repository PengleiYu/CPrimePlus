//
// Created by yupenglei on 2017/7/8.
//

#ifndef CPRIMEPLUS_LIST_H
#define CPRIMEPLUS_LIST_H

#include <stdbool.h>

/**
 * 特定程序的声明
 */
#define TSIZE 45
struct film {
    char title[TSIZE];
    int rating;
};
/**
 * 一般类型的定义
 */
typedef struct film Item;
typedef struct node {
    Item item;
    struct node *next;
} Node;
typedef Node *List;

/**
 * 函数原型
 */
void InitializeList(List *plist);

bool ListIsEmpty(const List *plist);

bool ListIsFull(const List *plist);

unsigned ListItemCount(List *plist);

bool AddItem(Item item, List *plist);

void Traverse(const List *plist, void(*pFunc)(Item item));

void EmptyTheList(List *plist);

#endif //CPRIMEPLUS_LIST_H
