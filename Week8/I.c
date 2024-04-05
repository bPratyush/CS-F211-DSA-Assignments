#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void swap(int *a, int *b) {
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

void quickSort(int arr[], int p, int r) {
    if (p < r) {
        int q = partition(arr, p, r);
        quickSort(arr, p, q - 1);
        quickSort(arr, q + 1, r);
    }
}

int findMedian(int arr[], int n) {
    quickSort(arr, 0, n - 1);
    return arr[n / 2];
}

int kthLargest(int arr[], int l, int r, int k) {
    if (k > 0 && k <= r - l + 1) {
        int n = r - l + 1;
        int i, median[(n + 4) / 5];
        for (i = 0; i < n / 5; i++) median[i] = findMedian(arr + l + i * 5, 5);
        if (i * 5 < n) {
            median[i] = findMedian(arr + l + i * 5, n % 5);
            i++;
        }
        int medOfMed = (i == 1) ? median[i - 1] : kthLargest(median, 0, i - 1, i / 2);
        int pos = partition(arr, l, r);
        if (pos - l == k - 1) return arr[pos];
        if (pos - l > k - 1) return kthLargest(arr, l, pos - 1, k);
        else return kthLargest(arr, pos + 1, r, k - pos + l - 1);
    }
    return -1;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    printf("%d", kthLargest(arr, 0, n - 1, n - k + 1));
} 