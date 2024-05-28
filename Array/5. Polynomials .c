#include <stdio.h>

int main(){

    int n;
    printf("enter term: ");
    scanf("%d",&n);

    int arr[n*2];

    for(int i=0; i<n*2; i+=2){
        printf("enter coff: ");
        scanf("%d",&arr[i]);
        printf("enter pow: ");
        scanf("%d",&arr[i+1]);
    }

    for(int i=0; i<n*2; i+=2){
        if(arr[i]!=0){

            if(arr[i+1]==0){
                printf("%d",arr[i]);
            }else{
                printf("%dx^%d",arr[i],arr[i+1]);
            }
            if(i<n*2-2){
                printf(" + ");
            }
        }
        
    }
    return 0;
}
