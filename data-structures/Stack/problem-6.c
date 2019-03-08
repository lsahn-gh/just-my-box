/*
 * Karumanchi N. - Data Structures and Algorithms Made Easy
 * 
 * Section : Stack
 * Problem : No. 6
 * 
 * Design a stack such that GetMinimum() in O(1),
 * but improve space-complexity.
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

/* --- Adv-Stack part --- */
typedef struct _AdvStack
{
    GTrashStack *main;
    GTrashStack *min;
} AdvStack;

#define ADDR(_var) (&(_var))

void
adv_stack_push (AdvStack *adv,
                int data)
{
    Node *new, *peek;

    new = new_node (data);
    g_trash_stack_push (ADDR (adv->main), new);

    if ( (peek = g_trash_stack_peek (ADDR (adv->min))) == NULL )
        g_trash_stack_push (ADDR (adv->min), clone_node (new));
    else if (data <= peek->data)
        g_trash_stack_push (ADDR (adv->min), clone_node (new));
}

Node *
adv_stack_pop (AdvStack *adv)
{
    Node *ret_node;

    ret_node = g_trash_stack_pop (ADDR (adv->main));

    if (ret_node) {
        Node *min = g_trash_stack_peek (ADDR (adv->min));

        if (ret_node->data == min->data)
            g_free (g_trash_stack_pop (ADDR (adv->min)));
    }

    return ret_node;
}

void
adv_stack_full_free (AdvStack *adv)
{
    g_trash_stack_full_free (ADDR (adv->main));
    g_assert (g_trash_stack_peek (ADDR (adv->main)) == NULL);

    g_trash_stack_full_free (ADDR (adv->min));
    g_assert (g_trash_stack_peek (ADDR (adv->min)) == NULL);
}

Node *
get_minimum (AdvStack *adv)
{
    return g_trash_stack_peek (ADDR (adv->min));
}

int
main(int argc, char *argv[])
{
    AdvStack stack, *adv = &stack;
    Node *node = NULL;
    int i;

    adv->main = NULL;
    adv->min = NULL;

    for (i = 5; i < 30; i++)
        adv_stack_push (adv, i);
    adv_stack_push (adv, 1);

    node = get_minimum (adv);
    g_assert (node->data == 1);

    for (i = 0; i < 10; i++)
        g_free (adv_stack_pop (adv));

    node = get_minimum (adv);
    g_assert (node->data == 5);

    adv_stack_full_free (adv);

    return 0;
}
