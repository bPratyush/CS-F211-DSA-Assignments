#include <stdlib.h>
#include <stdio.h>

int compare(const void* a, const void* b) {
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;

    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

long long sum_k_smallest(int arr[], int n, int k) {
    qsort(arr, n, sizeof(int), compare);
    long long sum = 0;
    for (int i = 0; i < k; i++) sum += arr[i];
    return sum;
}

int main() {
    int arr[] = {10, 5, 1, 6, 20, 7, 9, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    long long sum = sum_k_smallest(arr, n, k);

    printf("The sum of the smallest %d elements is %lld\n", k, sum);

    return 0;
}