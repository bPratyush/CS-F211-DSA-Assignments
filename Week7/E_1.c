#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int num1;
    int num2;
}pair;

void countSort2(pair* arr,int l,int r,int n){
    int freq[1000]={0};
    for(int i=l;i<=r;i++) freq[arr[i].num2]++;
    for(int i=1;i<=n;i++) freq[i]+=freq[i-1];
    int ans[r-l+1];
    for(int i=r;i>=l;i--){
        int k=--freq[arr[i].num2];
        ans[k]=arr[i].num2;
    }
    int ansIndex=0;
    for(int i=l;i<=r;i++){
        arr[i].num2=ans[ansIndex];
        ansIndex++;
    }
}

void countSort(pair* arr,int n){
    int freq[10000]={0};
    for(int i=0;i<=n;i++) freq[i]=0;
    for(int i=0;i<n;i++) freq[arr[i].num1]++;
    //calc cummmulative freq
    for(int i=1;i<=n;i++) freq[i]+=freq[i-1];
    pair* ans=malloc(n*sizeof(pair));
    for(int i=n-1;i>=0;i--){
        int k=--freq[arr[i].num1];
        ans[k].num1=arr[i].num1;
        ans[k].num2=arr[i].num2;
    }
    for(int i=0;i<n;i++){
        arr[i].num1=ans[i].num1;
        arr[i].num2=ans[i].num2;
    }
    for(int i=1;i<=n;i++) countSort2(arr,freq[i-1],freq[i]-1,n);
}

int main(){
    int n;
    scanf("%d",&n);
    pair* arr=malloc(n*sizeof(pair));
    for(int i=0;i<n;i++) scanf("%d",&arr[i].num1);
    for(int i=0;i<n;i++) scanf("%d",&arr[i].num2);
    countSort(arr,n);
    for(int i=0;i<n;i++) printf("%d ",arr[i].num1);
    printf("\n");
    for(int i=0;i<n;i++) printf("%d ",arr[i].num2);
}