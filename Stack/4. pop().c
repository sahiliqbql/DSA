#include <stdio.h>
#include <stdlib.h>

typedef struct stack{
    int size;
    int top;
    int * arr;
}stack;

void pop(stack* s){
    if(s->top == -1){
        printf("stack is empty!\n");
    }else{
        printf("val = %d\n",s->arr[s->top]);
        s->top--;
    }
}

int main(){
    stack* s = (stack*)malloc(sizeof(stack));
    s->size = 3;
    s->top = -1;
    s->arr = (int*)malloc(s->size*sizeof(int));

    s->arr[0] = 7;
    s->top++;
    s->arr[1] = 8;
    s->top++;
    s->arr[2] = 9;
    s->top++;

    pop(s);
    pop(s);
    pop(s);
    pop(s);

    return 0;
}
