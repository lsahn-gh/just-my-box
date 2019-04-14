#include <stdio.h>
#include <stdlib.h>
#include <glib.h>

#include "mytree.h"

void
in_order (XZTreeNode *root)
{
    GQueue stack = G_QUEUE_INIT;
    XZTreeNode *cur = root;

    while (1) {
        while (cur) {
            g_queue_push_head (&stack, cur);
            cur = cur->left;
        }
        if (g_queue_is_empty (&stack))
            break;

        cur = g_queue_pop_head (&stack);
        g_print ("%d ", MY_TREE_NODE (cur)->data);
        cur = cur->right;
    }

    g_assert (g_queue_is_empty (&stack));
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

    /* Output: 2 3 4 5 6 7 */
    in_order(tree->root);
    g_print ("\n");

    xz_tree_destroy (&tree);

    return 0;
}
