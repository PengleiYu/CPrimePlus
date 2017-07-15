//
// Created by yupenglei on 2017/7/9.
//
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

void print(Item item) {
    printf("%d ", item);
}

void test() {
    Tree tree;
    Item *pet;
    InitializeTree(&tree);


    for (int i = 0; i < 10; i++) {

    }
    Traverse(&tree, &print);
}

int main() {
    test();
}

