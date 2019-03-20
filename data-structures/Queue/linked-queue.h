#pragma once

typedef struct _node Node;

typedef struct _queue
{
    int length;
    Node *front;
    Node *rear;
} Queue;

struct _node
{
    Node *next;
    int data;
};

Node * node_new (int data);
Queue * queue_new (void);
int queue_is_empty (Queue *queue);
int queue_size (Queue *queue);
void enqueue (Queue *queue, Node *new_node);
Node * dequeue (Queue *queue);
int queue_full_free (Queue **qptr);
void queue_print_all (Queue *queue);
