#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int val;
    struct Node* next;
    struct Node* prev;
}Node;

Node* addNodeFront(Node* head, int val) {
    Node* node = malloc(sizeof(Node));
    node->val = val;
    node->next = head;
    node->prev = NULL;
    if (head) head->prev = node;
    return node;
}

Node* addNodeBack(Node* head, int val) {
    Node* node = malloc(sizeof(Node));
    node->val = val;
    node->next = NULL;

    if (!head) {
        node->prev = NULL;
        head = node;
    } else {
        Node* tmp = head;
        while (tmp->next) tmp = tmp->next;
        tmp->next = node;
        node->prev = tmp;
    }
    return head;
}

Node* deleteNodeFront(Node* head) {
    if (!head) return NULL;
    Node* temp = head;
    head = head->next;
    if (head) head->prev = NULL;
    free(temp);
    return head;
}

Node* deleteNodeBack(Node* head) {
    if (!head) return NULL;
    Node* temp = head;
    while (temp->next) temp = temp->next;
    if (temp->prev) temp->prev->next = NULL;
    else head = NULL;
    free(temp);
    return head;
}

void printListForward(Node* head){
    if (!head) {
        printf("-1\n");
        return;
    }
    Node *tmp=head;
    while(tmp){
        printf("%d ",tmp->val);
        tmp=tmp->next;
    }
}

void printListBackward(Node* head) {
    if (!head) {
        printf("-1\n");
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    while (temp) {
        printf("%d ", temp->val);
        temp = temp->prev;
    }
}

int main(void){
    int n, q;
    scanf("%d %d", &n, &q);
    Node* a = NULL;
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        a = addNodeBack(a, val);
    }

    for (int i = 0; i < q; i++) {
        int operation;
        scanf("%d", &operation);

        if (operation == 1) {
            int val;
            scanf("%d", &val);
            a = addNodeFront(a, val);
        } 
        else if (operation == 2) {
            int val;
            scanf("%d", &val);
            a = addNodeBack(a, val);
        } 
        else if (operation == 3) {
            a = deleteNodeFront(a);
        } 
        else if (operation == 4) {
            a = deleteNodeBack(a);
        } 
        else if (operation == 5) {
            printListForward(a);
        } 
        else if (operation == 6) {
            printListBackward(a);
        }
    }
}