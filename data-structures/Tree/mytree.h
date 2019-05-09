#ifndef MY_TREE_H
#define MY_TREE_H

#include "xz-tree.h"

typedef struct
{
    XZTreeNode _;
    int data;
} MyTreeNode;

#define MY_TREE_NODE(_ptr) ((MyTreeNode*)_ptr)

int my_tree_cmp (XZTreeNode *node_a, XZTreeNode *node_b);

MyTreeNode * my_tree_node_new   (int data);
MyTreeNode * my_tree_find       (XZTreeNode *root, int value);
MyTreeNode * my_tree_find_recur (XZTreeNode *root, int value);
MyTreeNode * my_tree_find_min   (XZTreeNode *root);
MyTreeNode * my_tree_find_max   (XZTreeNode *root);

#endif
