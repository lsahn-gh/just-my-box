/*
 * Karumanchi N. - Data Structures and Algorithms Made Easy
 * 
 * Section : Queue
 * Problem : No. 2
 * 
 * How can you implement a queue using two stacks?
 * 
 * N is for enqueue stack.
 * M is for dequeue stack.
 * 
 * Time-complexity
 *  - enqueue : O(1)
 *  - dequeue : O(1+N) -> O(N),
 *              1 is for dequeue-ing operation,
 *              N for pushing enq-stack to deq-stack if deq-stack has no elements at the operating moment.
 * 
 * Space-complexity is O(N+M)
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <gmodule.h>

typedef struct _Node
{
    GTrashStack _; /* Don't access */
    int data;
} Node;

typedef struct _Queue
{
    GTrashStack *deq;
    GTrashStack *enq;
} Queue;

#define NODE(_ptr)  ((Node *)_ptr)
#define G_TRASH_STACK(_ptr) ((GTrashStack *)_ptr)

Node *
new_node (int data)
{
    Node *new_node;

    new_node = g_new (Node, 1);
    new_node->data = data;
    G_TRASH_STACK (new_node)->next = NULL;

    return new_node;
}

int
g_trash_stack_is_empty (GTrashStack **stack)
{
    g_return_val_if_fail (stack != NULL, 0);

    return g_trash_stack_peek (stack) == NULL ? 1 : 0;
}

/* O(N+M) */
size_t
queue_size (Queue *queue)
{
    size_t enq, deq;

    enq = g_trash_stack_height (&queue->enq);
    deq = g_trash_stack_height (&queue->deq);

    return enq+deq;
}

void
enqueue (Queue *queue, Node *new_node)
{
    g_trash_stack_push (&queue->enq, new_node);
}

Node *
dequeue (Queue *queue)
{
    if (g_trash_stack_is_empty (&queue->deq)) {
        while (!g_trash_stack_is_empty (&queue->enq))
            g_trash_stack_push (&queue->deq, g_trash_stack_pop (&queue->enq));
    }

    return g_trash_stack_pop (&queue->deq);
}

static void
internal_enqueue_print (GTrashStack *node)
{
    if (node == NULL)
        return;

    internal_enqueue_print (node->next);
    printf ("%d ", NODE (node)->data);
}

/* O(N+M) */
void
queue_print_all (Queue *queue)
{
    GTrashStack *deq = queue->deq;

    /* print deq-stack elements */
    while (deq != NULL) {
        printf ("%d ", NODE (deq)->data);
        deq = deq->next;
    }

    /* print enq-stack elements */
    internal_enqueue_print (queue->enq);

    printf ("\n");
}

/* O(N+M) */
void
queue_full_free (Queue *queue)
{
    while (!g_trash_stack_is_empty (&queue->enq))
        g_free (g_trash_stack_pop (&queue->enq));

    while (!g_trash_stack_is_empty (&queue->deq))
        g_free (g_trash_stack_pop (&queue->deq));
}

int
main (void)
{
    int i;
    Queue tmp, *queue = &tmp;

    queue->enq = NULL;
    queue->deq = NULL;

    for (i = 0; i < 10; i++)
        enqueue (queue, new_node (i));
    assert (queue_size (queue) == 10);
    queue_print_all (queue);

    for (i = 0; i < 5; i++) {
        Node *tmp = dequeue (queue);
        assert (tmp->data == i);
        g_free (tmp);
    }
    assert (queue_size (queue) == 5);

    for (i = 0; i < 10; i++)
        enqueue (queue, new_node (i+10));
    assert (queue_size (queue) == 15);
    queue_print_all (queue);

    queue_full_free (queue);

    return 0;
}
