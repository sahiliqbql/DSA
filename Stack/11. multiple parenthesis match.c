#include <stdio.h>
#include <stdlib.h>

typedef struct stack{
    int top;
    int size;
    char * ch;
}stack;

int isFull(stack* s){
    if(s->top == s->size-1){
        return 1;
    }
    return 0;
}

int isEmpty(stack* s){
    if(s->top == -1){
        return 1;
    }
    return 0;
}

void push(stack* s,char c){
    if(isFull(s)){
        printf("stack overflow");
    }else{
        s->top++;
        s->ch[s->top] = c;
    }
}

char pop(stack* s){
    if(isEmpty(s)){
        printf("empty stack!");
        return '\0';
    }else{
        char c = s->ch[s->top];
        s->top--;
        return c;
    }
}

char operator(char ch){
    if(ch=='('||ch=='{'||ch=='['){
        return 1;
    }
    return 0;
}

char operator2(char ch){
    if(ch==')'||ch=='}'||ch==']'){
        return 1;
    }
    return 0;
}

char checkEqual(char ch){
    if(ch == ')'){
        return '(';
    }
    if(ch == '}'){
        return '{';
    }
    if(ch == ']'){
        return '[';
    }
    return '\0';
}

void mParMatch(char exp[]){

    stack* s = (stack*)malloc(sizeof(stack));
    s->size = 100;
    s->top = -1;
    s->ch = (char*)malloc(100*sizeof(char));

    for(int i=0; exp[i]!='\0'; i++){

        if(operator(exp[i])){
            push(s,exp[i]);

        }else if(operator2(exp[i])){

            char t = pop(s);

            if(t != checkEqual(exp[i])){
                printf("unbalenced exp");
                return ;
            }
        }
    }

    if(isEmpty(s)){
        printf("balenced exp");
    }else{
        printf("unbalenced exp");
    }
}

int main(){
    char exp[] = "2*[({5{(4+{5})-7})]";

    mParMatch(exp);

    return 0;
}
