/*
 * Karumanchi N. - Data Structures and Algorithms Made Easy
 * 
 * Section : Queue
 * Problem : No. 3
 * 
 * Show how you can efficiently implement one stack using two queues.
 * Analyze therunning time of the stack operations.
 * 
 * 
 * Note that the following annotations are used for time-complexity
 * 
 * N is for the Stack->enq
 * M is for the Stack->deq
 * S is just Stack itself, which means N+M
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "linked-queue.h"

typedef struct
{
    LQNode _; /* private */
    int data;
} Node;

#define NODE(_ptr) ((Node*)_ptr)

typedef struct
{
    int size;
    Queue *enq;
    Queue *deq;
} Stack;

Node *
node_new (int data)
{
    Node *new_node;

    new_node = (Node *)malloc(sizeof(Node));
    LQNODE (new_node)->next = NULL;
    new_node->data = data;

    return new_node;
}

Stack *
stack_new (void)
{
    Stack *new_stack;

    new_stack = (Stack*)malloc(sizeof(Stack));
    new_stack->enq = queue_new ();
    new_stack->deq = queue_new ();
    new_stack->size = 0;

    return new_stack;
}

/* Time: O(1) */
int
stack_is_empty (Stack *stack)
{
    return stack->size == 0 ? 1 : 0;
}

/* Time: O(1) */
int
stack_size (Stack *stack)
{
    return stack->size;
}


static void
internal_push_to_dequeue (LQNode *cur, Stack *stack)
{
    if (cur == NULL)
        return;

    internal_push_to_dequeue (dequeue (stack->enq), stack);
    enqueue (stack->deq, cur);
}

/* Time: O(1) */
void
stack_push (Stack *stack, Node *new_node)
{
    enqueue (stack->enq, new_node);
    stack->size += 1;
}

/* Time: O(N) */
Node *
stack_pop (Stack *stack)
{
    Node *ret;

    if (stack_is_empty (stack))
        return NULL;

    if (queue_is_empty (stack->deq))
        internal_push_to_dequeue (dequeue (stack->enq), stack);

    ret = NODE (dequeue (stack->deq));
    stack->size -= 1;

    return ret;
}

/* Time: O(N) */
Node *
stack_peek (Stack *stack)
{
    if (stack_is_empty (stack))
        return NULL;

    if (queue_is_empty (stack->deq))
        internal_push_to_dequeue (dequeue (stack->enq), stack);
    
    return queue_get_front (stack->deq);
}

static void
print_elem (Node *elem)
{
    printf ("%d ", elem->data);
}

/* Time: O(S) */
void
stack_print_all (Stack *stack)
{

    printf ("peek -> ");
    queue_recursion (stack->enq, RECURSION_CALL (print_elem));
    queue_foreach (stack->deq, FOREACH_CALL (print_elem));
}

/* Time: O(S) */
int
stack_full_free (Stack **stkptr)
{
    Stack *stack = *stkptr;

    queue_full_free (&stack->enq);
    queue_full_free (&stack->deq);

    free (stack);
    *stkptr = NULL;

    return 1;
}

int
main (void)
{
    int i;
    Node *node;
    Stack *stack;

    stack = stack_new ();

    for (i = 0; i < 10; i++)
        stack_push (stack, node_new (i));
    assert (!stack_is_empty (stack));
    assert (stack_size (stack) == 10);
    stack_print_all (stack);

    node = stack_peek (stack);
    assert (node->data == 9);

    for (i = 0; i < 2; i++)
        free (stack_pop (stack));
    assert (!stack_is_empty (stack));
    assert (stack_size (stack) == 8);
    stack_print_all (stack);

    stack_full_free (&stack);
    assert (stack == NULL);

    return 0;
}
