#pragma once

#include <stdio.h>
#include <gmodule.h>

typedef void* npointer;

/* GStack */
typedef GQueue GStack;
#define G_STACK_INIT                G_QUEUE_INIT
#define g_stack_push(stack, value)  g_queue_push_head (stack, value)
#define g_stack_pop(stack)          g_queue_pop_head (stack)
#define g_stack_peek(stack)         g_queue_peek_head (stack)
#define g_stack_is_empty(stack)     g_queue_is_empty (stack)
