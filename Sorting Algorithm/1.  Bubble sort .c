#include <stdio.h>
int main(){
    int arr[] = {3,1,5,2,7,9,4,6,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    // int steps = n-1;
    for(int i=0; i<n-1; i++){   // here n-1 is steps

        for(int j=0; j<(n-1)-i; j++){  // here n-1 is index
            if(arr[j]>arr[j+1]){
                int t = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = t;
            }
        }
    }
    //print
    for(int i=0; i<n; i++){
        printf("%d ",arr[i]);
    }

    return 0;
}

// O(n*n) = O(n2)
