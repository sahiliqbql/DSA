#include <stdio.h>
#include <stdlib.h>

struct node{
    int val;
    struct node* next;
};

void LinkedListTraversal(struct node* ptr){
    while(ptr != NULL){
        printf("%d ",ptr->val);
        ptr = ptr->next;
    }
}

//insert at start
struct node* insertStsrt(struct node* head, int data){
    struct node* ptr;
    ptr = (struct node*)malloc(sizeof(struct node));
    ptr->val = data;
    ptr->next = head;
    return ptr;
}

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
    
    // LinkedListTraversal(head); ---> we have to update this head to new head
    head = insertStsrt(head,66);
    //print
    LinkedListTraversal(head);

    return 0;
}