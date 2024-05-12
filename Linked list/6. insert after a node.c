#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int val;
    struct node* next;  
}node;

void traversal(node* head){
    while(head!=NULL){
        printf("%d ",head->val);
        head = head->next;
    }
}

node* insertAnode(node* preNode, int val){

    node* ptr = (node*)malloc(sizeof(node));
    ptr->val = val;
    ptr->next = preNode->next;
    preNode->next = ptr;

    return preNode;
}

int main(){
    node* head = (node*)malloc(sizeof(node));
    node* snd = (node*)malloc(sizeof(node));
    node* trd = (node*)malloc(sizeof(node));

    head->val = 7;
    head->next = snd;

    snd->val = 8;
    snd->next = trd;

    trd->val = 9;
    trd->next = NULL;

    insertAnode(snd,66);
    traversal(head);

    return 0;
}