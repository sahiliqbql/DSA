// condition for unbalenced exp:
// 1) while poping stack should not be underflow
// 2) at end of ecpretion , stuck should be empty

#include <stdio.h>
#include <stdlib.h>

typedef struct stact{
    int size;
    int top;
    char * arr;
}stact;

int isFull(stact* s){
    if(s->top == s->size-1){
        return 1;
    }
    return 0;
}

int isEmpty(stact* s){
    if(s->top == -1){
        return 1;
    }
    return 0;
}

void push(stact* s,char c){
    if(isFull(s)==1){
        printf("stack overloded");
    }else{
        s->top++;
        s->arr[s->top] = c;
    };
}

char pop(stact* s){
    if(isEmpty(s)==1){
        printf("empty stack");
        return '\0';
    }else{
        char c = s->arr[s->top];
        s->top--;
        return c;
    }
}

void parenthesisMatch(char equ[]){
    
    stact* s = (stact*)malloc(sizeof(stact));
    s->size = 100;
    s->top = -1;
    s->arr = (char*)malloc(100*sizeof(char));

    for(int i=0; equ[i]!='\0'; i++){

        if(equ[i]=='('){
            push(s,equ[i]);

        }else if(equ[i] == ')'){

            if(isEmpty(s)==1){
                printf("not balenced");
                return;
            }else{
                pop(s);
            }
        }
    }

    if(isEmpty(s)==1){
        printf("balenced exp");
    }else{
        printf("not balenced");
    }
}

int main(){
    
    char equ[] = "(5+(2+(3)))";
    parenthesisMatch(equ);
    
    return 0;
}
