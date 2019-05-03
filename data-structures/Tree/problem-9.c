/*
 * Karumanchi N. - Data Structures and Algorithms Made Easy
 * 
 * Section : Tree
 * Problem : No. 9
 * 
 * Give an algorithm for deleting the tree.
 * 
 * I use post-order algorithm for deleting all the nodes.
 * 
 * But if you are interested in the way of using level order,
 * please see libs/xz-tree.c:xz_tree_destroy()
 * 
 * O(N) for time-complexity, no needs extra spaces.
 */

#include <stdio.h>
#include <stdlib.h>
#include <glib.h>

#include "mytree.h"

/* A tracing variable to count how many times g_free called.
 * It must be up to the number of elements of the tree.
 */
int count = 0;

void
tree_destroy (XZTreeNode *root)
{
    if (root == NULL)
        return;

    tree_destroy (root->left);
    tree_destroy (root->right);
    g_free (root);
    count += 1;
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

    tree_destroy (tree->root);
    g_assert (count == 7);

#if 0
    xz_tree_destroy (&tree);
#endif

    return 0;
}