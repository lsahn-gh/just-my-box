#include <stdio.h>
#include <stdlib.h>
#include <glib.h>

#include "mytree.h"

void
pre_order_loop (XZTreeNode *root)
{
    /* GQueue of GLib can be used as Stack because it is double-linked Queue.
     * At this time, I take the advantage of GQueue */
    GQueue queue = G_QUEUE_INIT;

    if (root == NULL)
        return;

    while (1) {
        while (root) {
            g_print ("%d ", MY_TREE_NODE (root)->data);
            g_queue_push_head (&queue, root);
            root = root->left;
        }
        if (g_queue_is_empty (&queue))
            break;
        root = g_queue_pop_head (&queue);
        root = root->right;
    }
}

int
main (void)
{
    XZTree *tree;

    tree = xz_tree_new (COMPARE_FUNC (my_tree_cmp));

    /*
     *   3
     *  / \
     * 2   5
     *    / \
     *   4   6
     *        \
     *         7
     */
    xz_tree_insert (tree, my_tree_node_new (3));
    xz_tree_insert (tree, my_tree_node_new (2));
    xz_tree_insert (tree, my_tree_node_new (5));
    xz_tree_insert (tree, my_tree_node_new (4));
    xz_tree_insert (tree, my_tree_node_new (6));
    xz_tree_insert (tree, my_tree_node_new (7));

    /* Output: 3 2 5 4 6 7 */
    pre_order_loop (XZ_TREE_NODE (tree->root));
    g_print ("\n");

    xz_tree_destroy (&tree);

    return 0;
}

