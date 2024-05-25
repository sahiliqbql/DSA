#include <stdio.h>
int main(){
    int arr[] = {1,2,3,4,5,6,7,8};
    int n;
    printf("enter a num: ");
    scanf("%d",&n);
    int l = 0;
    int r = 7;
    int s = 0;
    while(l<=r){
        int mid = (l+r)/2;
        if(arr[mid]==n){
            printf("%d found idx %d",n,mid);
            s++;
            break;
        }
        else if(n<arr[mid]){
            r = mid-1;
        }
        else if(n>arr[mid]){
            l = mid+1;
        }
    }
    if(s==0){
        printf("%d not found",n);
    }
}

// O(logn)