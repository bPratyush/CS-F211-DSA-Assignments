#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

typedef struct {
    int val;
    int arrIdx;
    int elemIdx;
} HeapNode;

void swap(HeapNode* a, HeapNode* b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(HeapNode heap[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && heap[left].val < heap[i].val) smallest = left;
    if (right < n && heap[right].val < heap[smallest].val) smallest = right;
    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        minHeapify(heap, n, smallest);
    }
}

void buildMinHeap(HeapNode heap[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        minHeapify(heap, n, i);
    }
}

int* mergeKSortedArrays(int* arr[], int k, int sizes[]) {
    HeapNode* heap = malloc(k * sizeof(HeapNode));
    int totalSize = 0;
    for (int i = 0; i < k; i++) {
        heap[i].val = arr[i][0];
        heap[i].arrIdx = i;
        heap[i].elemIdx = 1;
        totalSize += sizes[i];
    }
    buildMinHeap(heap, k);
    int* res = malloc(totalSize * sizeof(int));
    for (int i = 0; i < totalSize; i++) {
        HeapNode root = heap[0];
        res[i] = root.val;
        if (root.elemIdx < sizes[root.arrIdx]) root.val = arr[root.arrIdx][root.elemIdx++];
        else root.val = INT_MAX;
        heap[0] = root;
        minHeapify(heap, k, 0);
    }
    return res;
}

int main() {
    int k;
    scanf("%d", &k);

    int** lists = malloc(sizeof(int*) * k);
    int listSizes[k];

    for (int i = 0; i < k; i++) {
        scanf("%d", &listSizes[i]);
        lists[i] = malloc(sizeof(int) * listSizes[i]);
        for (int j = 0; j < listSizes[i]; j++) scanf("%d", &lists[i][j]);
    }

    int* merged = mergeKSortedArrays(lists, k, listSizes);
    int totalSize = 0;
    for (int i = 0; i < k; i++) totalSize += listSizes[i];
    for (int i = 0; i < totalSize; i++) printf("%d ", merged[i]);
}