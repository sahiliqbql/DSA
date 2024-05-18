#include <stdio.h>
#include <stdlib.h>

typedef struct tree{
    int val;
    struct tree* left;
    struct tree* right;
}tree;

tree* create(int x){
    tree* t = (tree*)malloc(sizeof(tree));
    t->left = NULL;
    t->right = NULL;
    t->val = x;
    return t;
}

void insert(tree* root, int x){

    tree* prev = NULL;

    while(root!=NULL){

        prev = root;

        if(x==root->val){
            printf("can't insert repeated %d",x);
            return;
        }

        if(x > root->val){
            root = root->right;
        }
        else if(x<root->val){
            root = root->left;
        }
    }

    tree* new = create(x);

    if(x>prev->val){
        prev->right = new;
    }else{
        prev->left = new;
    }
}

void inOrder(tree* root){
    if(root == NULL){
        return;
    }
    inOrder(root->left);
    printf("%d ",root->val);
    inOrder(root->right);
}

int main(){
    
    tree* root = create(5); // first create then insert

    insert(root,6);
    insert(root,3);
    insert(root,11);

    inOrder(root);

    insert(root,3);
    
    return 0;
}
