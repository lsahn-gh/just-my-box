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

typedef struct
{
    LQNode _;
    int data;
} Node;

#define NODE(_ptr) ((Node*)_ptr)

static Node *
node_new (int data)
{
    Node *new_node;

    new_node = (Node *)malloc(sizeof(Node));
    LQNODE (new_node)->next = NULL;
    new_node->data = data;

    return new_node;
}

static LQNode *
internal_reverse (LQNode *cur_node)
{
    LQNode *next_node;

    if (cur_node == NULL)
        return NULL;

    next_node = internal_reverse (cur_node->next);
    if (next_node != NULL)
        next_node->next = cur_node;
    return cur_node;
}

void
queue_reverse (Queue *queue)
{
    LQNode *tmp;

    internal_reverse (queue->front);

    tmp = queue->front;
    queue->front = queue->rear;
    queue->rear = tmp;
    queue->rear->next = NULL;
}

void
queue_print_all (Queue *queue)
{
    LQNode *cur = queue->front;

    while (cur != NULL) {
        printf ("%d ", NODE (cur)->data);
        cur = cur->next;
    }
    printf ("\n");
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
