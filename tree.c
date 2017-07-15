//
// Created by yupenglei on 2017/7/9.
//

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tree.h"

typedef struct pair {
    Trnode *parent;
    Trnode *child;
} Pair;

/*
 * 局部函数原型
 */
static void InOrder(const Trnode *root, void(*pFunc)(Item item));

static void DeleteAllNodes(Trnode *root);

static void AddNode(Trnode *new_node, Trnode *root);

static int Compare(const Item *item1, const Item *item2);

static Trnode *MakeNode(const Item *pi);

static Pair SeekItem(const Item *pi, const Tree *ptree);

static void DeleteNode(Trnode **ptr);


/*
 * 函数定义
 */

void InitializeTree(Tree *ptree) {
    ptree->root = NULL;
    ptree->size = 0;
}

bool TreeIsEmpty(Tree *ptree) {
    return ptree->root == NULL;
}

bool TreeIsFull(Tree *ptree) {
    return ptree->size == MAXITEMS;
}

int TreeItemCount(const Tree *ptree) {
    return ptree->size;
}

bool AddItem(const Item *pi, Tree *ptree) {
    Trnode *new_node;
    if (TreeIsFull(ptree)) {
        return false;
    }
    if (SeekItem(pi, ptree).child != NULL) {
        return false;//duplicate item
    }
    new_node = MakeNode(pi);
    if (new_node == NULL) {
        return false;// can`t create node
    }
    ptree->size++;
    if (ptree->root == NULL) {
        ptree->root = new_node;
    } else {
        AddNode(new_node, ptree->root);
    }
    return true;
}

bool InTree(const Item *pi, const Tree *ptree) {
    return !SeekItem(pi, ptree).child == NULL;
}

bool DeleteItem(const Item *pi, Tree *ptree) {
    Pair look;
    look = SeekItem(pi, ptree);
    if (look.child == NULL) {
        return false;//not found
    }
    if (look.parent == NULL) {
        DeleteNode(&(ptree->root));
    } else if (look.parent->left == look.child) {
        DeleteNode(&(look.parent->left));
    } else
        DeleteNode(&(look.parent->right));
    ptree->size--;
    return true;
}

void Traverse(const Tree *ptree, void(*pFun)(Item item)) {
    if (ptree != NULL) {
        InOrder(ptree->root, pFun);
    }
}

void DeleteAll(Tree *ptree) {
    if (ptree != NULL) {
        DeleteAllNodes(ptree->root);
        ptree->root = NULL;
        ptree->root = 0;
    }
}

/* * 局部函数 */

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

void InOrder(const Trnode *root, void (*pFunc)(Item)) {
    if (root != NULL) {
        InOrder(root->left, pFunc);
        (*pFunc)(root->item);
        InOrder(root->right, pFunc);
    }

}

void DeleteAllNodes(Trnode *root) {
    Trnode *pright;
    if (root != NULL) {
        pright = root->right;
        DeleteAllNodes(root->left);
        free(root);
        DeleteAllNodes(pright);
    }
}

void AddNode(Trnode *new_node, Trnode *root) {
    int comp = Compare(&new_node->item, &root->item);
    if (comp < 0) {
        if (root->left == NULL) {
            root->left = new_node;
        } else {
            AddNode(new_node, root->left);
        }
    } else if (comp > 0) {
        if (root->right == NULL) {
            root->right = new_node;
        } else {
            AddNode(new_node, root->right);
        }
    } else {
        fprintf(stderr, "location error in AddNode()\n");
        exit(1);
    }
}

static int Compare(const Item *item1, const Item *item2) {
    int comp;
    if ((comp = strcmp(item1->petName, item2->petName)) != 0) {
        return comp;
    } else {
        return strcmp(item1->petKind, item2->petKind);
    }
}

Pair SeekItem(const Item *pi, const Tree *ptree) {
    Pair look;
    look.parent = NULL;
    look.child = ptree->root;
    if (look.child == NULL) {
        return look;
    }

    while (look.child != NULL) {
        int comp = Compare(pi, &(look.child->item));
        if (comp < 0) {
            look.parent = look.child;
            look.child = look.child->left;
        } else if (comp > 0) {
            look.parent = look.child;
            look.child = look.child->right;
        } else {
            break;
        }
    }
    return look;
}

void DeleteNode(Trnode **ptr) {
    Trnode *temp;
    if ((*ptr)->left == NULL) {
        temp = *ptr;
        *ptr = (*ptr)->right;
        free(temp);
    } else if ((*ptr)->right == NULL) {
        temp = *ptr;
        *ptr = (*ptr)->left;
        free(temp);
    } else {
        for (temp = (*ptr)->left; temp->right != NULL; temp = temp->right)
            continue;
        temp->right = (*ptr)->right;
        temp = *ptr;
        *ptr = (*ptr)->left;
        free(temp);
    }
}
