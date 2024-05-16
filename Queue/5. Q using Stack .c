/*

push(x)         -> we push element on the bottm
    S1 -> S2   // move all element of S1 into S2
    x -> S1
    S2 -> S1 

pop(): S1.pop()  // same as stack    // we get LILO for S1

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct queue{
    int size;
    int top;
    int * arr;
}queue;

void push(queue* q, int x){
    if(q->top == q->size-1){
        printf("full can't insert %d",x);
        return;
    }
    q->top++;
    q->arr[q->top] = x;
}

int pop(queue* q){
    if(q->top == -1){
        printf("empty!\n");
        return 0;
    }
    int x = q->arr[q->top];
    q->top--;
    return x;
}

void enQueue(queue* q, int x){

    if(q->top == q->size -1){
        printf("full! can't insert %d\n",x);
        return;
    }

    queue* q2 = (queue*)malloc(sizeof(queue));
    q2->size = q->size;
    q2->top = -1;
    q2->arr = (int*)malloc(sizeof(int));

    if(q->top == -1){
        q->top++;
        q->arr[q->top] = x;
    }
    else{
        
        while(q->top!=-1){
            int t = pop(q);
            push(q2,t);
        }
        push(q,x);
        while(q2->top!=-1){
            int t = pop(q2);
            push(q,t);
        }
    }
}

void deQueue(queue* q){   // same as pop
    if(q->top == -1){
        printf("empty!\n");
        return ;
    }
    int x = q->arr[q->top];
    q->top--;
    printf("%d\n",x);
}

int main(){
    queue * q = (queue*)malloc(sizeof(queue));
    q->size = 3;
    q->top = -1;
    q->arr = (int*)malloc(sizeof(int));

    enQueue(q,4);
    enQueue(q,5);
    enQueue(q,6);
    enQueue(q,7); // full

    deQueue(q); // 4
    deQueue(q);
    deQueue(q);
    deQueue(q); // empty

    enQueue(q,7);
    deQueue(q);  // 7
}
