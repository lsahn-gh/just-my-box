/*
 * Karumanchi N. - Data Structures and Algorithms Made Easy
 *
 * Section : Tree
 * Problem : No. 12
 * 
 * Give an algorithm for finding the deepest node of the binary tree.
 * 
 * - O(N) for time-complexity.
 * 
 * - O(N) for extra spaces.
 * N refers to the number of the elements in the tree through the queue.
 */

#include <stdio.h>
#include <stdlib.h>
#include <glib.h>

#include "mytree.h"

MyTreeNode *
get_deepest_node (XZTreeNode *root)
{
    GQueue queue = G_QUEUE_INIT;
    XZTreeNode *cur;

    if (root == NULL)
        return NULL;

    g_queue_push_tail (&queue, root);
    while (!g_queue_is_empty (&queue)) {
        cur = g_queue_pop_head (&queue);

        if (cur->left)
            g_queue_push_tail (&queue, cur->left);
        if (cur->right)
            g_queue_push_tail (&queue, cur->right);
    }

    return MY_TREE_NODE (cur);
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
     *           8
     *          /
     *         7
     */
    xz_tree_insert (tree, my_tree_node_new (3));
    xz_tree_insert (tree, my_tree_node_new (2));
    xz_tree_insert (tree, my_tree_node_new (1));
    xz_tree_insert (tree, my_tree_node_new (5));
    xz_tree_insert (tree, my_tree_node_new (4));
    xz_tree_insert (tree, my_tree_node_new (6));
    xz_tree_insert (tree, my_tree_node_new (8));
    xz_tree_insert (tree, my_tree_node_new (7));

    g_assert (get_deepest_node (tree->root)->data == 7);

    xz_tree_destroy (&tree);

    return 0;
}