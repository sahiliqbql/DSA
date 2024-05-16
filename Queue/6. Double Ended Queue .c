//      Tow types:

//      1) input restricted DEqueue      ---> input from both side not allow , but output allow
//      2) output restricted DEqueue


#include <stdio.h>
#include <stdlib.h>

typedef struct queue{
    int size;
    int f;
    int r;
    int* arr;
}queue;

void enQ_r(queue* q, int x){

    if(q->r == q->size - 1){
        printf("r is full for %d\n",x);
        return;
    }

    if(q->f == -1 && q->r == -1){
        q->r++;
        q->f++;
        q->arr[q->r] = x;
        return;
    }

    q->r++;
    q->arr[q->r] = x;
}

void enQ_f(queue* q, int x){

    if(q->f == 0){
        printf("f is full for %d\n",x);
        return;
    }

    if(q->f == -1 && q->r == -1){
        q->r++;
        q->f++;
        q->arr[q->r] = x;
        return;
    }

    q->f--;
    q->arr[q->f] = x;
}

void deQ_f(queue* q){

    if(q->r == -1 && q->f == -1){
        printf("empty\n");
        return ;
    }

    if(q->f == q->r){
        printf("%d\n",q->arr[q->f]);
        q->f = q->r = -1;
        return;
    }

    int x = q->arr[q->f];
    printf("%d\n",x);
    q->f++;

}

void deQ_r(queue* q){
    
    if(q->r == -1 && q->f == -1){
        printf("empty\n");
        return;
    }

    if(q->f == q->r){
        printf("%d\n",q->arr[q->r]);
        q->f = q->r = -1;
        return;
    }

    int x = q->arr[q->r];
    printf("%d\n",x);
    q->r--;
}

int main(){

    queue* q = (queue*)malloc(sizeof(queue));
    q->size = 4;
    q->f = q->r = -1;
    q->arr = (int*)malloc(q->size*sizeof(int));

    enQ_r(q,7);
    enQ_f(q,8); // f full

    enQ_r(q,8);
    enQ_r(q,9);
    enQ_r(q,10);

    enQ_r(q,11); // full

    deQ_f(q); // 7

    enQ_f(q,88);
    enQ_f(q,99); // f full

}
