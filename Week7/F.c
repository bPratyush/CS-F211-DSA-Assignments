#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int val;
    struct Node* next;
}Node;

Node* createNode(int val){
    Node* node=malloc(sizeof(Node));
    node->val=val;
    node->next=NULL;
    return node;
}

void insertNode(Node**head,int val){
    Node* node=createNode(val);
    Node* curr=*head;
    Node* prev=NULL;
    while(curr && curr->val<val){
        prev=curr;
        curr=curr->next;
    }
    if(!prev){
        node->next=*head;
        *head=node;
    }
    else{
        node->next=prev->next;
        prev->next=node;
    }
}

void printF(Node* head,int freq){
    Node* tmp=head;
    while(tmp && freq){
        printf("%d ",tmp->val);
        tmp=tmp->next;
        freq--;
    }
}

int main(void){
    int n;
    scanf("%d",&n);
    int a[n],freq[n+1];
    Node* buckets[n+1];
    for(int i=0;i<=n;i++){
        buckets[i]=NULL;
        freq[i]=0;
    }
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        freq[a[i]]++;
        insertNode(&buckets[a[i]],a[i]);
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<n;j++){
            if(freq[a[j]]==i){
                printF(buckets[a[j]],freq[a[j]]);
                freq[a[j]]=0;
            }
        }
    }
}