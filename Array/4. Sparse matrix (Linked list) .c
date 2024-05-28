#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int i_idx;
    int j_idx;
    int val;
    struct node* next;
}spr;

// When we pass a single pointer to a function, 
// any changes to the pointer itself are local(stay) to the function 
// the modification won't affect the original

// if we want to chane the original in void we give its address to that func
// here we give the address of that pointer head
// thats why we give &head insted of only head [in main() func]
// and we use the value of that address, so we simply add a * --> spr*(*head) [in push func]

//in case of array we dont need to pass address we simply pass the arr 
// beacuse array was always pass by reference

void push(spr* *head, int i, int j, int x){

    spr* new = (spr*)malloc(sizeof(spr));
    new->i_idx = i;
    new->j_idx = j;
    new->val = x;
    new->next = NULL;

    if(*head==NULL){
        *head = new;
        return;
    }

    spr* temp = *head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = new;
}

void print_linkL(spr* head){
    while(head!=NULL){
        printf("%d %d %d",head->i_idx,head->j_idx,head->val);
        printf("\n");
        head = head->next;
    }
}

void print_link_2_way(spr* head){
    spr* r, *c, *x;
    r = c = x = head;

    printf("R: ");
    while(r!=NULL){
        printf("%d ",r->i_idx);
        r = r->next;
    }
    printf("\n");

    printf("C: ");
    while(c!=NULL){
        printf("%d ",c->j_idx);
        c = c->next;
    }
    printf("\n");

    printf("X: ");
    while(x!=NULL){
        printf("%d ",x->val);
        x = x->next;
    }
}

int main(){
    int arr[4][4] = {{0, 0, 1, 0},
                     {0, 2, 0, 0},
                     {0, 0, 3, 0},
                     {4, 0, 0, 0}};
    int m = 4;
    int n = 4;

    int zro = 0;
    int n_zro = 0;

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if (arr[i][j] == 0){
                zro++;
            }
            else{
                n_zro++;
            }
        }
    }

    if(n_zro >= zro){
        printf("not a aparse matrix");
    }else{
        spr* head = NULL;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(arr[i][j]!=0){
                    push(&head,i,j,arr[i][j]);
                }
            }
        }

        print_linkL(head);
        printf("\n");
        print_link_2_way(head);
    }

    return 0;
}
