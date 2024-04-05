#include <stdio.h>
#include <stdlib.h>

void mergeArrays(int a[], int n, int b[], int m, int result[]) {
    int i = 0, j = 0, k = 0;
    while (i < n && j < m) {
        if (a[i] <= b[j]) result[k++] = a[i++]; 
        else result[k++] = b[j++];
    }
    while (i < n) result[k++] = a[i++];
    while (j < m) result[k++] = b[j++];
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int a[n], b[m];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < m; i++) scanf("%d", &b[i]);
    int result[n+m];
    E(a, n, b, m, result);
    for (int i = 0; i < n + m; i++) printf("%d ", result[i]);
    return 0;
}
