#include<stdio.h>
int main()
{
    int n,a,b;
    scanf("%d %d %d", &n ,&a, &b);
    int i=0;
    int av=a/(b+1);
    int s=a%(b+1);
    char ans[n];
    while(i<n){   
        if(s){
            ans[i++]='K';
            s--;
        }
        for(int j=0; j<av; j++) ans[i++]='K';
        if(b){
            ans[i++]='O';
            b--;
        }
    }
    for(int i=0; i<n; i++) printf("%c", ans[i]);
}