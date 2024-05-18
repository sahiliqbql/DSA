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

int inOrder_min(tree* root){

    tree* prev = NULL;

    while(root!=NULL){
        prev = root;
        root = root->left;
    }

    return prev->val;
}

int inOrder_max(tree* root){
    
    tree* prev = NULL;

    while(root!=NULL){
        prev = root;
        root = root->right;
    }

    return prev->val;

}

void isBST(tree* root){

    if( inOrder_max(root->left) < root->val && inOrder_min(root->right) > root->val ){

        printf("valid BST");
        return;
    }
    printf("not a BST");
}

int main(){

    tree* root = create(5);
    tree* e1 = create(3);
    tree* e2 = create(6);
    tree* e3 = create(1);
    tree* e4 = create(4);

    //connect
    root->left = e1;
    root->right = e2;

    e1->left = e3;
    e1->right = e4;

    /* final the tree look like this:
               5
              / \
            3    6
           / \  
          1   4                    */

    
    isBST(root);

    return 0;
}
