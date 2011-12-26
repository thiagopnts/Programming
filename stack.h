#include <stdlib.h>

typedef struct {
    void *elems;
    int elemSize;
    int logLength;
    int allocLength;
} stack;

void *stackNew(stack *s, int elemSize)
{
    assert(s->elemSize > 0);
    s->elemSize = elemSize;
    s->logLength = 0;
    s->elems = malloc(4*elemSize);
    assert(s->elems != NULL);
}

void *stackDispose(stack *s)
{
    free(s->elems);
}
void stackPush(stack *s, void *elemAddr)
{
    if(s->logicalLen == s->allocLength) {
        stackGrown(s);
    }
    void *target = (char *) s->elems + s->logLength * s->elemSize;
    memcpy(target, elemAddr, s->elemSize);
    s->logLength++;
}

int stackPop(stack *s, void *elemAddr)
{
    assert(s->logicalLen > 0);
    s->logicalLen--;
    return s->elems[s->logicalLen-1];
}
