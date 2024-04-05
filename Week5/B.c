#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int val;
    struct Node*next;
}Node;

Node* addNode(Node*head,int val){
    Node* node=malloc(sizeof(Node));
    node->val=val;
    node->next=NULL;
    if(!head) head=node;
    else{
        Node* tmp=head;
        while(tmp->next) tmp=tmp->next;
        tmp->next=node;
    }
    return head;
}

Node* merge(Node* l1, Node* l2) {
    if (!l1) return l2;
    if (!l2) return l1;
    if (l1->val < l2->val) {
        l1->next = merge(l1->next, l2);
        return l1;
    } else {
        l2->next = merge(l1, l2->next);
        return l2;
    }
}

void printNode(Node* head){
    Node *tmp=head;
    while(tmp){
        printf("%d ",tmp->val);
        tmp=tmp->next;
    }
}

int main(void){
    int n,m;
    Node*l1=NULL;
    Node*l2=NULL;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        int num;
        scanf("%d",&num);
        l1 = addNode(l1,num);  
    }
    for(int i=0;i<m;i++){
        int num;
        scanf("%d",&num);
        l2 = addNode(l2,num);  
    }
    Node*res=merge(l1,l2);
    printNode(res);
}