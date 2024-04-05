#include <stdio.h>
#include <stdlib.h>
#define SIZE 1000000
//Doubly Linked List
typedef struct Node {
    char val;
    struct Node* next;
    struct Node* prev;
} Node;

Node* addNode(Node* head, char val) {
    Node* node = malloc(sizeof(Node));
    node->val = val;
    node->next = NULL;
    node->prev = NULL;
    if(!head) {
        head = node;
    } else {
        Node* tmp = head;
        while(tmp->next) tmp = tmp->next;
        tmp->next = node;
        node->prev = tmp;
    }
    return head;
}

int isPalindrome(Node* head, int n) {
    Node* tail = head;
    while(tail->next) tail = tail->next;
    for(int i = 0; i < n / 2; i++) {
        if(head->val != tail->val) return 0;
        head = head->next;
        tail = tail->prev;
    }
    return 1;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;
    int n;
    char s[SIZE];
    scanf("%d", &n);
    scanf("%s", s);
    for(int i = 0; i < n; i++) {
        tail = addNode(tail, s[i]);
        if(!head) head = tail; //Initialises Head at start of list
    }
    if(isPalindrome(head, n)) printf("YES\n");
    else printf("NO\n");
}