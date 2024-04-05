#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define max(a,b) ((a>b)?(a):(b))
#define ll long long int

int H(long long a[], int n, int k){
	int s=0;
	int e=k-1;
	int maxcnt=0;
	while(s<n&&e<n){
		int tmp=0, cnt=0;
		for(int i=s;i<=e;i++) tmp |= a[i];
		for(int i=0;i<60;i++){
			if((tmp&(1LL<<i))!=0) cnt++;
		}
		s++; e++;
		maxcnt=max(cnt,maxcnt);
	}
	return maxcnt;
}
int main(){
	// int n,k; scanf("%d %d",&n,&k);
	// ll* arr=(ll*) malloc(sizeof(ll)*n);
	// for(int i=0;i<n;i++) scanf("%lld",&arr[i]);

	// int si=0,ei=k-1,ans=0;
	// while(si<n && ei<n){
	// 	ll cur_sat=0,bit_count=0;
	// 	for(int i=si;i<=ei;i++) cur_sat|=arr[i];
	// 	for(int i=0;i<60;i++){
	// 		if(cur_sat&(1LL<<i)) bit_count++;
	// 	}
	// 	si++; ei++;
	// 	ans=max(ans,bit_count);
	// }

	// printf("%d\n",ans);
	// free(arr);
	int n;
  int k;
  scanf("%d %d" , &n , &k);
  long long a[n];
  for(int i=0;i<n;i++) scanf("%llu" , &a[i]);
  printf("%d" , H(a , n , k));
}