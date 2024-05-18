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

void preOrder(tree* root){
    if(root==NULL){
        return;
    }
    printf("%d ",root->val);
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(tree* root){
    if(root == NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ",root->val);
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

    tree* root = create(2);
    tree* e1 = create(4);
    tree* e2 = create(5);
    tree* e3 = create(6);
    tree* e4 = create(7);

    //connect
    root->left = e1;
    root->right = e2;

    e1->left = e3;
    e1->right = e4;

    /* final the tree look like this:
               2
              / \
            4    5
           / \  
          6   7                    */

    preOrder(root);
    printf("\n");

    postOrder(root);
    printf("\n");
    
    inOrder(root);

    return 0;
}
