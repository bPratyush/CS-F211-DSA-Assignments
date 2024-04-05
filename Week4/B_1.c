#include<stdio.h>
#include<limits.h>

int a[10];
int group[10];
int min_group_sum;

int max(int a, int b) {
    return (a > b) ? a : b;
}

void partition(int n, int k, int index, int used, int max_group_sum) {
    if (max_group_sum >= min_group_sum) return; // pruning
    if (index == n) {
        if (used == k) {
            min_group_sum = max_group_sum; // found a better solution
        }
        return;
    }
    if (used < k) {
        group[used] = a[index];
        partition(n, k, index+1, used+1, max(max_group_sum, a[index]));
    }
    for (int i = 0; i < used; i++) {
        group[i] += a[index];
        partition(n, k, index+1, used, max(max_group_sum, group[i]));
        group[i] -= a[index]; // backtrack
    }
}

int main(){
    int n, k;
    scanf("%d",&n);
    scanf("%d",&k);
    int sum = 0;
    for(int i=0;i<n;i++){
        int num = 0;
        scanf("%d",&num);
        a[i] = num ; 
        sum+=num;
    }
    int av = ((sum%k)==0)?(sum/k):((int)(sum/k) + 1);
    min_group_sum = sum;
    partition(n, k, 0, 0, 0);
    printf("%d\n", min_group_sum);
    return 0;
}