//
// Created by yupenglei on 2017/7/9.
//

#ifndef CPRIMEPLUS_TREE_H
#define CPRIMEPLUS_TREE_H

#include <stdbool.h>

#define SLEN 20
typedef struct item {
    char petName[SLEN];
    char petKind[SLEN];
} Item;
//typedef int Item;
#define MAXITEMS 10

typedef struct trnode {
    Item item;
    struct trnode *left;
    struct trnode *right;
} Trnode;
typedef struct tree {
    Trnode *root;
    int size;
} Tree;

void InitializeTree(Tree *ptree);

bool TreeIsEmpty(Tree *ptree);

bool TreeIsFull(Tree *ptree);

int TreeItemCount(const Tree *ptree);

bool AddItem(const Item *pi, Tree *ptree);

bool InTree(const Item *pi, const Tree *ptree);

bool DeleteItem(const Item *pi, Tree *ptree);

void Traverse(const Tree *ptree, void(*pFun)(Item item));

void DeleteAll(Tree *ptree);

#endif //CPRIMEPLUS_TREE_H
