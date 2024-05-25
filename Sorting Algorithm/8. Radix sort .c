#include <stdio.h>

int maxElement(int arr[], int n){
    int max = arr[0];
    for(int i=1; i<n; i++){
        if(arr[i]>max){
            max = arr[i];
        }
    }
    return max;
}

void  countSort(int arr[], int n, int p){
    int count[10] = {0};

    for(int i=0; i<n; i++){
        count[(arr[i]/p)%10]++;
    }

    for(int i=1; i<10; i++){
        count[i] = count[i]+count[i-1];
    }

    int b[n];
    for(int i=n-1; i>=0; i--){
        b[--count[(arr[i]/p)%10]] = arr[i];
    }

    for(int i=0; i<n; i++){  //copy
        arr[i] = b[i];
    }
}

void radixSort(int arr[], int n){

    int m = maxElement(arr,n);

    for(int p=1; m/p>0; p=p*10){
        countSort(arr,n,p);
    }
}

int main(){
    int arr[] = {2,4,6,5,3,1,9,7,8};
    int n = sizeof(arr)/sizeof(arr[0]);

    radixSort(arr,n);

    for(int i=0; i<n; i++){
        printf("%d ",arr[i]);
    }
    return 0;
}

// O(nd) --> n = size of arr, d = number of digits in the largest element
