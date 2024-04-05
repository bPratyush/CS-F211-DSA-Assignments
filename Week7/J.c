#include <stdio.h>
#include <stdlib.h>

int main(void){
    int n, x;
    scanf("%d %d", &n, &x);
    int a[n];
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    int k = 0;
    int indices[n];
    for(int i = 0; i < n; i++) {
        if(a[i] < x) indices[k++] = i;
    }
    printf("%d\n", k);
    for(int i = 0; i < k; i++) printf("%d ", indices[i]+1);
}