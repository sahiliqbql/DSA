#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b){
    int t = *b;
    *b = *a;
    *a = t;
}

void maxHeapify(int arr[], int n, int i){
    int largest = i;
    int l = 2*i+1;
    int r = (2*i)+2;
    if(l<n && arr[l]>arr[largest]){
        largest = l;
    }
    if(r<n && arr[r]>arr[largest]){
        largest = r;
    }
    if(largest!=i){
        swap(&arr[largest],&arr[i]);
        maxHeapify(arr, n, largest);
    }
}

void heapSort(int arr[],int n){
    for(int i=n/2-1; i>=0; i--){
        maxHeapify(arr,n,i);
    }
    for(int i=n-1; i>=0; i--){
        swap(&arr[0],&arr[i]);
        maxHeapify(arr,i,0);
    }
}

int main(){
    int arr[] = {3,4,2,1,8,9,5,7,6};
    int n = sizeof(arr)/sizeof(arr[0]);

    heapSort(arr,n);

    for(int i=0; i<n; i++){ 
        printf("%d ",arr[i]);
    }
    return 0;
}

// O(nlogn) --> for all
