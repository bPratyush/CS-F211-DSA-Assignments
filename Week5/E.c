#include <stdio.h>
#include <stdlib.h>
//Josephus Problem - Circular Linked List
typedef struct Node {
    int val;
    struct Node* next;
} Node;

Node* addNode(Node* head, int val) {
    Node* node = malloc(sizeof(Node));
    node->val = val;
    node->next = NULL;
    if (!head) {
        head = node;
        node->next = head; //Maintaing Circularity
    } else {
        Node* tmp = head;
        while (tmp->next != head) tmp = tmp->next; //tmp->next not equals head
        tmp->next = node;
        node->next = head; //Maintaing Circularity
    }
    return head;
}

int findLastPerson(Node* head,int n, int k) {
    if (k<2) return n;
    Node* tmp=head;
    while (tmp->next!=tmp) {
        for (int i=0;i<k-2;i++) tmp=tmp->next;
        Node* nextNode=tmp->next->next;
        tmp->next = nextNode;
        tmp = nextNode;
    }
    int lastPerson = tmp->val;
    // free(tmp);
    return lastPerson;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    Node* head = NULL;
    for (int i = 1; i <= n; i++) head = addNode(head, i);
    printf("%d", findLastPerson(head,n, k));
}