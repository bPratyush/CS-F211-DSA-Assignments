#include<stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    int freq[n+1];
    for(int i=0; i<=n; i++) freq[i]=0;
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    for(int i=0; i<n;i++) freq[a[i]]++;  
    for(int i=1;i<=n;i++){ //Iterate over freq
        for(int j=0; j<n;j++){ //Iterate over elements
            if(freq[a[j]]==i){
                for(int k=0; k<freq[a[j]]; k++) printf("%d ", a[j]);
                freq[a[j]]=-1;
            }
        }
    }
}