#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX_N ((unsigned int)1e6)

int stack[MAX_N],top=-1;

void processStack(int n, int k, char* arr) {
    for(int i=0;i<n;i++){
        while(k && top>=0 && arr[stack[top]]>=arr[i]) {
            k--;
            top--;
        }
        stack[++top]=i;
    }
    while(k && top>=0){
        k--;
        top--;
    }
}

long long calculatePrice(int n, char* arr) {
    long long ten=1,price=0;
    for(int i=top;i>=0;i--){ //Top
        price+=((arr[stack[i]]-'0')*ten); //arr[stack[i]]
        ten*=10;
    }
    return price;
}

long long calculateCost(int n, char* arr) {
    long long ten=1,cost=0;
    for(int i=n-1;i>=0;i--){ //n-1
        cost+=((arr[i]-'0')*ten); //arr[i]
        ten*=10;
    }
    return cost;
}

int main(){
    int n,k; 
    scanf("%d %d",&n,&k);
    char arr[MAX_N];
    scanf("%s",arr);
    processStack(n, k, arr);
    long long price = calculatePrice(n, arr);
    long long cost = calculateCost(n, arr);
    printf("%lld",cost-price);
}