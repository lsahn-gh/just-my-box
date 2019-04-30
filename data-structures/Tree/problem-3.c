/*
 * Karumanchi N. - Data Structures and Algorithms Made Easy
 * 
 * Section : Tree
 * Problem : No. 3
 * 
 * Give an algorithm for searching an element in binary tree.
 * 
 * O(logN) for time-complexity.
 */

#include <stdio.h>
#include <stdlib.h>
#include <glib.h>

#include "mytree.h"

gboolean
find_the_value (XZTreeNode *root, int value)
{
    MyTreeNode *cur = MY_TREE_NODE (root);
    gboolean ret = FALSE;

    while (cur != NULL) {
        if (cur->data > value)
            cur = XZ_TREE_NODE (cur)->left;
        else if (cur->data < value)
            cur = XZ_TREE_NODE (cur)->right;
        else {
            ret = TRUE;
            break;
        }
    }

    return ret;
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

    g_assert (find_the_value (tree->root, 5));
    g_assert (!find_the_value (tree->root, 8));

    xz_tree_destroy (&tree);

    return 0;
}