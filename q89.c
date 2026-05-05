#include <stdio.h>
#include <stdlib.h>

int isPossible(int arr[], int n, int m, int maxPages) {
    int studentsRequired = 1;
    int currentSum = 0;

    for (int i = 0; i < n; i++) {
        // If a single book has more pages than allowed maxPages, allocation is impossible
        if (arr[i] > maxPages) return 0;

        if (currentSum + arr[i] > maxPages) {
            studentsRequired++;
            currentSum = arr[i];

            if (studentsRequired > m) return 0;
        } else {
            currentSum += arr[i];
        }
    }
    return 1;
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    int *arr = (int *)malloc(n * sizeof(int));
    int sum = 0, maxVal = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
        if (arr[i] > maxVal) maxVal = arr[i];
    }

    // If students are more than books, allocation is impossible
    if (m > n) {
        printf("-1\n");
        free(arr);
        return 0;
    }

    int low = maxVal;
    int high = sum;
    int ans = sum;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (isPossible(arr, n, m, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    printf("%d\n", ans);

    free(arr);
    return 0;
}