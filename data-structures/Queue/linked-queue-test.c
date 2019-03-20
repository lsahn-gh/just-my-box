#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "linked-queue.h"

int
main (void)
{
    int i;
    Queue *queue;

    queue = queue_new ();

    for (i = 0; i < 10; i++)
        enqueue (queue, node_new (i));
    queue_print_all (queue);
    assert (!queue_is_empty (queue));
    assert (queue_size (queue) == 10);

    free (dequeue (queue));
    queue_print_all (queue);
    assert (!queue_is_empty (queue));
    assert (queue_size (queue) == 9);

    queue_full_free (&queue);
    assert (queue == NULL);

    return 0;
}
