// linear search
#include <stdio.h>
int main(){
    int arr[] = {5,6,7,8,1,2};
    int n;
    printf("enter a num: ");
    scanf("%d",&n);
    int s=0;
    for(int i=0; i<6; i++){
        if(arr[i]==n){
            printf("%d is found at idx %d",n,i);
            s++;
        }
    }
    if(s==0){
        printf("not found");
    }
    return 0;
}

// time complexity O(1) to O(n)    avg = O(1)+O(n) / 2
// avg = (1+2+3...+n)/n  = n(n+1)/2n = n+1/2
