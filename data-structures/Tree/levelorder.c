#include <stdio.h>
#include <stdlib.h>
#include <glib.h>

#include "mytree.h"

void
level_order (XZTreeNode *root)
{
    GQueue queue = G_QUEUE_INIT;

    if (root == NULL)
        return;

    g_queue_push_tail (&queue, root);

    while (!g_queue_is_empty (&queue)) {
        XZTreeNode *cur = g_queue_pop_head (&queue);
        g_print ("%d ", MY_TREE_NODE (cur)->data);
        if (cur->left)
            g_queue_push_tail (&queue, cur->left);
        if (cur->right)
            g_queue_push_tail (&queue, cur->right);
    }
}

int
main (void)
{
    XZTree *tree;

    tree = xz_tree_new (COMPARE_FUNC (my_tree_cmp));

    /*
     *     3
     *    / \
     *   2   5
     *  /   / \
     * 1   4   6
     *          \
     *           7
     */
    xz_tree_insert (tree, my_tree_node_new (3));
    xz_tree_insert (tree, my_tree_node_new (2));
    xz_tree_insert (tree, my_tree_node_new (1));
    xz_tree_insert (tree, my_tree_node_new (5));
    xz_tree_insert (tree, my_tree_node_new (4));
    xz_tree_insert (tree, my_tree_node_new (6));
    xz_tree_insert (tree, my_tree_node_new (7));

    /* Output: 3 2 5 1 4 6 7 */
    level_order (tree->root);
    g_print ("\n");

    xz_tree_destroy (&tree);

    return 0;
}
