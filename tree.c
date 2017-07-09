//
// Created by yupenglei on 2017/7/9.
//

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tree.h"

static Trnode *MakeNode(const Item *pi);

static int compare(const Item *item1, const Item *item2);

Trnode *MakeNode(const Item *pi) {
    Trnode *new_node;
    new_node = malloc(sizeof(Trnode));
    if (new_node != NULL) {
        new_node->item = *pi;
        new_node->left = NULL;
        new_node->right = NULL;
    }
    return new_node;
}

static int compare(const Item *item1, const Item *item2) {
}

