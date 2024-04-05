#include <stdio.h>
#include <stdlib.h>

void findDays(int *w, int *d, int n, int dir) {
    int stack[n];
    int top = -1;
    for (int i = 0; i < n; i++) d[i] = 0;
    for (int i = 0; i < n; i++) {
        while (top >= 0 && ((dir > 0) ? (w[i] > w[stack[top]]) : (w[i] < w[stack[top]]))) {
            int j = stack[top--];
            d[j] = i - j;
        }
        stack[++top] = i;
    }
    while (top >= 0) d[stack[top--]] = 0;
}

int main() {
    int n;
    scanf("%d", &n);
    int weights[n], daysGreater[n], daysLesser[n];
    for (int i = 0; i < n; i++) scanf("%d", &weights[i]);
    findDays(weights, daysGreater, n, 1);
    findDays(weights, daysLesser, n, -1);
    for (int i = 0; i < n; i++) printf("%d ", daysGreater[i]);
    printf("\n");
    for (int i = 0; i < n; i++) printf("%d ", daysLesser[i]);
}
