#include <stdio.h>

int main(void){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    int l=0;
    int r=n-1;
    while(l<r){
        int mid=l+(r-l)/2;
        if(a[mid]<a[mid+1])
        l=mid+1;
        else
        r=mid;
    }
    printf("%d\n",l+1);
}