#include <stdio.h>
int main(){
    int arr[] = {2,1,6,4,3,7,5,9,8};
    int n = sizeof(arr)/sizeof(arr[0]);

    for(int i=1; i<n; i++){
        int j=i;
        while(j>0 && arr[j-1]>arr[j]){
            int t = arr[j-1];
            arr[j-1] = arr[j];
            arr[j] = t;
            j--;
        }
    }

    //print
    for(int i=0; i<n; i++){
        printf("%d ",arr[i]);
    }
}

// O(n2)
