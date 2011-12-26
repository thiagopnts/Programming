#include "stack.h"

static void stackGrow(stack *s)
{
    s->allocLength *= 2;
    s->elems = realloc(s->elems, s->allocLength*s->elemSize);
}

void *stackNew(stack *s, int size)
{
    assert(s->elemSize > 0);
    s->elemSize = size;
    s->logLength = 0;
    s->elems = malloc(4*size);
    assert(s->elems != NULL);
}

void *stackDispose(stack *s)
{
    free(s->elems);
}

void stackPush(stack *s, void *elemAddr)
{
    if(s->logLength == s->allocLength) {
        stackGrow(s);
    }
    void *target = (char *) s->elems + s->logLength * s->elemSize;
    memcpy(target, elemAddr, s->elemSize);
    s->logLength++;
}

void stackPop(stack *s, void *elemAddr)
{
    void *source = (char *) s->elems + (s->logLength-1) * s->elemSize;
    memcpy(elemAddr, source, s->elemSize);
    s->logLength--;
}

