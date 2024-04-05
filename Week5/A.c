#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* next;
} Node;

Node* addNode(Node* head, int val) {
    Node* node = malloc(sizeof(Node));
    node->val = val;
    node->next = NULL;
    if (!head) head = node;
    else {
        Node* tmp = head;
        while (tmp->next) tmp = tmp->next;
        tmp->next = node;
    }
    return head;
}

Node* addLists(Node* a, Node* b) {
    Node* result = NULL;
    Node* prev = NULL;
    int carry = 0;
    while (a || b) {
        int sum = carry + (a ? a->val : 0) + (b ? b->val : 0);
        carry = sum/10;
        sum = sum % 10;

        Node* node = malloc(sizeof(Node));
        node->val = sum;
        node->next = NULL;

        if (!result) result = node;
        else prev->next = node;
        prev = node;

        if (a) a = a->next;
        if (b) b = b->next;
    }
    if (carry > 0) {
        Node* node = malloc(sizeof(Node));
        node->val = carry;
        node->next = NULL;
        prev->next = node;
    }
    return result;
}

void printList(Node* head) {
    Node* tmp = head;
    while (tmp) {
        printf("%d ", tmp->val);
        tmp=tmp->next;
    }
}

int main() {
    Node* a = NULL;
    Node* b = NULL;
    int n, m, val;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        a = addNode(a, val);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &val);
        b = addNode(b, val);
    }
    Node* result = addLists(a, b);
    printList(result);
}