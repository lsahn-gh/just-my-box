/*
 * Karumanchi N. - Data Structures and Algorithms Made Easy
 * 
 * Section : Stack
 * Problem : No. 8
 * 
 * Given an array of characters formed with a's and b's.
 * The string is marked with special Character X which represents the middle
 * of the list. Check whether the string is palindrome.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
is_palindrome (const char *str)
{
    int i = 0;
    size_t len = strlen(str);

    for ( ; i < (int)(len/2); i++)
        if (str[i] != str[(len-1)-i])
            return 0;

    return 1;
}

int
main (int argc, char *argv[])
{
    const char *string = "abababbXbbababa";

    if (is_palindrome (string))
        printf ("It's palindrome.\n");
    else
        printf ("It's not palindrome.\n");
    
    return 0;
}
