#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int val;
    struct Node* next;
}Node;

Node* addNode(Node* head,int val){
    Node* node=malloc(sizeof(Node));
    node->next=NULL;
    node->val=val;

    if(!head) head=node;
    else{
        Node* tmp=head;
        while(tmp->next) tmp=tmp->next;
        tmp->next=node;
    }
    return head;
}

Node* reverse(Node* head){
    Node* prev=NULL;
    Node* curr=head;
    while(curr){
        Node* tmp=curr->next; //Storing curr->next in tmp
        curr->next=prev; //Linking curr->next to prev (Delinking from next)
        prev=curr; //Move prev forward for next iteration
        curr=tmp; //Move curr forward for next iteration
    }
    head=prev;
    return head;
}

void printList(Node* head) {
    Node* tmp = head;
    while(tmp) {
        printf("%d ", tmp->val);
        tmp = tmp->next;
    }
}

int main() {
    Node* head = NULL;
    int n, data;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &data);
        head = addNode(head, data);
    }
    head = reverse(head); //Equate rev(head) with head
    printList(head);
}