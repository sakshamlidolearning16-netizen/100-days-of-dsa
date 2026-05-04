#include <stdio.h>

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements: ", n);
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int pos;
    printf("Enter position to delete: ");
    scanf("%d", &pos);

    if(pos < 1 || pos > n) {
        printf("Invalid position");
        return 0;
    }

    for(int i = pos - 1; i < n - 1; i++)
        arr[i] = arr[i + 1];

    printf("Updated array: ");
    for(int i = 0; i < n - 1; i++)
        printf("%d ", arr[i]);

    return 0;
}