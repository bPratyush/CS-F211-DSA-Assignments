#include <stdio.h>
#include <stdlib.h>

void countingSort(int A[], int B[], int idx[], int idx_sorted[], int n) {
    int C[n+1]; //Cummulative Count Array
    for (int i = 0; i <= n; i++) C[i] = 0;
    for (int j = 0; j < n; j++) C[A[j]]++;
    for (int i = 1; i <= n; i++) C[i] += C[i - 1];
    for (int j = n - 1; j >= 0; j--) {
        B[C[A[j]] - 1] = A[j];
        idx_sorted[C[A[j]] - 1] = idx[j];
        C[A[j]]--;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int A[n];
    int B[n];
    int idx[n];
    int idx_sorted[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
        idx[i] = i + 1;
    }
    countingSort(A, B, idx, idx_sorted, n);
    for (int i = 0; i < n; i++) printf("%d ", B[i]);
    printf("\n");
    for (int i = 0; i < n; i++) printf("%d ", idx_sorted[i]);
    printf("\n");
}