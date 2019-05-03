/*
 * Karumanchi N. - Data Structures and Algorithms Made Easy
 * 
 * Section : Tree
 * Problem : No. 10
 * 
 * Give an algorithm for finding the height (or depth) of the binary tree.
 * 
 * O(N) for time-complexity, no needs extra spaces.
 */

#include <stdio.h>
#include <stdlib.h>
#include <glib.h>

#include "mytree.h"

int
get_height (XZTreeNode *root)
{
    int left, right, bigger;

    if (root == NULL)
        return -1;

    left = get_height (root->left);
    right = get_height (root->right);
    if (left >= right)
        bigger = left;
    else
        bigger = right;

    return bigger + 1;
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
     *            \
     *             8
     */
    xz_tree_insert (tree, my_tree_node_new (3));
    xz_tree_insert (tree, my_tree_node_new (2));
    xz_tree_insert (tree, my_tree_node_new (1));
    xz_tree_insert (tree, my_tree_node_new (5));
    xz_tree_insert (tree, my_tree_node_new (4));
    xz_tree_insert (tree, my_tree_node_new (6));
    xz_tree_insert (tree, my_tree_node_new (7));
    xz_tree_insert (tree, my_tree_node_new (8));

    g_assert (get_height (tree->root) == 4);

    xz_tree_destroy (&tree);

    return 0;
}