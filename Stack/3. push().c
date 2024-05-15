#include <stdio.h>
#include <stdlib.h>

typedef struct stack{
    int size;
    int top;
    int * arr;
}stack;

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
    push(s,10);
    push(s,11);

    return 0;
}
