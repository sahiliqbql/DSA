#include <stdio.h>
int main(){
    int arr[] = {3,1,5,2,7,9,4,6,8};
    int n = sizeof(arr)/sizeof(arr[0]);

    for(int i=0; i<n-1; i++){

        int flag = 0;

        for(int j=0; j<(n-1)-i; j++){
            if(arr[j]>arr[j+1]){
                int t = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = t;
                flag++;
            }
        }

        if(flag == 0){
            break;
        }
    }

    //print
    for(int i=0; i<n; i++){
        printf("%d ",arr[i]);
    }

    return 0;
}

// best use in shorted array 
// O(1*n) to O(n*n) = O(n) to O(n2)
