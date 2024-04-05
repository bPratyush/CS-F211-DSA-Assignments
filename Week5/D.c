#include <stdlib.h>
#include <stdio.h>
// Definition for singly-linked list.
typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;

ListNode* addNode(ListNode* head, int val) {
    ListNode* node = malloc(sizeof(ListNode));
    node->val = val;
    node->next = NULL;

    if (!head) head = node;
    else {
        ListNode* tmp = head;
        while (tmp->next) tmp = tmp->next;
        tmp->next = node;
    }
    return head;
}

ListNode* rotateLeft(ListNode* head, int n,int k) {
    if (!head || !head->next || !k) return head;
    ListNode* tail = head;
    while (tail->next) tail = tail->next;
    k = k % n; //if k>n
    if (!k) return head;
    //k-th node
    ListNode* newTail = head;
    for (int i = 0; i < k - 1; i++) newTail = newTail->next;
    // Make the next of the `k`-th node as the new head and the next of the last node as the old head
    ListNode* newHead = newTail->next;
    newTail->next = NULL;
    tail->next = head;
    return newHead;
}

void printList(ListNode* head) {
    ListNode* tmp = head;
    while (tmp) {
        printf("%d ", tmp->val);
        tmp = tmp->next;
    }
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int val;
    ListNode* head = NULL;
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        head = addNode(head, val);
    }
    ListNode* newHead = rotateLeft(head,n, k);
    printList(newHead);
}