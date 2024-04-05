#include <stdio.h>
#include <math.h>
#include <limits.h>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int p, int r) {
    int x = arr[r];
    int i = p - 1;
    for (int j = p; j <= r - 1; j++) {
        if (arr[j] <= x) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[r]);
    return (i + 1);
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

void Mergesort(int A[], int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        Mergesort(A, p, q);
        Mergesort(A, q + 1, r);
        merge(A, p, q, r);
    }
}

void nomkiSort(int a[], int p, int r, int depth) {
    if (p < r) {
        if (depth <= 0) Mergesort(a, p, r);
        else {
            int q = partition(a, p, r);  // partition function for quicksort
            nomkiSort(a, p, q - 1, depth - 1);
            nomkiSort(a, q + 1, r, depth - 1);
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
    int maxDepth = 2 * log2(n);
    nomkiSort(arr, 0, n - 1, maxDepth);
    for(int i = 0; i < n; i++) printf("%d ", arr[i]);
}