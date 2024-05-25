#include <stdio.h>

void swap(int* a, int* b){
    int t = *b;
    *b = *a;
    *a = t;
}

int partition(int arr[],int l,int r){
    int pivot = arr[l];

    int i=l+1;
    int j=r;

    while(i<=j){

        while(arr[i]<=pivot){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }
        if(i<j){
            swap(&arr[i],&arr[j]);
        }
    };
    
    swap(&arr[l],&arr[j]);
    return j;
}

void quickSort(int arr[], int l,int r){

    int pi; //partition index

    if(l<r){

        pi = partition(arr,l,r);
        quickSort(arr,l,pi-1);
        quickSort(arr,pi+1,r);
    }
}

int main(){
    int arr[] = {2,1,6,4,3,7,5,9,8};
    int n = sizeof(arr)/sizeof(arr[0]);

    quickSort(arr,0,12);

    //print
    for(int i=0; i<n; i++){
        printf("%d ",arr[i]);
    }
    return 0;
}

// worst: O(n2)  avg and best: O(nlogn)
