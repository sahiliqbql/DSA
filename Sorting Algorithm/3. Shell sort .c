#include <stdio.h>

void shell_sort(int arr[],int n){
    for(int gap=n/2; gap>=1; gap=gap/2){
        
        for(int i=0,j=gap;j<n;i++,j++){
            if(arr[i]>arr[j]){
                int t = arr[j];
                arr[j] = arr[i];
                arr[i] = t; 
            }
        }
    }
}

int main(){
    int arr[] = {2,1,6,4,3,7,5,9,8};
    int n = sizeof(arr)/sizeof(arr[0]);

    shell_sort(arr,n);

    //print
    for(int i=0; i<n; i++){
        printf("%d ",arr[i]);
    }
    return 0;
}

// O(nlog n)   to O(n2)     avg = O(nlog n)
