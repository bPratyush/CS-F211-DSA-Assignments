#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int parent(int i){
    return (i-1)/2;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int* arr, int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] < arr[smallest]) smallest = left;
    if (right < n && arr[right] < arr[smallest]) smallest = right;
    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        heapify(arr, n, smallest);
    }
}

void heapdecreasekey(int arr[], int i, int key) {
    if (key > arr[i]) {
        printf("new key is larger than current key");
        return;
    }
    arr[i] = key;
    while (i > 0 && arr[parent(i)] > arr[i]) {
        swap(&arr[i], &arr[parent(i)]);
        i = parent(i);
    }
}

void insert(int arr[], int* size, int capacity, int key) {
    if (*size == capacity) return;
    arr[*size] = INT_MAX;
    (*size)++;
    heapdecreasekey(arr, *size - 1, key);
}

int extractMin(int arr[], int* n) {
    int root = arr[0];
    arr[0] = arr[*n - 1];
    (*n)--;
    heapify(arr, *n, 0);
    return root;
}

int main(void) {
    int n, x;
    scanf("%d %d", &n, &x);
    int minHeap[n];
    int heapSize = 0;
    int k = 0;
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        if (num < x) {
            insert(minHeap, &heapSize, n, i);
            k++;
        }
    }
    printf("%d\n", k);
    for (int i = 0; i < k; i++) printf("%d ", extractMin(minHeap, &heapSize) + 1);
}
