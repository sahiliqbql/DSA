#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    struct node* prev;
    int val;
    struct node* next;
}node;

int main(){
    node* head = (node*)malloc(sizeof(node));
    node* snd = (node*)malloc(sizeof(node));
    node* trd = (node*)malloc(sizeof(node));

    head->prev = NULL;
    head->val = 7;
    head->next = snd;

    snd->prev = head;
    snd->val = 8;
    snd->next = trd;

    trd->prev = snd;
    trd->val = 9;
    trd->next = NULL;

    return 0;
}
