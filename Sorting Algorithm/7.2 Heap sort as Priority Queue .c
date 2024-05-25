// out of syllabus (may be)

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int *data;
    int capacity;  //Maximum possible size of the max-heap
    int size;     //Current size of the max-heap
} MaxHeap;

// maxHeap = queue = array

MaxHeap* createMaxHeap(int capacity) {
    MaxHeap* maxHeap = (MaxHeap*) malloc(sizeof(MaxHeap));
    maxHeap->capacity = capacity;
    maxHeap->size = 0;
    maxHeap->data = (int*) malloc(capacity * sizeof(int));
    return maxHeap;
}

int parent(int i) { return (i - 1) / 2; }
int leftChild(int i) { return (2 * i + 1); }
int rightChild(int i) { return (2 * i + 2); }

void maxHeapify(MaxHeap* maxHeap, int i) {
    int l = leftChild(i);
    int r = rightChild(i);
    int largest = i;

    if (l < maxHeap->size && maxHeap->data[l] > maxHeap->data[largest])
        largest = l;

    if (r < maxHeap->size && maxHeap->data[r] > maxHeap->data[largest])
        largest = r;

    if (largest != i) {
        int temp = maxHeap->data[i];
        maxHeap->data[i] = maxHeap->data[largest];
        maxHeap->data[largest] = temp;
        maxHeapify(maxHeap, largest);
    }
}

void insertMaxHeap(MaxHeap* maxHeap, int key) {
    if (maxHeap->size == maxHeap->capacity) {
        printf("Overflow: Could not insert key\n");
        return;
    }

    int i = maxHeap->size;
    maxHeap->size++;
    maxHeap->data[i] = key;

    while (i != 0 && maxHeap->data[parent(i)] < maxHeap->data[i]) {
        int temp = maxHeap->data[i];
        maxHeap->data[i] = maxHeap->data[parent(i)];
        maxHeap->data[parent(i)] = temp;
        i = parent(i);
    }
}

int extractMax(MaxHeap* maxHeap) {   //actualy deletion
    if (maxHeap->size <= 0)
        return INT_MIN;
    if (maxHeap->size == 1) {
        maxHeap->size--;
        return maxHeap->data[0];
    }

    int root = maxHeap->data[0];
    maxHeap->data[0] = maxHeap->data[maxHeap->size - 1];
    maxHeap->size--;
    maxHeapify(maxHeap, 0);

    return root;
}

void heapSort(int *arr, int n) {
    MaxHeap* maxHeap = createMaxHeap(n);
    
    for (int i = 0; i < n; i++) {
        insertMaxHeap(maxHeap, arr[i]);
    }
    
    for (int i = n - 1; i >= 0; i--) {
        arr[i] = extractMax(maxHeap);
    }

    free(maxHeap->data);
    free(maxHeap);
}

int main() {
    int arr[] = {3,6,8,9,2,1,5,4,7};
    int n = sizeof(arr)/sizeof(arr[0]);

    heapSort(arr, n);

    for(int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}

// O(log N) 