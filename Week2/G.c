#include <stdio.h>
#include <limits.h>

int max(int a, int b){
    if(a<b) return b;
    else return a;
}

int main(void){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    scanf("%d",&a[i]);
    int curr=0;
    int bst=INT_MIN;
    for(int i=0;i<n;i++){
        curr=max(a[i],curr+a[i]);
        bst=max(curr,bst);  
    }      
    printf("%d\n",bst);
}