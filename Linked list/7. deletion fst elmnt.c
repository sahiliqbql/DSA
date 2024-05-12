#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int val;
    struct node* next;
}node;

void traversal(node* head){
    while(head != NULL){
        printf("%d ",head->val);
        head = head->next;
    }
}


int main(){
    node* head = (node*)malloc(sizeof(node));
    node* snd = (node*)malloc(sizeof(node));
    node* trd = (node*)malloc(sizeof(node));
    node* frth = (node*)malloc(sizeof(node));

    head->val = 6;
    head->next = snd;

    snd->val = 7;
    snd->next = trd;

    trd->val = 8;
    trd->next = frth;

    frth->val = 9;
    frth->next = NULL;

    //before
    traversal(head);
    printf("\n");

    //deletion
    node* ptr = head;
    head = head->next;
    free(ptr);

    //after
    traversal(head);

    return 0;
}