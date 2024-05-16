#include <stdio.h>
#include <stdlib.h>

typedef struct queue{
    int size;
    int f;
    int r;
    int * arr;
}queue;

int isEmpty(queue* q){
    if(q->f == -1 && q->r == -1){
        return 1;
    }
    return 0;
}

int isFull(queue* q){
    if(q->r == q->size-1){
        return 1;
    }
    return 0;
}

void enqueue(queue* q, int val){
    if(isFull(q)){
        printf("queue overflow! can't enter %d\n",val);
        return;
    }
    if(isEmpty(q)){
        q->f = q->r = 0;
        q->arr[q->r] = val;
        return;
    }

    q->r++;
    q->arr[q->r] = val;
}

int dequeue(queue* q){
    if(isEmpty(q)){
        printf("empty queue!\n");
        return 0;
    }

    if(q->f == q->r){
        int n = q->arr[q->f];
        q->f = q->r = -1;
        return n;
    }
    
    int n = q->arr[q->f];
    q->f++;
    return n;
}

int main(){
    queue* q = (queue*)malloc(sizeof(queue));
    q->size = 3;
    q->f = q->r = -1;
    q->arr = (int*)malloc(3*sizeof(int));

    dequeue(q);

    enqueue(q,7);
    enqueue(q,8);
    enqueue(q,9);
    enqueue(q,10);

    int n = dequeue(q);
    printf("%d\n",n);

    enqueue(q,10); // space is not use efficiently

    return 0;
}
