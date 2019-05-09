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

MyTreeNode *
my_tree_find_recur (XZTreeNode *root, int value)
{
    npointer ptr;

    if (root == NULL)
        return NULL;

    if (value == MY_TREE_NODE (root)->data)
        ptr = root;
    else if (value < MY_TREE_NODE (root)->data)
        ptr = my_tree_find (root->left, value);
    else
        ptr = my_tree_find (root->right, value);
    
    return ptr;
}

MyTreeNode *
my_tree_find (XZTreeNode *root, int value)
{
    XZTreeNode *cur = root;

    while (cur) {
        if (value == MY_TREE_NODE (cur)->data)
            break;
        else if (value < MY_TREE_NODE (cur)->data)
            cur = cur->left;
        else
            cur = cur->right;
    }

    return MY_TREE_NODE (cur);
}

MyTreeNode *
my_tree_find_min (XZTreeNode *root)
{
    XZTreeNode *cur = root;

    if (root == NULL)
        return NULL;

    while (cur->left)
        cur = cur->left;

    return MY_TREE_NODE (cur);
}

MyTreeNode *
my_tree_find_max (XZTreeNode *root)
{
    XZTreeNode *cur = root;

    if (root == NULL)
        return NULL;

    while (cur->right)
        cur = cur->right;

    return MY_TREE_NODE (cur);
}
