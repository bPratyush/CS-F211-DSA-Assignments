#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

void swap(int*a,int*b){
    int tmp=*a;
    *a=*b;
    *b=tmp;
}

int kadane(int c[], int k){
    int ans = INT_MIN, mx = 0;
    for (int i = 0; i < k; i++) {
        mx = max(mx + c[i], c[i]);
        ans = max(ans, mx);
    }
    return ans;
}

void bubbleSortDescending(int* a, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] < a[j + 1]) {
                swap(&a[j],&a[j+1]);
            }
        }
    }
}

int main(void) {
    int n, k;
    scanf("%d %d", &n, &k);
    int a[n], b[n];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n; i++) scanf("%d", &b[i]);
    int c[n];
    for (int i = 0; i < n; i++) c[i] = a[i] + b[i];
    bubbleSortDescending(c, n);
    int sum = kadane(c, k);
    printf("%d", sum);
}