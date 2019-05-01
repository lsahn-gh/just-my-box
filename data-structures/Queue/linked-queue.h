#pragma once

typedef void * npointer;
typedef void (*ForeachCall) (npointer);
typedef void (*RecursionCall) (npointer);

typedef struct _lq_node
{
    npointer next;
} LQNode;

typedef struct _queue
{
    int length;
    LQNode *front;
    LQNode *rear;
} Queue;

#define LQNODE(_ptr) ((LQNode*)_ptr)
#define FOREACH_CALL(_ptr) ((ForeachCall)_ptr)
#define RECURSION_CALL(_ptr) ((RecursionCall)_ptr)

Queue * queue_new (void);
int queue_is_empty (Queue *queue);
int queue_size (Queue *queue);
npointer queue_get_front (Queue *queue);
npointer queue_get_rear (Queue *queue);
void enqueue (Queue *queue, npointer new_node);
npointer dequeue (Queue *queue);
int queue_full_free (Queue **qptr);
void queue_foreach (Queue *queue, ForeachCall fptr);
void queue_recursion (Queue *queue, RecursionCall fptr);
