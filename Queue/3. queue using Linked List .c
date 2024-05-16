#include <stdio.h>
#include <stdlib.h>

struct queue* r = NULL;  //global variable
struct queue* f = NULL;  //global variable

typedef struct queue{
    int val;
    struct queue* next;
}queue;

void enQueue(int x){
    queue* newQ =  (queue*)malloc(sizeof(queue));
    
    if(f == NULL && r == NULL){
        newQ->val = x;
        newQ->next = NULL;
        f = r = newQ;

    }
    else{
        newQ->val = x;
        newQ->next = NULL;
        r->next = newQ;
        r = newQ;
    }
}

void display(){
    
    if(f == NULL && r == NULL){
        printf("empty!\n");
        return;
    }
    queue* t = f;

    while(t!=NULL){
        printf("%d ",t->val);
        t = t->next;
    }
    printf("\n");
}

void deQueue(){
    if(f == NULL && r == NULL){
        printf("empty!\n");
        return ;
    }
    if(f==r){
        queue* temp = f;
        f = r = NULL;
        printf("%d\n",temp->val);
        free(temp);
        return;
    }
    queue* temp = f;
    f = f->next;
    printf("%d\n",temp->val);
    free(temp);
}

int main(){
    
    display();

    enQueue(7);
    enQueue(8);
    enQueue(9);

    display();

    deQueue();

    display();

    enQueue(11);

    display();

    return 0;
}
