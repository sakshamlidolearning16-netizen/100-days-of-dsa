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

// Function to merge intervals
void mergeIntervals(Interval arr[], int n) {
    // Step 1: Sort intervals
    qsort(arr, n, sizeof(Interval), compare);

    // Temporary array for result
    Interval result[n];
    int idx = 0;

    result[idx] = arr[0];

    // Step 2: Merge
    for (int i = 1; i < n; i++) {
        if (arr[i].start <= result[idx].end) {
            // Overlapping → merge
            if (arr[i].end > result[idx].end)
                result[idx].end = arr[i].end;
        } else {
            // No overlap → new interval
            idx++;
            result[idx] = arr[i];
        }
    }

    // Print result
    for (int i = 0; i <= idx; i++) {
        printf("%d %d\n", result[i].start, result[i].end);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    Interval arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].start, &arr[i].end);
    }

    mergeIntervals(arr, n);

    return 0;
}