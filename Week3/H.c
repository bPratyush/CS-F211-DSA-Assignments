#include<stdio.h>
#include<stdint.h>
#define MAX 60

int setBit(int temp , int i){
    return ((temp & 1<<i) != 0);
}

int max(int a, int b){
    if(a>b) return a;
    return b;
}

int solution(uint64_t a[] , int n , int k){
    int start = 0;
    int end = k-1;
    int max_count=0;
    while(end<n){
        uint64_t temp=0;
        int count=0;
        for(int i=start;i<=end;i++) temp |= a[i];
        for(int i=0;i<60;i++){
            if(setBit(temp , i))
            count++;
        }

    max_count=max(count,max_count);
    start++;
    end++;      
    }
    return max_count/2;
}

int main(){
  int n;
  int k;
  scanf("%d %d" , &n , &k);
  uint64_t a[n];
  for(int i=0;i<n;i++) scanf("%llu" , &a[i]);
  printf("%d" , solution(a , n , k));
}
