#include <stdio.h>
#include <string.h>

/*
 * Generic function implementation using C.
 * Swap values of the same type.
 */
void swap(void *p1, void *p2, int size)
{
    char buffer[size];
    memcpy(buffer, p1, size);
    memcpy(p1, p2, size);
    memcpy(p2, buffer, size);
}

int cmp(void *x, void *y)
{
    int *p1 = x;
    int *p2 = y;

    return (*p1 - *p2);
}

void *lnsrch(void *key, void *base, int n, int elsize, int (*cmpfn)(void *, void*))
{
    int i;
    for(i = 0; i < n; i++) {
        void *elmaddr = (char *) base + (i*elsize);
        if(cmpfn(key, elmaddr)==0)
            return i;
    }
    return -1;
}

int main()
{
    int x=17, y=37;
    int array[] = {1,2,3,4,5};
    int search = 5;
    float z=45.1, w=33.3;

    printf("%d\n", lnsrch(&search, &array, 5, sizeof(int), cmp));
    swap(&x, &y, sizeof(int));
    printf("x: %d, y: %d\n", x,y);

    swap(&z, &w, sizeof(float));
    printf("z: %f, w: %f\n", z, w);

    return 0;
}
