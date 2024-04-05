#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Slot;

void swap(Slot* a, Slot* b) {
    Slot temp = *a;
    *a = *b;
    *b = temp;
}

int partition(Slot arr[], int p, int r) {
    int x = arr[r].start;
    int i = p - 1;
    for (int j = p; j <= r - 1; j++) {
        if (arr[j].start <= x) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[r]);
    return (i + 1);
}

void quickSort(Slot arr[], int p, int r) {
    if (p < r) {
        int q = partition(arr, p, r);
        quickSort(arr, p, q - 1);
        quickSort(arr, q + 1, r);
    }
}

int mergeSlots(Slot* slots, int n) {
    int m = 0;
    for(int i = 1; i < n; i++) {
        if(slots[m].end >= slots[i].start) {
            if(slots[m].end < slots[i].end) slots[m].end = slots[i].end;
        }
        else {
            m++;
            slots[m] = slots[i];
        }
    }
    return m + 1;
}

int main() {
    int n;
    scanf("%d", &n);
    Slot* slots = malloc(n * sizeof(Slot));
    for (int i = 0; i < n; i++) scanf("%d %d", &slots[i].start, &slots[i].end);
    quickSort(slots, 0, n - 1);
    int k = mergeSlots(slots, n);
    printf("%d\n", k);
    for (int i = 0; i < k; i++) printf("%d %d\n", slots[i].start, slots[i].end);
}