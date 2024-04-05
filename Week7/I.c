#include<stdio.h>
#include<string.h>

int main()
{
    int n,k;
    scanf("%d %d", &n, &k);
    char s[n];
    for(int i=0; i<n; i++){
        getchar();
        scanf("%c", &s[i]);
    }
    int freq[26]={0};
    for(int i=0; i<n; i++) freq[s[i]-'a']++;
    int chosen[26]={0};
    while(k>0)    
    {
        for(int i=0; i<26; i++)
        {
            if(freq[i])
            {
                freq[i]--;
                chosen[i]++;
                k--;
            }
            if(k==0) break;
        }
    }
    int sumOfSquares=0;
    for(int i=0; i<26; i++) sumOfSquares += chosen[i]*chosen[i];
    printf("%d\n", sumOfSquares);    
}