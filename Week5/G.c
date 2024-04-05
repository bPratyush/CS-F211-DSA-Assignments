#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* next;
}Node;

Node* addNode(Node* head, int val) {
    Node* node = malloc(sizeof(Node));
    node->val = val;
    node->next = NULL;
    if (!head) {
        head = node;
        node->next = head; //Maintaing Circularity
    } else {
        Node* tmp = head;
        while (tmp->next != head) tmp = tmp->next;
        tmp->next = node;
        node->next = head; //Maintaing Circularity
    }
    return head;
}

int findMeetingPoint(Node *head, int a, int b) {
    Node *dwight = head, *jim = head;
    while (a-- > 1) dwight = dwight->next;
    while (b-- > 1) jim = jim->next;
    while (dwight != jim) {
        dwight = dwight->next->next;
        jim = jim->next;
    }
    return dwight->val;
}

int main() {
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);
    Node *head = NULL;
    for (int i = 1; i <= n; i++) head = addNode(head, i);
    printf("%d",findMeetingPoint(head, a, b));
}