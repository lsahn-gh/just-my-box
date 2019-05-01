/*
 * Karumanchi N. - Data Structures and Algorithms Made Easy
 * 
 * Section : Queue
 * Problem : No. 5
 * 
 * Given a queue Q containing n elements, transfer these items on to a stack S
 * (initially empty) so that front element of Q appears at the top of the stack and the order of
 * all other items is preserved. Using enqueue and dequeue operations for the queue, and push
 * and pop operations for the stack, outline an efficient O(n) algorithm to accomplish the
 * above task, using only a constant amount of additional storage.
 */

#include <stdio.h>
#include <stdlib.h>
#include <gmodule.h>

#include "linked-queue.h"

typedef struct _node
{
    LQNode _;
    int data;
} Node;

#define NODE(_ptr) ((Node*)_ptr)

Node *
new_node (int data)
{
    Node *new_node;

    new_node = (Node *)malloc(sizeof(Node));
    LQNODE (new_node)->next = NULL;
    new_node->data = data;

    return new_node;
}

/* Time: O(N) */
void
transfer_to_stack (Queue *queue, GTrashStack **stack)
{
    Node *cur = dequeue (queue);
    if (cur == NULL)
        return;

    transfer_to_stack (queue, stack);
    g_trash_stack_push (stack, cur);
}

static void
print_elem_cb (Node *elem)
{
    printf ("%d ", elem->data);
}

void
queue_print_all_elements (Queue *queue)
{
    g_print ("Queue head -> ");
    queue_foreach (queue, FOREACH_CALL (print_elem_cb));
}

void
g_trash_stack_print_all (GTrashStack **stack)
{
    GTrashStack *sptr = *stack;

    /* From top to bottom */
    g_print ("Stack top  -> ");
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

int
main (void)
{
    int i;
    Queue *queue;
    GTrashStack *stack = NULL;

    queue = queue_new ();

    for (i = 0; i < 10; i++)
        enqueue (queue, new_node (i));
    g_assert (!queue_is_empty (queue));
    g_assert (queue_size (queue) == 10);
    queue_print_all_elements (queue);

    transfer_to_stack (queue, &stack);
    g_assert (queue_is_empty (queue));
    g_assert (queue_size (queue) == 0);
    g_assert (!g_trash_stack_is_empty (&stack));
    g_assert (g_trash_stack_height (&stack) == 10);
    {
        Node *tmp = g_trash_stack_peek (&stack);
        g_assert (tmp->data == 0);
    }
    g_trash_stack_print_all (&stack);

    g_trash_stack_full_free (&stack);
    g_assert (g_trash_stack_is_empty (&stack));

    return 0;
}
