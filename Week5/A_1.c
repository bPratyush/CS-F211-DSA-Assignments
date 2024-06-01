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

Node* addTwoNumbers(Node* l1, Node* l2) {
    Node* dummy = malloc(sizeof(Node));
    dummy->next = NULL;
    dummy->val=0;
    Node* p = l1, *q = l2, *curr = dummy;
    int carry = 0;
    while (p || q) {
        int x = (p) ? p->val : 0;
        int y = (q) ? q->val : 0;
        int sum = carry + x + y;
        carry = sum / 10;
        curr->next = addNode(curr->next, sum % 10); //Adding added result in curr node
        curr = curr->next;

        if (p) p = p->next;
        if (q) q = q->next;
    }

    if (carry > 0) curr->next = addNode(curr->next, carry); //Adding left over carry of last digits
    Node* result = dummy->next;
    free(dummy);
    return result;
}

void printList(Node* head) {
    Node* tmp = head;
    while (tmp) {
        printf("%d ", tmp->val);
        tmp = tmp->next;
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

    Node* result = addTwoNumbers(a, b);
    printList(result);
}