#include "nyse.h"

void *create_stack(int size)
{
    struct NODE s;
    struct NODE *stack = &s;

    stack = (struct NODE *)node();


    stack->ptr = 0;
    stack->top = size;
    stack->bottom = 0;

    return stack;
}