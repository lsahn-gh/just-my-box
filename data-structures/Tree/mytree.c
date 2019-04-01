#include <stdlib.h>

#include "mytree.h"

MyTreeNode *
my_tree_node_new (int data)
{
    MyTreeNode *new_node;

    new_node = (MyTreeNode*)malloc(sizeof(MyTreeNode));
    XZ_TREE_NODE (new_node)->left = NULL;
    XZ_TREE_NODE (new_node)->right = NULL;
    new_node->data = data;

    return new_node;
}

int
my_tree_cmp (XZTreeNode *node_a, XZTreeNode *node_b)
{
    MyTreeNode *root= MY_TREE_NODE (node_a);
    MyTreeNode *new= MY_TREE_NODE (node_b);

    if (root->data > new->data)
        return -1;
    else if (root->data < new->data)
        return 1;
    else
        return 0;
}

