#include <stdio.h>
#include <stdlib.h>

void mergeSort(int arr[],int l,int r){
    if(l<r){
        int mid = (l+r)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        
        merge2ndWay(arr,l,mid,r);
    }
}

void merge(int arr[],int l,int mid,int r){
    int i=l;
    int j = mid+1;

    int ln = r-l+1;
    int cpy[ln];
    int k = 0;

    while(i<=mid && j<=r){
        if(arr[i]<arr[j]){
            cpy[k] = arr[i];
            k++,i++;
        }else{
            cpy[k] = arr[j];
            k++,j++;
        }
    }
    while(i<=mid){
        cpy[k] = arr[i];
        k++,i++;
    }
    while(j<=r){
        cpy[k] = arr[j];
        k++,j++;
    }

    for (i = l, k = 0; i <= r; i++, k++) {
        arr[i] = cpy[k];
    }
}

//another way
void merge2ndWay(int arr[], int l, int mid, int r){
    int size1 = mid-l+1;
    int size2 = r-mid;

    int a[size1];
    int b[size2];

    for(int i=0; i<size1; i++){
        a[i] = arr[l+i];
    }
    for(int j=0; j<size1; j++){
        b[j] = arr[mid+1+j];
    }

    int i,j,k;
    i=j=0;
    k = l;
    while(i<size1 && j<size2){
        if(a[i]<b[j]){
            arr[k]=a[i];
            k++,i++;
        }else{
            arr[k]=b[j];
            k++,j++;
        }
    }
    while(i<size1){
        arr[k]=a[i];
        i++;
        k++;
    }
    while(j<size2){
        arr[k]=b[j];
        j++;
        k++;
    }
}


int main(){
    int arr[] = {2,1,6,4,3,7,5,9,8};
    int n = sizeof(arr)/sizeof(arr[0]);

    mergeSort(arr,0,n-1);

    //print
    for(int i=0; i<n; i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
// O(n log n) for all




// marge 2 array in 1 : example for understanding
//marge a and b into a new array c[]
void merge2arr(int a[], int b[], int c[],int m,int n){    // m = size of a[], n = size of b[]

    int i,j,k; // i = index of a[] , j=b[] and k=c[]
    i=j=k = 0;

    while(i<m && j<n){
        if(a[i]<b[j]){
            c[k] = a[i];
            i++;
            k++;
        }else{
            c[k]=b[j];
            j++;
            k++;
        }
    } // either i or j was completed

    // copy rest of the element from a[] either b[]
    while(i<m){
        c[k]=a[i];
        c++,j++;
    }
    //or
    while(j<n){
        c[k]=b[j];
        c++,j++;
    }
}
// this portion is just an example
