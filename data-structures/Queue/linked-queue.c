#include <stdio.h>
#include <stdlib.h>

#include "linked-queue.h"

Node *
node_new (int data)
{
    Node *new_node;

    new_node = (Node *)malloc(sizeof(Node));
    new_node->next = NULL;
    new_node->data = data;

    return new_node;
}

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

void
enqueue (Queue *queue, Node *new_node)
{
    if (queue->rear == NULL) {
        queue->front = queue->rear = new_node;
    } else {
        queue->rear->next = new_node;
        queue->rear = new_node;
    }
    queue->length += 1;
}

Node *
dequeue (Queue *queue)
{
    Node *ret;

    if (queue_is_empty (queue))
        return NULL;

    ret = queue->front;
    queue->front = ret->next;
    queue->length -= 1;

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
queue_print_all (Queue *queue)
{
    Node *cur = queue->front;

    while (cur != NULL) {
        printf ("%d ", cur->data);
        cur = cur->next;
    }
    printf ("\n");
}
