#include <stdio.h>
#include <stdlib.h>

#include "linked-queue.h"


Queue *
queue_new (void)
{
    Queue *new_queue;

    new_queue = (Queue *)malloc(sizeof(Queue));
    new_queue->front = NULL;
    new_queue->rear = NULL;
    new_queue->length = 0;

    return new_queue;
}

int
queue_is_empty (Queue *queue)
{
    return queue->front == NULL ? 1 : 0;
}

int
queue_size (Queue *queue)
{
    return queue->length;
}

npointer
queue_get_front (Queue *queue)
{
    if (queue_is_empty (queue))
        return NULL;

    return queue->front;
}

npointer
queue_get_rear (Queue *queue)
{
    if (queue_is_empty (queue))
        return NULL;

    return queue->rear;
}

void
enqueue (Queue *queue, npointer new_node)
{
    LQNODE (new_node)->next = NULL;

    if (queue->rear == NULL) {
        queue->front = queue->rear = new_node;
    } else {
        queue->rear->next = new_node;
        queue->rear = new_node;
    }
    queue->length += 1;
}

npointer
dequeue (Queue *queue)
{
    LQNode *ret;

    if (queue_is_empty (queue))
        return NULL;

    ret = queue->front;
    queue->front = ret->next;
    queue->length -= 1;

    ret->next = NULL;
    return ret;
}

int
queue_full_free (Queue **qptr)
{
    Queue *queue = *qptr;

    while (!queue_is_empty (queue)) {
        free (dequeue (queue));
    }

    free (queue);
    *qptr = NULL;

    return 1;
}

void
queue_foreach (Queue *queue, ForeachCall fptr)
{
    LQNode *cur = queue->front;

    while (cur != NULL) {
        fptr (cur);
        cur = cur->next;
    }
    printf ("\n");
}

static npointer
internal_recursion (LQNode *cur, ForeachCall fptr)
{
    if (cur == NULL)
        return NULL;
    
    internal_recursion (cur->next, fptr);
    fptr (cur);
}

void
queue_recursion (Queue *queue, ForeachCall fptr)
{
    internal_recursion (queue->front, fptr);
}
