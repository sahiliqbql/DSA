#include <stdio.h>
#include <stdlib.h>

typedef struct queue{
    int size;
    int f;
    int r;
    int* arr;
}queue;

void swap(int* a, int* b){
    int t = *b;
    *b = *a;
    *a = t;
}

void heapify(int *arr, int n) {

    for(int i = n/2; i>=0; i--) {
        int largest = i;
        int l = 2*i + 1;
        int r = 2*i + 2;

        if (l<n && arr[l] > arr[largest]) {
            largest = l;
        }
        if (r<n && arr[r] > arr[largest]) {
            largest = r;
        }
        if (largest != i) {
            swap(&arr[i], &arr[largest]);
        }
    }
}

void enque(queue* q, int x){
    if(q->r == q->size-1){
        printf("Queue overflow, can't insert %d\n", x);
        return;
    }
    if(q->f == -1 && q->r == -1){
        q->f = q->r = 0;
        q->arr[q->r] = x;
    }else{
        q->r++;
        q->arr[q->r] = x;
    }

    heapify(q->arr,q->r+1);

}

void deque(queue* q){
    if(q->f == -1 && q->r == -1){
        printf("empty\n");
        return;
    }

    int n = q->arr[q->f];
    printf("%d\n", n);

    // delete
    if (q->f == q->r) {
        q->f = q->r = -1;
    } else { // maintain heap
        q->arr[q->f] = q->arr[q->r];  // move last element to front 
        q->r--;
        heapify(q->arr, q->r+1);
    }
}

int main(){
    queue* q = (queue*)malloc(sizeof(queue));
    q->size = 3;
    q->f = q->r = -1;
    q->arr = (int*)malloc(q->size*sizeof(int));

    enque(q,6);
    enque(q,9);
    enque(q,3);
    enque(q,5); // full

    deque(q);
    deque(q);
    deque(q);
    deque(q); // empty

}
