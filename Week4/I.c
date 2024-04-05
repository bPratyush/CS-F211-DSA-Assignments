#include<stdio.h>
#include<limits.h>

long long int maxNum=LLONG_MIN, minNum= LLONG_MAX ;

void possibleWays(int n, int k, int index,  long long int current_num, long int current_sum)
{
    if(index==n){//full number formed
        if(current_num<minNum && current_sum==k) minNum=current_num;
        if(current_num>maxNum  && current_sum==k) maxNum=current_num;
        return;
    }
    if (current_sum > k) return; // Early return if sum already exceeds k
    for(int i=0;i<10;i++){
        if(!(current_num==0  && i==0))
        possibleWays(n,k,index+1,current_num*10+i,current_sum+i);
    }
}

int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    possibleWays(n,k,0,0,0);
    if(minNum==LLONG_MAX) printf("-1 -1");
    else printf("%lld %lld",minNum,maxNum);
}