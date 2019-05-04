/*
 * Karumanchi N. - Data Structures and Algorithms Made Easy
 * 
 * Section : Tree
 * Problem : No. 11
 * 
 * Give an algorithm for finding the height (or depth) of the binary tree
 * without recursion.
 * 
 * - O(N) for time-complexity.
 * 
 * - O(N+M) for extra spaces.
 * In this case, N refers to the number of the elements in the tree,
 * M refers to the height+1 for the tree.
 * No matter how many items there are in that level, but items >= 1,
 * NULL is always required only once per level. For the reason, M is height+1.
 */

#include <stdio.h>
#include <stdlib.h>
#include <glib.h>

#include "mytree.h"

int
get_height (XZTreeNode *root)
{
    GQueue queue = G_QUEUE_INIT;
    XZTreeNode *cur;
    int height = -1;

    if (root == NULL)
        return height;

    g_queue_push_tail (&queue, root);
    /* NULL is as a mark of a separator of each level */
    g_queue_push_tail (&queue, NULL);
    while (!g_queue_is_empty (&queue)) {
        cur = g_queue_pop_head (&queue);

        if (cur == NULL) {
            if (!g_queue_is_empty (&queue))
                g_queue_push_tail (&queue, NULL);
            height += 1;
        } else {
            if (cur->left)
                g_queue_push_tail (&queue, cur->left);
            if (cur->right)
                g_queue_push_tail (&queue, cur->right);
        }
    }

    return height;
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

    g_assert (get_height (tree->root) == 4);

    xz_tree_destroy (&tree);

    return 0;
}