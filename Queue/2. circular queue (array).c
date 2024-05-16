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
    if((q->r+1)%3 == q->f){       
        return 1;
    }
    return 0;
}

void enqueue(queue* q, int val){

    if(q->f == -1 && q->r == -1){
        q->f = q->r = 0;
        q->arr[q->r] = val;
    }
    else if(isFull(q)){
        printf("queue overflow! can't insert %d\n",val);
    }
    else{
        q->r = (q->r+1)%q->size;
        q->arr[q->r] = val;
    }
}

void dequeue(queue* q){
    if(isEmpty(q)){
        printf("empty!\n");
    }
    else if(q->f == q->r){
        printf("%d",q->arr[q->f]);
        q->f = q->r = -1;
    }
    else{
        printf("%d\n",q->arr[q->f]);
        q->f = (q->f+1)%q->size;
    }
}

int main(){
    queue* q = (queue*)malloc(sizeof(queue));
    q->size = 3;
    q->f = q->r = -1;               
    q->arr = (int*)malloc(3*sizeof(int));

    dequeue(q);

    enqueue(q,7);  
    enqueue(q,8);
    enqueue(q,9);  // 7 8 9
    enqueue(q,10);   

    dequeue(q);  // 8 9

    enqueue(q,10); // now space can be use efficiently  // 8 9 10
    enqueue(q,11);

    dequeue(q); // 9 10

    return 0;
}
