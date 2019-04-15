/*
 * Karumanchi N. - Data Structures and Algorithms Made Easy
 * 
 * Section : Tree
 * Problem : No. 1 and 2
 * 
 * Give an algorithm for finding maximum element in binary tree.
 * 
 * -- Note --
 * Are you sure that the left child is always less than root and
 * the right child is always greater than the root?
 * What if above line is false?
 * The approach of the level order is one of the simplest way to
 * find the maximum value.
 * 
 * This algorithm take O(N) for time and O(N) for space.
 */

#include <stdio.h>
#include <stdlib.h>
#include <glib.h>

#include "mytree.h"

MyTreeNode *
find_maximum (XZTreeNode *root)
{
    GQueue queue = G_QUEUE_INIT;
    void *max = NULL;

    if (root == NULL)
        return NULL;

    g_queue_push_tail (&queue, root);

    while (!g_queue_is_empty (&queue)) {
        XZTreeNode *cur = g_queue_pop_head (&queue);
        if (max == NULL || MY_TREE_NODE (max)->data < MY_TREE_NODE (cur)->data)
            max = cur;
        if (cur->left)
            g_queue_push_tail (&queue, cur->left);
        if (cur->right)
            g_queue_push_tail (&queue, cur->right);
    }

    return max;
}

int
main (void)
{
    XZTree *tree;
    MyTreeNode * max = NULL;

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

    max = find_maximum (tree->root);
    if (max)
        g_print ("Maximum value: %d\n", max->data);

    xz_tree_destroy (&tree);

    return 0;
}