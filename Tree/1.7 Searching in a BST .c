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

void search(tree* root, int x){

    if(root == NULL){
        printf("%d is not found",x);
        return;
    }

    if(root->val == x){
        printf("%d is found in root",x);
        return;
    }

    if(x>root->val){
        search(root->right,x);
    }

    if(x<root->val){
        search(root->left,x);
    }

}
//  without recursion: use while(root != null) ----> if(x > val) --> (root = root->right) same for left ,
//                     if element found return it

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

    search(root,3);

    return 0;
}
