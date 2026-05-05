#include <stdio.h>
#include <stdlib.h>

int main() {
    int arr[1000], n = 0;
    while (scanf("%d", &arr[n]) != EOF) {
        n++;
    }

    int maxLength = 0;

    for (int i = 0; i < n; i++) {
        int currentSum = 0;
        for (int j = i; j < n; j++) {
            currentSum += arr[j];
            if (currentSum == 0) {
                int currentLength = j - i + 1;
                if (currentLength > maxLength) {
                    maxLength = currentLength;
                }
            }
        }
    }

    printf("%d\n", maxLength);

    return 0;
}