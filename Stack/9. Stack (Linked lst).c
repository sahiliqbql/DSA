#include <stdio.h>
#include <stdlib.h>

typedef struct stack{
    int val;
    struct stack* next;
}stack;


stack* push(stack* *top, int n){
    stack* p = (stack*)malloc(sizeof(stack));
    if(p==NULL){
        printf("stack full!"); // only p is null when computer memory was full theoretically not possible
        return 0;
    }
    
    p->val = n;
    p->next = *top;
    *top = p;

    return *top;
}

//we should use *pop
void pop(stack* *top){

    stack* p = *top;
    if(p==NULL){
        printf("empty!");
        return ;
    }
    printf("%d\n",p->val);
    *top = (*top)->next;
    free(p);
}

int main(){
    stack* top = NULL;

    push(&top,7);
    push(&top,8);
    push(&top,9);

    pop(&top);
    pop(&top);
    pop(&top);
    pop(&top);

    return 0;
}
