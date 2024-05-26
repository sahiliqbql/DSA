#include <stdio.h>

void Tail(int n){
    if(n==0){
        return;
    }
    printf("%d ",n);

    Tail(n-1);
}

void nonTail(int n){
    if(n==0){
        return;
    }
    nonTail(n-1);

    printf("%d ",n);
}

int main(){
    
    Tail(3);   // 3 2 1

    printf("\n");

    nonTail(3);   // 1 2 3 

}
