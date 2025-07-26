#ifndef STACK_H
#define STACK_H

struct STACK
{
    int *data;
    int ptr;
    int size;
    int top;
} stack_t;

void *create_stack(int);
int isEmpty(stack_t);
int isFull(stack_t);
void peek();
void pop();
void push();

#endif