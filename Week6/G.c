#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int parent(int i){
    return (i - 1) / 2;
}

int left(int i){
    return 2 * i + 1;
}

int right(int i){
    return 2 * i + 2;
}

void heapify(int arr[], int n, int i) {
    int l = left(i);
    int r = right(i);
    int largest = i;
    if (l < n && arr[l] > arr[i]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void buildmaxheap(int arr[], int n){
    for(int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i);
}

long long sum_k_smallest(int arr[], int n, int k) {
    buildmaxheap(arr, k);
    for (int i = k; i < n; i++) {
        if (arr[i] < arr[0]) {
            arr[0] = arr[i];
            heapify(arr, k, 0);
        }
    }
    long long sum = 0;
    for (int i = 0; i < k; i++) sum += arr[i];
    return sum;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    printf("%lld\n", sum_k_smallest(arr, n, k));
}
