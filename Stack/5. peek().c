#include <stdio.h>
#include <stdlib.h>

typedef struct stack{
    int size;
    int top;
    int * arr;
}stack;

void push(stack* s, int val){
    
    if(s->top == s->size-1){
        printf("stack overflow");
    }else{
        s->top++;
        s->arr[s->top] = val;
    }
}

void peek(stack* s, int p){ // here p is the position from last in
    int idx = s->top - p + 1;

    if(idx<0){
        printf("invalid index\n");
    }else{
        printf("val = %d\n",s->arr[idx]);
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

    peek(s,1);
    peek(s,2);
    peek(s,3);
    peek(s,4);

    return 0;
}
