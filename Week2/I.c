#include <stdio.h>
#include <limits.h>

int main(void) {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    scanf("%d", &a[i]);
    int sum=0;
    for (int i = 1; i < n; i++) {
        if(a[i]>a[i-1]){
            sum+=a[i]-a[i-1];
        }
    }
    printf("%d\n", sum);
}