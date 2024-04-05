#include <stdio.h>

double avg(int a[], int l, int r) {
    int sum = 0;
    for (int i = l; i <= r; i++) sum += a[i];
    int p = r - l + 1;
    return (double)sum / p;  
}

int func(int a[], int n, int k, int x) {
    int cnt = 0;
    int i = 0;
    int j = k - 1;  
    while (j < n) {
        double average = avg(a, i, j);
        if (average >= x) cnt++;
        i++;
        j++;
    }
    return cnt;
}

int main(void) {
    int n, k, x;
    scanf("%d %d %d", &n, &k, &x);
    int a[n];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    int result = func(a, n, k, x);
    printf("%d", result);
}

