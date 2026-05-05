#include <stdio.h>

// Function to check if boards can be painted within maxTime using k painters
int canPaint(int boards[], int n, int k, int maxTime) {
    int painters = 1;
    int currTime = 0;

    for (int i = 0; i < n; i++) {
        // If a single board is larger than maxTime → not possible
        if (boards[i] > maxTime)
            return 0;

        if (currTime + boards[i] <= maxTime) {
            currTime += boards[i];
        } else {
            painters++;
            currTime = boards[i];

            if (painters > k)
                return 0;
        }
    }
    return 1;
}

// Function to find minimum time
int minTime(int boards[], int n, int k) {
    int low = boards[0];
    int high = 0;

    // Find max element and sum
    for (int i = 0; i < n; i++) {
        if (boards[i] > low)
            low = boards[i];
        high += boards[i];
    }

    int result = high;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (canPaint(boards, n, k, mid)) {
            result = mid;
            high = mid - 1;  // try smaller value
        } else {
            low = mid + 1;   // increase time
        }
    }

    return result;
}

int main() {
    int n, k;

    scanf("%d %d", &n, &k);

    int boards[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &boards[i]);
    }

    printf("%d\n", minTime(boards, n, k));

    return 0;
}