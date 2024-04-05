#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
//Median Heap
#define MAX_HEAP_SIZE 100000
#define MIN_HEAP_SIZE 100000

int maxHeap[MAX_HEAP_SIZE];
int minHeap[MIN_HEAP_SIZE];
int maxHeapSize = 0;
int minHeapSize = 0;

int parent(int i){
    return (i - 1) / 2;
}

int Left(int i){
    return 2 * i + 1;
}

int Right(int i){
    return 2 * i + 2;
}

void swapMax(int a, int b) {
    int temp = maxHeap[a];
    maxHeap[a] = maxHeap[b];
    maxHeap[b] = temp;
}

void maxHeapify(int i) {
    int largest = i;
    int left = Left(i);
    int right = Right(i);
    if (left < maxHeapSize && maxHeap[left] > maxHeap[i]) largest = left;
    else largest=i;
    if (right < maxHeapSize && maxHeap[right] > maxHeap[largest]) largest = right;
    if (largest != i) {
        swapMax(i, largest);
        maxHeapify(largest);
    }
}

void heapincreasekey(int i, int key) {
    if (key < maxHeap[i]) {
        printf("new key is smaller than current key");
        return;
    }
    maxHeap[i] = key;
    while (i > 0 && maxHeap[parent(i)] < maxHeap[i]) {
        swapMax(i, parent(i));
        i = parent(i);
    }
}

void maxheapinsert(int key) {
    maxHeapSize++;
    maxHeap[maxHeapSize-1] = INT_MIN;
    heapincreasekey(maxHeapSize-1, key);
}

int extractMax() {
    if(maxHeapSize<0) return -1;
    int max = maxHeap[0];
    maxHeap[0] = maxHeap[maxHeapSize--]; //updates first element of maxHeap array with value of last element
    maxHeapify(0);
    return max;
}

void swapMin(int a, int b) {
    int temp = minHeap[a];
    minHeap[a] = minHeap[b];
    minHeap[b] = temp;
}

void minHeapify(int i) {
    int smallest = i;
    int left = Left(i);
    int right = Right(i);
    if (left < minHeapSize && minHeap[left] < minHeap[i]) smallest = left;
    else smallest=i;
    if (right < minHeapSize && minHeap[right] < minHeap[smallest]) smallest = right;
    if (smallest != i) {
        swapMin(i, smallest);
        minHeapify(smallest);
    }
}

void heapdecreasekey(int i, int key) {
    if (key > minHeap[i]) {
        printf("new key is larger than current key");
        return;
    }
    minHeap[i] = key;
    while (i > 0 && minHeap[parent(i)] > minHeap[i]) {
        swapMin(i, parent(i));
        i = parent(i);
    }
}

void minheapinsert(int key) {
    minHeapSize++;
    minHeap[minHeapSize - 1] = INT_MAX;
    heapdecreasekey(minHeapSize - 1, key);
}

int extractMin() {
    if(minHeapSize<0) return -1;
    int min = minHeap[0];
    minHeap[0] = minHeap[minHeapSize--];
    minHeapify(0);
    return min;
}
//The max heap contains the smaller half of the numbers, and the min heap contains the larger half
void balanceHeaps() {
    while (maxHeapSize > minHeapSize + 1) minheapinsert(extractMax());
    while (minHeapSize > maxHeapSize) maxheapinsert(extractMin());
}

void insertNumber(int x) {
    if (maxHeapSize == 0 || x < maxHeap[0]) maxheapinsert(x);
    else minheapinsert(x);
    balanceHeaps();
}

int getMedian() {
    return maxHeap[0];
}

int main() {
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        int type;
        scanf("%d", &type);
        if (type == 1) {
            int x;
            scanf("%d", &x);
            insertNumber(x);
        } else if (type == 2) printf("%d\n", getMedian());
    }
}
