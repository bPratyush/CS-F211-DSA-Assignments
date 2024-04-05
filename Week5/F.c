#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* addNode(Node* head, int data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if(!head) head = newNode;
    else {
        Node* tmp = head;
        while(tmp->next) tmp = tmp->next;
        tmp->next = newNode;
    }
    return head;
}

void removeDuplicates(Node* head) {
    Node *tmp = head, *prev = NULL;
    int hash[1000000] = {0};
    while(tmp) {
        if(hash[tmp->data]) {
            prev->next = tmp->next;
            free(tmp);
        }
        else {
            hash[tmp->data] = 1;
            prev = tmp;
        }
        tmp = prev->next;
    }
}

void printList(Node* head) {
    Node* tmp = head;
    while(tmp) {
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    int n, data;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &data);
        head = addNode(head, data);
    }
    removeDuplicates(head);
    printList(head);
}