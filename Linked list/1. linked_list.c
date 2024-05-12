#include <stdio.h>
#include <stdlib.h>

struct node{
    int val;
    struct node* next;
};

int main(){

    struct node* head;
    struct node* snd;
    struct node* trd;

    head = (struct node*)malloc(sizeof(struct node));
    snd = (struct node*)malloc(sizeof(struct node));
    trd = (struct node*)malloc(sizeof(struct node));

    head->val = 7;
    head->next = snd;

    snd->val = 8;
    snd->next = trd;

    trd->val = 9;
    trd->next = NULL;
    
}