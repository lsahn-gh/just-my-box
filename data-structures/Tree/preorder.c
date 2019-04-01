#include <stdio.h>
#include <stdlib.h>
#include <glib.h>

#include "mytree.h"

void
pre_order (MyTreeNode *root)
{
    XZTreeNode *tmp;

    if (root == NULL)
        return;

    tmp = XZ_TREE_NODE (root);
    g_print ("%d ", root->data);
    pre_order (MY_TREE_NODE (tmp->left));
    pre_order (MY_TREE_NODE (tmp->right));
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

    /* Output: 3 2 5 4 6 7 */
    pre_order (MY_TREE_NODE (tree->root));
    g_print ("\n");

    xz_tree_destroy (&tree);

    return 0;
}
