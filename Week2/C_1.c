#include<stdio.h>
#include<stdlib.h>
int main(){
    int n;
    scanf("%d", &n);
    int* a = malloc(sizeof(int) * n);
    for(int i = 0; i < n-1; i++){
        scanf("%d", &a[i]);
    }
    if(a[n-2]==6){
        printf("-1\n");
    }else if(a[n-2]<=5){
        printf("%d\n",7 - a[n-2] - 2);
    }
    else{
        printf("%d\n", n - (a[n-2] - 7) - 2);
    }
    free(a);
    return 0;
}