#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
#define ll long long int

int max(int a, int b){
    if(a>b) return a;
    return b;
}

int min(int a,int b){
    if(a<b) return a;
    return b;
}

int n,k;
int a[8];
int fr[8];
int B(int index,int fr[]){
    if(index==n){
        int mb=0;
        for(int i=0;i<k;i++) mb=max(mb,fr[i]);
        return mb;
    }
    else{
        int mini=__INT_MAX__;
        for(int i=0;i<k;i++){
            fr[i]+=a[index];
            int beau=B(index+1,fr);
            mini=min(mini,beau);
            fr[i]-=a[index];
        }
        return mini;
    }
}

int main(void){
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    int res=B(0,fr);
    printf("%d",res);
}