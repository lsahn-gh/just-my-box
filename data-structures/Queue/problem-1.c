/*
 * Karumanchi N. - Data Structures and Algorithms Made Easy
 * 
 * Section : Queue
 * Problem : No. 1
 * 
 * Given an algorithm for reversing a Queue.
 */

#include <stdio.h>
#include <stdlib.h>

#include "linked-queue.h"

static Node *
internal_reverse (Node *node)
{
    Node *tmp;

    if (node == NULL)
        return NULL;

    tmp = internal_reverse (node->next);
    if (tmp != NULL)
        tmp->next = node;
    return node;
}

void
queue_reverse (Queue *queue)
{
    Node *tmp;

    internal_reverse (queue->front);

    tmp = queue->front;
    queue->front = queue->rear;
    queue->rear = tmp;
    queue->rear->next = NULL;
}

int
main (void)
{
    int i;
    Queue *queue;

    queue = queue_new ();

    for (i = 0; i < 10; i++)
        enqueue (queue, node_new (i));
    queue_print_all (queue);

    queue_reverse (queue);
    queue_print_all (queue);

    queue_full_free (&queue);

    return 0;
}
