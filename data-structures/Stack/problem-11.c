/*
 * Karumanchi N. - Data Structures and Algorithms Made Easy
 * 
 * Section : Stack
 * Problem : No. 11
 * 
 * Given a stack, how to reverse the elements of the stack using only stack
 * operations such as push and pop.
 */

#include <stdio.h>
#include <stdlib.h>
#include <gmodule.h>

typedef struct _Node
{
    GTrashStack _;  /* Don't access */
    int data;
} Node;

#define NODE(_ptr) ((Node*)_ptr)

Node *
new_node (int data)
{
    Node *new_node;

    new_node = g_new (Node, 1);
    new_node->data = data;

    return new_node;
}

void
g_trash_stack_print_all (GTrashStack **stack)
{
    GTrashStack *sptr = *stack;

    while (sptr != NULL) {
        g_print ("%d ", NODE (sptr)->data);
        sptr = sptr->next;
    }
    g_print ("\n");
}

int
g_trash_stack_is_empty (GTrashStack **stack)
{
    g_return_val_if_fail (stack != NULL, 0);

    return g_trash_stack_peek (stack) == NULL ? 1 : 0;
}

void
g_trash_stack_full_free (GTrashStack **stack)
{
    Node *node;

    while ( (node = g_trash_stack_pop (stack)) != NULL )
        g_free (node);
}

void
insert_at_bottom (GTrashStack **stack, Node *data)
{
    Node *tmp;

    if (g_trash_stack_is_empty (stack)) {
        g_trash_stack_push (stack, data);
        return;
    }

    tmp = g_trash_stack_pop (stack);
    insert_at_bottom (stack, data);
    g_trash_stack_push (stack, tmp);
}

void
reverse_stack (GTrashStack **stack)
{
    Node *tmp;

    if (g_trash_stack_is_empty (stack))
        return;

    tmp = g_trash_stack_pop (stack);
    reverse_stack (stack);
    insert_at_bottom (stack, tmp);
}

int
main (int argc, char *argv[])
{
    GTrashStack *stack = NULL;
    const int arr[4] = { 4, 3, 5, 2 };
    int i = 0;
    size_t len = sizeof(arr)/sizeof(arr[0]);

    for ( ; i < len; i++)
        g_trash_stack_push (&stack, new_node (arr[i]));
    g_trash_stack_print_all (&stack);

    reverse_stack (&stack);
    g_trash_stack_print_all (&stack);

    g_trash_stack_full_free (&stack);

    g_assert (g_trash_stack_is_empty (&stack));

    return 0;
}
