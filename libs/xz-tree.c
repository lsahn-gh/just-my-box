#include <stdlib.h>

#include "xz-tree.h"

/* ADT
 * - inserting
 * - deleting
 * - searching
 * - traversing
 * 
 * Aux
 * - get size
 * - get height
 * - get level which has maximum sum
 * - get least common ancestor (LCA) for a given pair of nodes, and many more.
 */

XZTree *
xz_tree_new (CompareFunc cmp_func)
{
    XZTree *new_tree;

    new_tree = (XZTree*)malloc(sizeof(XZTree));
    new_tree->root = NULL;
    new_tree->cmp = cmp_func;

    return new_tree;
}

void
xz_tree_insert (XZTree *tree, gpointer user_data)
{
    XZTreeNode *new_node = XZ_TREE_NODE (user_data);

    if (tree->root == NULL)
        tree->root = new_node;
    else {
        XZTreeNode *cur = tree->root;

        while (1) {
            int branch = tree->cmp (cur, new_node);

            switch (branch) {
            case -1:
                if (cur->left == NULL) {
                    cur->left = new_node;
                    goto out_of_loop;
                }
                cur = cur->left;
                break;
            case 0:
            case 1:
            default:
                if (cur->right == NULL) {
                    cur->right = new_node;
                    goto out_of_loop;
                }
                cur = cur->right;
                break;
            }
        }
out_of_loop:
        ;
    }
}

void
xz_tree_destroy (XZTree **ptrtree)
{
    GQueue queue = G_QUEUE_INIT;
    XZTree *tree = *ptrtree;

    if (tree == NULL)
        return;
    
    g_queue_push_tail (&queue, tree->root);
    while (!g_queue_is_empty (&queue)) {
        XZTreeNode *cur = g_queue_pop_head (&queue);
        if (cur->left)
            g_queue_push_tail (&queue, cur->left);
        if (cur->right)
            g_queue_push_tail (&queue, cur->right);
        g_free (cur);
    }
    g_assert (g_queue_get_length (&queue) == 0);

    g_free (*ptrtree);
    *ptrtree = NULL;
}