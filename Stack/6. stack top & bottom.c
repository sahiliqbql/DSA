#include <stdio.h>
#include <stdlib.h>

typedef struct stack{
    int size;
    int top;
    int * arr;
}stack;

int stackTop(stack* s){
    return s->arr[s->top];
}

int stackBottom(stack* s){
    return s->arr[0];
}

void push(stack* s, int val){
    
    if(s->top == s->size-1){
        printf("stack overflow can't push %d\n",val);
    }else{
        s->top++;
        s->arr[s->top] = val;
    }
}
int main(){
    stack* s = (stack*)malloc(sizeof(stack));
    s->size = 3;
    s->top = -1;
    s->arr = (int*)malloc(s->size*sizeof(int));

    push(s,7);
    push(s,8);
    push(s,9);

    printf("top = %d\n",stackTop(s));
    printf("bottom = %d",stackBottom(s));

    return 0;
}
