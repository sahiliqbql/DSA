// O(log log n)

#include <stdio.h>

int ipSearch(int arr[],int l, int r, int x){
    int idx;

    if(l<=r && x>=arr[l] && x<=arr[r]){
        
        idx = l + (((double)(r-l)/(arr[r]-arr[l])) * (x-arr[l]));

        if(arr[idx] == x){
            return idx;
        }
        else if(x<arr[idx]){
            return ipSearch(arr,l,idx-1,x);
        }
        else if(x>arr[idx]){
            return ipSearch(arr,idx+1,r,x);
        }
    }

    return -1;
}

int main(){

    int arr[] = {3,5,6,10,12,15};
    int size = sizeof(arr)/sizeof(arr[0]);
    int n;
    printf("enter a num: ");
    scanf("%d",&n);

    int idx = ipSearch(arr,0,size-1,n);

    if(idx == -1){
        printf("not found");
    }else{
        printf("%d found at idx %d",n,idx);
    }

    return 0;
}
