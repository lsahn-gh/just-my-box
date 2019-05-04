#pragma once

#include "common.h"

typedef npointer (*ForeachCall) (npointer);
typedef npointer (*RecursionCall) (npointer);
#define FOREACH_CALL(_ptr) ((ForeachCall)_ptr)
#define RECURSION_CALL(_ptr) ((RecursionCall)_ptr)

/* Compatible with GTrashStack */
typedef struct
{
    npointer next;
} XZQueueNode;

typedef struct _queue
{
    int length;
    XZQueueNode *front;
    XZQueueNode *rear;
} XZQueue;

#define XZ_QUEUE_NODE(_ptr) ((XZQueueNode*)_ptr)

XZQueue * queue_new (void);
int queue_is_empty (XZQueue *queue);
int queue_size (XZQueue *queue);
npointer queue_get_front (XZQueue *queue);
npointer queue_get_rear (XZQueue *queue);
void enqueue (XZQueue *queue, npointer new_node);
npointer dequeue (XZQueue *queue);
int queue_full_free (XZQueue **qptr);
void queue_foreach (XZQueue *queue, ForeachCall fptr);
void queue_recursion (XZQueue *queue, RecursionCall fptr);
