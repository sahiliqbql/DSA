#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int val;
    struct node* next;
}node;

void traversal(node* head){
    node* ptr = head;
    do{
        printf("%d ",ptr->val);
        ptr = ptr->next;
    }while(ptr!=head);
}

//insert
node* insertFst(node* head, int val){
    node* ptr;
    ptr = (node*)malloc(sizeof(node));
    ptr->val = val;

    node* p = head->next;
    while(p->next!=head){
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;

    return ptr;
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
    frth->next = head; // head

    head = insertFst(head,66);
    //print
    traversal(head);

    return 0;
}
