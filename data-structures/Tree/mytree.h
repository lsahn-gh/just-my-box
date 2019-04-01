#pragma once

#include "xz-tree.h"

typedef struct
{
    XZTreeNode _;
    int data;
} MyTreeNode;

#define MY_TREE_NODE(_ptr) ((MyTreeNode*)_ptr)

int my_tree_cmp (XZTreeNode *node_a, XZTreeNode *node_b);

MyTreeNode * my_tree_node_new (int data);
