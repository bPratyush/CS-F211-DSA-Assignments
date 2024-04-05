#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void heapify(int arr[], int n, int i) {
    int largest = i; 
    int l = 2 * i + 1; 
    int r = 2 * i + 2; 
    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void buildMaxHeap(int arr[], int n) {
    for (int i = (n/2)-1; i >= 0; i--) heapify(arr, n, i);
}

int extractMax(int a[],int n) {
    if(n<0) return -1;
    int max = a[0];
    a[0] = a[n--]; 
    heapify(a,n,0);
    return max;
}

int max(int a,int b){
    if(a>b) return a;
    return b;
}

int kadane(int c[], int k) {
    int ans = INT_MIN, mx = 0;
    for (int i = 0; i < k; i++) {
        mx = max(mx + c[i],c[i]);
        ans = max(mx,ans);
    }
    return ans;
}

int main(void) {
    int n, k;
    scanf("%d %d", &n, &k);
    int a[n], b[n];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n; i++) scanf("%d", &b[i]);
    int c[n];
    for (int i = 0; i < n; i++) c[i] = a[i] + b[i];
    buildMaxHeap(c, n);
    int subarray[k];
    for (int i = 0; i < k; i++) subarray[i] = extractMax(c, n);
    printf("%d", kadane(subarray, k));
}
