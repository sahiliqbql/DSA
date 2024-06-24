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

node* deleteElmnt(node* head, int n){
    node* p = head;
    node* q = head->next;

    while(q->val!=n && q->next!=NULL){
        q = q->next;
        p = p->next;
    }

    if(q->val == n){
        p->next = q->next;
        free(q);
    }

    return head;
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

    printf("before: ");
    traversal(head);
    printf("\n");
    int n;
    printf("enter num: ");
    scanf("%d",&n);

    deleteElmnt(head,n); // call & deleted

    printf("\n");
    printf("after: ");
    traversal(head);

    return 0;
}
