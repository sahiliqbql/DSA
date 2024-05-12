#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int val;
    struct node* next;
}node;

void travesal(node* ptr){
    while(ptr!=NULL){
        printf("%d ",ptr->val);
        ptr = ptr->next;
    }
}

//insert at index
node* insertIdx(node* head, int val, int idx){
    node* p = head;
    int i = 0;
    node* ptr = (node*)malloc(sizeof(node*));
    while(i!=idx-1){
        p = p->next;
        i++;
    }
    ptr->val = val;
    ptr->next = p->next;
    p->next = ptr;
    return head;

}

int main(){
    node* head;
    node* snd;
    node* trd;

    head = (node*)malloc(sizeof(node));
    snd = (node*)malloc(sizeof(node));
    trd = (node*)malloc(sizeof(node));

    head->val = 7;
    head->next = snd;

    snd->val = 8;
    snd->next = trd;

    trd->val = 9;
    trd->next =NULL;

    //insert
    insertIdx(head,66,2);
    //print
    travesal(head);

    return 0;
}
