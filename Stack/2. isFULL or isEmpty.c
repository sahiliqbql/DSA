#include <stdio.h>
#include <stdlib.h>

typedef struct stack{
    int size;
    int top;
    int* arr;
}stack;

int isEmpty(stack* s){

    if(s->top == -1){
        return 1;
    }
    return 0;
}

int isFull(stack* s){

    if(s->top == s->size-1){
        return 1;
    }
    return 0;
}

int main(){
    stack * s;
    s->size = 3;
    s->top = -1;
    s->arr = (int*)malloc(s->size*sizeof(int));

    if(isEmpty(s))
    printf("stack is empty\n");
    else
    printf("stack is not empty\n");
    
    s->arr[0] = 7;
    s->top++;

    s->arr[1] = 8;
    s->top++;

    s->arr[2] = 9;
    s->top++;

    if(isEmpty(s))
    printf("stack is empty\n");
    else
    printf("stack is not empty\n");

    if(isFull(s))
    printf("stack is full\n");
    else
    printf("stack is not full\n");

    return 0;
}
