#include <stdio.h>
#include <stdlib.h>
#include <glib.h>

#include "mytree.h"

void
in_order (MyTreeNode *root)
{
    XZTreeNode *xz;

    if (root == NULL)
        return;
    
    xz = XZ_TREE_NODE (root);
    in_order (MY_TREE_NODE (xz->left));
    g_print ("%d ", root->data);
    in_order (MY_TREE_NODE (xz->right));
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
    in_order(MY_TREE_NODE (tree->root));
    g_print ("\n");

    xz_tree_destroy (&tree);

    return 0;
}
