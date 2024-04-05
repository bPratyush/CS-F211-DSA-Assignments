#include <stdio.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
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
    else largest=i;
    if (r < n && arr[r] > arr[largest]) largest = r;
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void buildmaxheap(int arr[], int n){
    for(int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i);
}

void heapSort(int a[],int n){
    buildmaxheap(a,n);
    for(int i=n-1;i>=1;i--){
        swap(&a[0],&a[i]);
        n--;
        maxheapify(a,n,0);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
    heapSort(arr, n);
    for(int i = 0; i < n; i++) printf("%d ", arr[i]);
    return 0;
}