#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
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

int randomizedPartition(int arr[], int p, int r) {
    int i = p + rand() % (r - p + 1);
    swap(&arr[r], &arr[i]);
    return partition(arr, p, r);
}

void randomizedQuicksort(int arr[], int p, int r) {
    if (p < r) {
        int q = randomizedPartition(arr, p, r);
        randomizedQuicksort(arr, p, q - 1);
        randomizedQuicksort(arr, q + 1, r);
    }
}

int randomizedSelect(int arr[], int p, int r, int i) {
    if (p == r) return arr[p];
    int q = randomizedPartition(arr, p, r);
    int k = q - p + 1;
    if (i == k) return arr[q];
    else if (i < k) return randomizedSelect(arr, p, q - 1, i);
    else return randomizedSelect(arr, q + 1, r, i - k);
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    randomizedQuicksort(arr, 0, n - 1);
    printf("%d", randomizedSelect(arr, 0, n - 1, n - k + 1));
}