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

    // main code
    int p = q->r;
    q->r++;

    while(p>=0 && q->arr[p] >= val){
        q->arr[p+1] = q->arr[p];
        p--; 
    }
    q->arr[p+1] = val;

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
    q->size = 5;
    q->f = q->r = -1;
    q->arr = (int*)malloc(5*sizeof(int));

    enqueue(q,5);
    enqueue(q,4);
    enqueue(q,2);
    enqueue(q,7);
    enqueue(q,9);

    int n = dequeue(q);
    printf("%d\n",n);

    int n2 = dequeue(q);
    printf("%d\n",n2);

    return 0;
}
