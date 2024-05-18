// for root node : replace the position of the root with
//                 its inOrder predecessor or inOrder successor
//                            max of left  or   min of right

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

tree* inOrderPredecessor(tree* root){
    root = root->left;
    while(root->right != NULL){
        root = root->right;
    }
    return root;
}

tree* inOrderSuccessor(tree* root){
    root = root->right;
    while(root->left != NULL){
        root = root->left;
    }
    return root;
}

tree* delete(tree* root, int x){

    if(root == NULL){
        return NULL;
    }

    // scarching for that node to be deleated
    if(x < root->val){
        root->left = delete(root->left,x);
    }
    else if(x > root->val){
        root->right = delete(root->right,x);
    }
    else{

        // deleate:

        if(root->left == NULL && root->right == NULL){  // leaf nodes
            root = NULL;
        }

        else if(root->left == NULL){              // one right child
            root = root->right;
        }

        else if(root->right == NULL){        // one left child
            root = root->left;
        }
        
        else{    
            // have 2 child
            tree* temp = inOrderPredecessor(root);
            root->val = temp->val;
            delete(root->left,temp->val);
        }
    }
    return root;
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

    tree* root = create(5);
    tree* e1 = create(3);
    tree* e2 = create(6);
    // tree* e3 = create(1);
    tree* e4 = create(4);

    //connect
    root->left = e1;
    root->right = e2;

    e1->right = e4;

    /* final the tree look like this:
               5
              / \
            3    6
             \  
              4                    */

    
    inOrder(root);
    printf("\n");

    root = delete(root,4);
    root = delete(root,3);
    inOrder(root);
    
    return 0;
}
