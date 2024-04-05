#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void maxHeapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    if (left < n && arr[left] > arr[largest]) largest = left;
    if (right < n && arr[right] > arr[largest]) largest = right;
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

void buildMaxHeap(int arr[], int n) {
    for (int i = n/2 - 1; i >= 0; i--)  maxHeapify(arr, n, i);
}

int calculateSumOfSquares(char* s, int n, int k) {
    int freq[26] = {0};
    for(int i = 0; i < n; i++) freq[s[i]-'a']++;
    buildMaxHeap(freq, 26);
    int chosen[26] = {0};
    while(k > 0) {
        chosen[0]++;
        freq[0]--;
        k--;
        maxHeapify(freq, 26, 0);
    }
    int sumOfSquares = 0;
    for(int i = 0; i < 26; i++) sumOfSquares += chosen[i]*chosen[i];
    return sumOfSquares;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    char s[n];
    for(int i = 0; i < n; i++) scanf(" %c", &s[i]); //Leave whitespace
    int result = calculateSumOfSquares(s, n, k);
    printf("%d", result);
}