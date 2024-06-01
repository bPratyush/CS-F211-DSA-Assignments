#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int a[n - 1];
    for (int i = 0; i < n - 1; i++) scanf("%d", &a[i]);
    int start = 0, end = n - 2;
    while (start <= end) {
        int mid = start + (end-start) / 2;
        if (a[mid] == 7) printf("%d\n", mid);
        if (a[mid] >= a[start]) {
            if (7 < a[mid] && 7 >= a[start]) end = mid - 1;
            else start = mid + 1;
        } 
        else {
            if (7 > a[mid] && 7 <= a[end]) start = mid + 1;
            else end = mid - 1;
        }
    }
    printf("-1\n");
    return 0;
}
