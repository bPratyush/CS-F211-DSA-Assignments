#include <stdio.h>

int main(void) {
    int n;
    int h;
    scanf("%d %d", &n, &h);
    int a[n];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    int l = 0;
    int r = n - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (a[mid] == h) printf("%d\n", mid+1);
        if (h < a[mid]) r = mid - 1;
        else l = mid + 1;
    }
}
