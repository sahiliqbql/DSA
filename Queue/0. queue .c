// FIFO OR LILO        // f = front          // r = rear

#include <stdio.h>
#include <stdlib.h>

typedef struct queue{
    int size;
    int f;
    int r;
    int * arr;
}queue;

int main(){
    queue* q;
    q->size = 10;
    q->f = q->r = -1;
    q->arr = (int*)malloc(10*sizeof(int));

    return 0;
}
