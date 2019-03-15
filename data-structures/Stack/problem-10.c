/*
 * Karumanchi N. - Data Structures and Algorithms Made Easy
 * 
 * Section : Stack
 * Problem : No. 10
 * 
 * Given an array of characters formed with a's and b's.
 * The string is marked with special Character X which represents the middle
 * of the list. Check whether the string is palindrome with Stack.
 */

#include <stdio.h>
#include <stdlib.h>
#include <gmodule.h>

typedef struct _Node
{
    GTrashStack _;  /* Don't access */
    char data;
} Node;

#define NODE(_ptr) ((Node*)_ptr)

Node *
new_node (char data)
{
    Node *new_node;

    new_node = g_new (Node, 1);
    new_node->data = data;

    return new_node;
}

int
main(int argc, char *argv[])
{
    int is_palindrome = 1;
    int count = 0;
    GTrashStack *stack = NULL;
    Node *popped;

    const gchar *string = "abababbXbbababa";
    const gchar *pstr = string;

    while (*pstr != 'X') {
        g_trash_stack_push (&stack, new_node (*pstr));
        count += 1;
        pstr++;
    }

    pstr++;

    while (*pstr != '\0') {
        if ( (popped = g_trash_stack_pop (&stack)) != NULL) {
            if (*pstr != popped->data)
                break;
            g_free (popped);
        }
        count -= 1;
        pstr++;
    }

    while ( (popped = g_trash_stack_pop (&stack)) != NULL) {
        g_free (popped);
    }

    if (count != 0)
            is_palindrome = 0;

    g_print ("The string %s is %spalindrome.", string, is_palindrome ? "" : "not ");

    return 0;
}

