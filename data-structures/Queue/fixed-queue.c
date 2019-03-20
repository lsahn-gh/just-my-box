#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct queue
{
    int length;
    int allocated_size;
    int head;
    int rear;
    int *array;
} Queue;

int
queue_front (Queue *queue)
{
    return queue->array[queue->head];
}

int
queue_size (Queue *queue)
{
    return queue->length;
}

int
queue_is_empty (Queue *queue)
{
    return queue->length == 0 ? 1 : 0;
}

int
queue_is_full (Queue *queue)
{
    return queue->length == queue->allocated_size ? 1 : 0;
}

int
enqueue (Queue *queue, int new_data)
{
    if (queue_is_full (queue))
        return 0;

    queue->array[queue->rear] = new_data;
    queue->rear = (queue->rear+1) % queue->allocated_size;
    queue->length += 1;

    return 1;
}

int
dequeue (Queue *queue)
{
    int ret_data;

    if (queue_is_empty (queue))
        return 0;

    ret_data = queue->array[queue->head];
    queue->head = (queue->head+1) % queue->allocated_size;
    queue->length -= 1;

    return ret_data;
}

Queue *
queue_new (size_t require)
{
    Queue *new_queue;

    if (require < 1)
        require = 16;

    new_queue = (Queue *)malloc(sizeof(Queue));
    new_queue->array = (int *)malloc(sizeof(int) * require);
    new_queue->allocated_size = require;
    new_queue->length = 0;
    new_queue->head = 0;
    new_queue->rear = 0;

    return new_queue;
}

void
queue_free (Queue *queue)
{
    if (queue) {
        if (queue->array)
            free (queue->array);
        free (queue);
    }
}

int
main (void)
{
    int i;
    Queue *queue;

    queue = queue_new (10);
    assert (queue_is_empty (queue));
    assert (queue_size (queue) == 0);

    for (i = 1; i <= 10; i++)
        enqueue (queue, i);
    assert (queue_is_full (queue));
    assert (queue_size (queue) == 10);
    assert (queue_front (queue) == 1);

    for (i = 0; i < 3; i++)
        dequeue (queue);
    assert (!queue_is_full (queue));
    assert (!queue_is_empty (queue));
    assert (queue_size (queue) == 7);
    assert (queue_front (queue) == 4);

    for (i = 0; i < 3; i++)
        enqueue (queue, i);
    assert (queue_is_full (queue));
    assert (queue_size (queue) == 10);
    assert (queue_front (queue) == 4);

    queue_free (queue);

    return 0;
}
