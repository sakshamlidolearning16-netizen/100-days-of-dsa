#include <stdio.h>
#include <stdlib.h>

// Structure for interval
typedef struct {
    int start, end;
} Interval;

// Comparator for sorting by start time
int compare(const void *a, const void *b) {
    Interval *x = (Interval *)a;
    Interval *y = (Interval *)b;
    return x->start - y->start;
}

// Min Heap functions
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(int heap[], int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[parent] > heap[index]) {
            swap(&heap[parent], &heap[index]);
            index = parent;
        } else break;
    }
}

void heapifyDown(int heap[], int size, int index) {
    int smallest = index;

    while (1) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < size && heap[left] < heap[smallest])
            smallest = left;
        if (right < size && heap[right] < heap[smallest])
            smallest = right;

        if (smallest != index) {
            swap(&heap[index], &heap[smallest]);
            index = smallest;
        } else break;
    }
}

void push(int heap[], int *size, int value) {
    heap[*size] = value;
    (*size)++;
    heapifyUp(heap, *size - 1);
}

void pop(int heap[], int *size) {
    heap[0] = heap[*size - 1];
    (*size)--;
    heapifyDown(heap, *size, 0);
}

int top(int heap[]) {
    return heap[0];
}

// Main function to find minimum rooms
int minRooms(Interval arr[], int n) {
    qsort(arr, n, sizeof(Interval), compare);

    int heap[n];  // min heap
    int size = 0;

    push(heap, &size, arr[0].end);

    for (int i = 1; i < n; i++) {
        if (arr[i].start >= top(heap)) {
            pop(heap, &size);  // reuse room
        }
        push(heap, &size, arr[i].end);
    }

    return size;
}

int main() {
    int n;
    scanf("%d", &n);

    Interval arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].start, &arr[i].end);
    }

    printf("%d\n", minRooms(arr, n));

    return 0;
}