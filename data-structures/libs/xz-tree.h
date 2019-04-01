#pragma once

#include "common.h"

typedef struct _XZTreeNode XZTreeNode;
typedef struct _XZTree XZTree;

typedef int (*CompareFunc) (XZTreeNode *node1, XZTreeNode *node2);

struct _XZTreeNode
{
    gpointer left;
    gpointer right;
};

struct _XZTree
{
    XZTreeNode *root;
    CompareFunc cmp;
};

#define XZ_TREE_NODE(_ptr) ((XZTreeNode*)_ptr)
#define COMPARE_FUNC(_fptr) ((CompareFunc)_fptr)

XZTree * xz_tree_new (CompareFunc cmp_func);
void xz_tree_insert (XZTree *tree, gpointer user_data);
void xz_tree_destroy (XZTree **ptrtree);

