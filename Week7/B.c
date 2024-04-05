#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    float val;
    struct Node* next;
} Node;

Node* createNode(float val) {
    Node* node = malloc(sizeof(Node));
    node->val = val;
    node->next = NULL;
    return node;
}

//Insertion Sort on LL
void insert(Node** head, float val) {
    Node* node = createNode(val);
    Node* current = *head;
    Node* prev = NULL;
    while (current && current->val < val) {
        prev = current;
        current = current->next;
    }
    if (!prev) {
        node->next = *head;
        *head = node;
    } 
    else {
        node->next = prev->next;
        prev->next = node;
    }
}

int count(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp) {
        count++;
        temp = temp->next;
    }
    return count;
}

void print(Node* head) {
    Node* temp = head;
    while (temp) {
        if (temp->val == (int)temp->val) printf("%d ", (int)temp->val);
        else printf("%.1f ", temp->val);
        temp = temp->next;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    Node** buckets = malloc(n * sizeof(Node*));
    for (int i = 0; i < n; i++) buckets[i] = NULL;
    for (int i = 0; i < n; i++) {
        float num;
        scanf("%f", &num);
        int index = n * num; //Bucket Distribution
        insert(&buckets[index], num);
    }
    for (int i = 0; i < n; i++) print(buckets[i]);
    printf("\n");
    for (int i = 0; i < n; i++) printf("%d ", count(buckets[i]));
}