#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void insertionSort(int arr[], int n) {
    int i;
    for(int j = 1; j < n; j++){
        int key = arr[j];
        i = j - 1;
        while(i >= 0 && arr[i] > key){
            arr[i + 1] = arr[i];
            i--;
        }
        arr[i + 1] = key;
    }
}

void merge(int A[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1 + 1];
    int R[n2 + 1];
    for (int i = 0; i < n1; i++) L[i] = A[p + i];
    for (int i = 0; i < n2; i++) R[i] = A[q + i + 1];
    L[n1] = INT_MAX;
    R[n2] = INT_MAX;
    int i = 0, j = 0;
    for (int k = p; k <= r; k++) {
        if (L[i] <= R[j]) A[k] = L[i++];
        else A[k] = R[j++];
    }
}

void daaSort(int arr[], int l, int r, int k) {
    if (r - l <= k) insertionSort(arr + l, r - l + 1); //Insertion Sort is faster than Merge Sort for small arrays
    else {
        int m = l + (r - l) / 2;
        daaSort(arr, l, m, k);
        daaSort(arr, m + 1, r, k);
        merge(arr, l, m, r);
    }
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int arr[n];
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
    daaSort(arr, 0, n - 1, k);
    for(int i = 0; i < n; i++) printf("%d ", arr[i]);
}