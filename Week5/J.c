#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int val;
    struct Node* next;
    struct Node* prev;
}Node;

Node* addNode(Node* head, int val){
    Node* node = malloc(sizeof(Node));
    node->val = val;
    node->next = NULL;
    node->prev = NULL;
    if(!head) head = node;
    else {
        Node* tmp = head;
        while(tmp->next) tmp = tmp->next;
        tmp->next = node; 
        node->prev = tmp; 
    }
    return node;
}

Node* addNodeToEnd(Node* head, Node* last, int val){
    Node* node = malloc(sizeof(Node));
    node->val = val;
    node->next = NULL;
    node->prev = NULL;
    if(!last) last=node;
    if(last) {
        node->prev = last;
        last->next = node;
    }
    return node;
}

void printNode(Node* current) {
    if(current) printf("%d ", current->val);
    else printf("0");
}

Node* addNodeAfterCurrent(Node* current, int val) {
    Node* node = malloc(sizeof(Node));
    node->val=val;
    node->next=NULL;
    node->prev = NULL;
    if(!current) current=node;
    if(current) {
        node->next = current->next;
        node->prev = current;
        if(current->next) current->next->prev = node;
        current->next = node;
    }
    return current;
}

Node* moveNext(Node* current) {
    if (current && current->next) return current->next;
    return current;
}

Node* movePrev(Node* current) {
    if (current && current->prev) return current->prev;
    return current;
}

Node* deleteCurrentAndMoveToNext(Node* head, Node* current) {
    if (!current) return NULL;
    if (current->prev) current->prev->next = current->next;
    if (current->next) {
        current->next->prev = current->prev;
        Node* nextNode = current->next;
        free(current);
        return nextNode;
    } 
    else {
        free(current);
        return head;
    }
}

int main(void){
    int n, q;
    Node* head = NULL;
    Node* last = NULL;
    Node* current = NULL;

    scanf("%d %d", &n, &q);
    for(int i = 0; i < n; i++){
        int val;
        scanf("%d", &val);
        last = addNode(head, val);
        current=head;
        if(i == 0) {
            head = last;
        }
    }
    
    for(int i = 0; i < q; i++){
        int operation;
        scanf("%d", &operation);
        if(operation == 1){
            printNode(current);
        } 
        else if(operation == 2){
            int song;
            scanf("%d", &song);
            current = addNodeAfterCurrent(current, song);
        } 
        else if(operation == 3){
            int song;
            scanf("%d", &song);
            last = addNodeToEnd(head, last, song);
        } 
        else if(operation == 4) current = moveNext(current);
        else if(operation == 5) current = movePrev(current);
        else if(operation == 6) current = deleteCurrentAndMoveToNext(head, current);
    }
}