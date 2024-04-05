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

void printList(Node* head) {
    Node* tmp = head;
    while(tmp) {
        printf("%d ", tmp->data);
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
    printList(head);
}