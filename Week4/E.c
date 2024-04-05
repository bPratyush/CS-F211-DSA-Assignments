#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ll long long int

void possibleWays(ll n, ll k, ll l, ll r,char digits[],int index,ll currentNum,ll currentSum,int* count) {
    if(index == n) {
        if(currentSum == k && l <= currentNum && currentNum <= r) (*count)++;
        return;
    }
    if(digits[index] != '?')
        possibleWays(n,k,l,r,digits,index+1,currentNum*10+digits[index]-'0',currentSum+digits[index]-'0',count);
    else {
        for(int i = 0; i < 10; i++) {
            if(!(currentNum == 0 && i == 0 && k != 0))
                possibleWays(n, k, l, r, digits, index+1, currentNum*10 + i, currentSum + i, count);
        }
    }
}

int main() {
    ll n, k, l, r;
    scanf("%lld %lld %lld %lld", &n, &k, &l, &r);
    char digits[n];
    getchar();
    for(int i = 0; i < n; i++) scanf("%c", &digits[i]);
    int count = 0;
    possibleWays(n, k, l, r, digits, 0, 0, 0, &count);
    printf("%d", count);
}