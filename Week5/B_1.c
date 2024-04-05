#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int val;
    struct Node* next;
}Node;

Node* addNode(Node* head, int val) {
    Node* newNode = malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = NULL;

    if(!head) head = newNode;
    else {
        Node* tmp = head;
        while(tmp->next) tmp = tmp->next;
        tmp->next = newNode;
    }
    return head;
}

Node* mergeTwoLists(Node* l1, Node* l2) {
    Node* dummy = (Node*)malloc(sizeof(Node));
    dummy->val = 0;
    dummy->next = NULL;
    Node* p = dummy;
    //Dummy node is used as a placeholder at the start of the new linked list.
    //It simplifies the code by providing a consistent 'next' node to attach to
    while (l1 || l2) {
        if (!l1) {
            p->next = l2;
            break;
        }
        if (!l2) {
            p->next = l1;
            break;
        }
        if (l1->val < l2->val) {
            p->next = l1;
            l1 = l1->next;
        } else {
            p->next = l2;
            l2 = l2->next;
        }
        p = p->next;
    }
    Node* result = dummy->next;
    free(dummy); //Free
    return result;
}

void printList(Node* head) {
    Node* tmp = head;
    while(tmp) {
        printf("%d ", tmp->val);
        tmp = tmp->next;
    }
}

int main() {
    Node* head1 = NULL;
    Node* head2 = NULL;
    int n, m, data;
    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++) {
        scanf("%d", &data);
        head1 = addNode(head1, data);
    }
    for(int i = 0; i < m; i++) {
        scanf("%d", &data);
        head2 = addNode(head2, data);
    }
    Node* mergedHead = mergeTwoLists(head1, head2);
    printList(mergedHead);
}