/*
 * Karumanchi N. - Data Structures and Algorithms Made Easy
 * 
 * Section : Tree
 * Problem : No. 8
 * 
 * Give an algorithm for printing the level order data in reverse order.
 * 
 * O(N) for time-complexity, O(N) for space-complexity.
 */

#include <stdio.h>
#include <stdlib.h>
#include <glib.h>

#include "mytree.h"

void
print_level_order_reverse (XZTreeNode *root)
{
    GStack stack = G_STACK_INIT;
    GQueue queue = G_QUEUE_INIT;
    XZTreeNode *cur;

    if (root == NULL)
        return;

    g_queue_push_tail (&queue, root);
    while (!g_queue_is_empty (&queue)) {
        cur = g_queue_pop_head (&queue);
        g_stack_push (&stack, cur);

        if (cur->right)
            g_queue_push_tail (&queue, cur->right);
        if (cur->left)
            g_queue_push_tail (&queue, cur->left);
    }

    while (!g_stack_is_empty (&stack)) {
        cur = g_stack_pop (&stack);
        g_print ("%d ", MY_TREE_NODE (cur)->data);
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

    /* Output
     *
     * 7 1 4 6 2 5 3
     */
    print_level_order_reverse (tree->root);

    xz_tree_destroy (&tree);

    return 0;
}