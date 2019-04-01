#include <stdlib.h>

#include "xz-queue.h"

XZQueue *
queue_new (void)
{
    XZQueue *new_queue;

    new_queue = (XZQueue *)malloc(sizeof(XZQueue));
    new_queue->front = NULL;
    new_queue->rear = NULL;
    new_queue->length = 0;

    return new_queue;
}

int
queue_is_empty (XZQueue *queue)
{
    return queue->front == NULL ? 1 : 0;
}

int
queue_size (XZQueue *queue)
{
    return queue->length;
}

npointer
queue_get_front (XZQueue *queue)
{
    if (queue_is_empty (queue))
        return NULL;

    return queue->front;
}

npointer
queue_get_rear (XZQueue *queue)
{
    if (queue_is_empty (queue))
        return NULL;

    return queue->rear;
}

void
enqueue (XZQueue *queue, npointer new_node)
{
    XZ_QUEUE_NODE (new_node)->next = NULL;

    if (queue->rear == NULL) {
        queue->front = queue->rear = new_node;
    } else {
        queue->rear->next = new_node;
        queue->rear = new_node;
    }
    queue->length += 1;
}

npointer
dequeue (XZQueue *queue)
{
    XZQueueNode *ret;

    if (queue_is_empty (queue))
        return NULL;

    ret = queue->front;
    queue->front = ret->next;
    queue->length -= 1;

    ret->next = NULL;
    return ret;
}

int
queue_full_free (XZQueue **qptr)
{
    XZQueue *queue = *qptr;

    while (!queue_is_empty (queue)) {
        free (dequeue (queue));
    }

    free (queue);
    *qptr = NULL;

    return 1;
}

void
queue_foreach (XZQueue *queue, ForeachCall fptr)
{
    XZQueueNode *cur = queue->front;

    while (cur != NULL) {
        fptr (cur);
        cur = cur->next;
    }
    printf ("\n");
}

static npointer
internal_recursion (XZQueueNode *cur, ForeachCall fptr)
{
    if (cur == NULL)
        return NULL;
    
    internal_recursion (cur->next, fptr);
    return fptr (cur);
}

void
queue_recursion (XZQueue *queue, ForeachCall fptr)
{
    internal_recursion (queue->front, fptr);
}
