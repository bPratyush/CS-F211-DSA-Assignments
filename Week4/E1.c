#include <stdio.h>
#include <stdlib.h>

int check(int *s, int n, int k, long long l, long long r, int f) {
    if (f == n) return 1;
    if (s[f] != -1) return check(s, n, k, l, r, f + 1);
    else {
        int result = 0;
        for (int i = 0; i < 10; i++) {
            s[f] = i;
            long long low = 0, high = 0;
            int a = 0, b = 0;
            for (int i = 0; i < n; i++) {
                low *= 10;
                high *= 10;
                if (s[i] == -1) {
                    high += 9;
                    b += 9;
                } else {
                    low += s[i];
                    high += s[i];
                    a += s[i];
                    b += s[i];
                }
            }
            if (low > r || high < l || a > k || b < k) continue;
            result += check(s, n, k, l, r, f + 1);
        }
        s[f] = -1;
        return result;
    }
}

int main() {
    int n, k;
    long long l, r;
    scanf("%d %d %lld %lld", &n, &k, &l, &r);
    char c;
    scanf("%c", &c);
    int *s = (int *)(malloc(sizeof(int) * n));
    for (int i = 0; i < n; i++) {
        char c;
        scanf("%c", &c);
        if (c >= 48 && c <= 57) s[i] = c - 48;
        else s[i] = -1;
    }
    int result = check(s, n, k, l, r, 0);
    printf("%d", result);
}