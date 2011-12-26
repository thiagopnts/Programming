#ifndef STACK_H
#define STACK_H
#include <stdlib.h>
#include <string.h>

/**
 * Generic stack implementation.
 */

typedef struct {
    void *elems;
    int elemSize;
    int logLength;
    int allocLength;
} stack;

static void stackGrow(stack *s);

void *stackNew(stack *s, int size);

void *stackDispose(stack *s);

void stackPush(stack *s, void *elemAddr);

void stackPop(stack *s, void *elemAddr);

#endif
