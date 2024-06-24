#include <stdio.h>
#include <stdlib.h>

typedef struct stack{
    int top;
    int size;
    char * val;
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

void push(stack* s, char c){
    if(isFull(s)){
        printf("stack overfloe!");
        return;
    }else{
        s->top++;
        s->val[s->top] = c;
    }
}

char pop(stack* s){
    if(isEmpty(s)){
        printf("empty stack!");
        return '\0';
    }else{
        char c = s->val[s->top];
        s->top--;
        return c;
    }
}

char operator(char ch){
    if(ch=='+'||ch=='-'||ch=='*'||ch=='/'){
        return 1;
    }
    return 0;
}

int precedence(char c){
    
    if(c=='+' || c=='-'){
        return 1;
    }
    if(c=='*' || c=='/'){
        return 2;
    }
    return 0;
}

void inTOpo(char exp[]){
    stack * s = (stack*)malloc(sizeof(stack));
    s->size = 100;
    s->top = -1;
    s->val = (char*)malloc(100*sizeof(char));

    char* ans = (char*)malloc(100*sizeof(char));
    int j=0;

    for(int i=0; exp[i]!='\0'; i++){
        if(operator(exp[i])){
            while(!isEmpty(s) && precedence(s->val[s->top]) >= precedence(exp[i])){
                ans[j] = pop(s);
                j++;
            }
            push(s,exp[i]);
        }else{
            ans[j] = exp[i];
            j++;
        }
    }

    while(!isEmpty(s)){
        ans[j]=pop(s);
        j++;
    }
    ans[j]='\0';


    //print ans
    for(int i=0; ans[i]!='\0'; i++){
        printf("%c",ans[i]);
    }
}

int main(){
    char ch[] = "a+b*c-d/e";
    inTOpo(ch);
    return 0;
}
