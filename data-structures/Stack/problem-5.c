/*
 * Karumanchi N. - Data Structures and Algorithms Made Easy
 * 
 * Section : Stack
 * Problem : No. 5
 * 
 * Design a stack such that GetMinimum() in O(1)
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

Node *
clone_node (Node *target)
{
    return new_node (target->data);
}

void
print_elements (GTrashStack **stack)
{
    GTrashStack *n = *stack;
    Node *node = NODE (n);

    if (n == NULL)
        return;

    g_print ("%d ", node->data);
    print_elements (&(n->next));
}

void
g_trash_stack_full_free (GTrashStack **stack)
{
    Node *node;

    while ( (node = g_trash_stack_pop (stack)) != NULL)
        g_free (node);
}

void
fake_stack_push (GTrashStack **real,
                 GTrashStack **aux,
                 int data)
{
    Node *new, *peek;

    new = new_node (data);
    g_trash_stack_push (real, new);

    if ( (peek = g_trash_stack_peek (aux)) == NULL )
        g_trash_stack_push (aux, clone_node (new));
    else if (data < peek->data)
        g_trash_stack_push (aux, clone_node (new));
    else  /* data > peek->data */
        g_trash_stack_push (aux, clone_node (peek));
}

Node *
get_minimum (GTrashStack **aux)
{
    return g_trash_stack_peek (aux);
}

int
main(int argc, char *argv[])
{
    GTrashStack *stack = NULL, *aux = NULL;
    Node *node = NULL;
    int i;

    for (i = 5; i < 30; i++)
        fake_stack_push (&stack, &aux, i);
    fake_stack_push (&stack, &aux, 1);

    node = get_minimum (&aux);
    g_assert (node->data == 1);

    g_trash_stack_full_free (&stack);
    g_assert (g_trash_stack_peek (&stack) == NULL);

    g_trash_stack_full_free (&aux);
    g_assert (g_trash_stack_peek (&aux) == NULL);

    return 0;
}
