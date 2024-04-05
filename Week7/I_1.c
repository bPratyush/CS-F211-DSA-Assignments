#include<stdio.h>
int main(){
    int n , k;
    int freq[26]={0};
    scanf("%d %d" , &n , &k);
    char a[n];
    char buffer;
    scanf("%c" , &buffer);
    char ct;
    while(ct != '\n')
     { scanf("%c" , &ct);
         if(ct != ' ')
         freq[ct-'a']++;
     }
    
    int chosen_freq[26] = {0}; 
    
     while(k>0){
        for(int i=0;i<26;i++){
            if(freq[i] > 0 && k>0)
             {freq[i]--;
               k--;
              chosen_freq[i]++;     
             }
        }     
     }
    
    int sum=0;
    for(int i=0;i<26;i++)
    {
        sum += chosen_freq[i]*chosen_freq[i];
    }
    
    printf("%d" , sum);
}