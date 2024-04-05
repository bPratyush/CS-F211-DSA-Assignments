#include <stdio.h>

int countGroups(int n, int k, int x, int a[]) {
    int count = 0;
    int sum = 0;
    for (int i = 0; i < k; i++) sum += a[i];
    if (sum >= x * k) count++;
    for (int i = k; i < n; i++) {
        sum += a[i] - a[i - k];
        if (sum >= x * k) count++;
    }
    return count;
}

int main() {
    int n, k, x;
    scanf("%d %d %d", &n, &k, &x);
    int a[n];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    int result = countGroups(n, k, x, a);
    printf("%d\n", result);
}
