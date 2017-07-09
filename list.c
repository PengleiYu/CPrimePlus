//
// Created by yupenglei on 2017/7/8.
//
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

static void CopyToNode(Item item, Node *pnode);

void InitializeList(List *plist) {
    *plist = NULL;
}

bool ListIsEmpty(const List *plist) {
    return *plist == NULL ? true : false;
}

bool ListIsFull(const List *plist) {
    Node *pt;
    bool full;

    pt = malloc(sizeof(Node));
    full = pt == NULL ? true : false;
    free(pt);
    return full;
}

unsigned ListItemCount(List *plist) {
    unsigned int count = 0;
    Node *pnode = *plist;
    while (pnode != NULL) {
        count++;
        pnode = pnode->next;
    }
    return count;
}

bool AddItem(Item item, List *plist) {
    Node *pnew;
    Node *scan = *plist;

    pnew = malloc(sizeof(Node));
    if (pnew == NULL)
        return false;

    CopyToNode(item, pnew);
    pnew->next = NULL;
    if (scan == NULL) {
        *plist = pnew;
    } else {
        while (scan->next != NULL) {
            scan = scan->next;
        }
        scan->next = pnew;
    }
    return true;
}

void Traverse(const List *plist, void(*pFunc)(Item item)) {
    Node *pnode = *plist;
    while (pnode != NULL) {
        (*pFunc)(pnode->item);
        pnode = pnode->next;
    }
}

void EmptyTheList(List *plist) {
    Node *psave;
    while (*plist != NULL) {
        psave = (*plist)->next;
        free(*plist);
        *plist = psave;
    }
}

static void CopyToNode(Item item, Node *pnode) {
    pnode->item = item;
}
