#include <stdio.h>

void selectionSort(int arr[],int n){

    for(int i=0; i<n; i++){
        int min = i;
        for(int j=i; j<n; j++){
            if(arr[j]<arr[min]){
                min = j;
            }
        }
        if(min!=arr[i]){
            int t = arr[i];
            arr[i] = arr[min];
            arr[min] = t;
        }
    }
}

int main(){
    int arr[] = {2,1,6,4,3,7,5,9,8};
    int n = sizeof(arr)/sizeof(arr[0]);

    selectionSort(arr,n);

    //print
    for(int i=0; i<n; i++){
        printf("%d ",arr[i]);
    }
    return 0;
}

// O(n2) for all
