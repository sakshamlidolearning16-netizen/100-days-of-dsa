#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EMPTY -1
#define DELETED -2

int main() {
    int m, n;
    if (scanf("%d %d", &m, &n) != 2) return 0;

    int *hashTable = (int *)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++) {
        hashTable[i] = EMPTY;
    }

    char command[10];
    int key;

    for (int k = 0; k < n; k++) {
        scanf("%s %d", command, &key);

        int h_k = key % m;

        if (strcmp(command, "INSERT") == 0) {
            for (int i = 0; i < m; i++) {
                int index = (h_k + i * i) % m;
                if (hashTable[index] == EMPTY || hashTable[index] == DELETED) {
                    hashTable[index] = key;
                    break;
                }
            }
        } else if (strcmp(command, "SEARCH") == 0) {
            int found = 0;
            for (int i = 0; i < m; i++) {
                int index = (h_k + i * i) % m;
                if (hashTable[index] == EMPTY) {
                    break;
                }
                if (hashTable[index] == key) {
                    found = 1;
                    break;
                }
            }
            if (found) printf("FOUND\n");
            else printf("NOT FOUND\n");
        }
    }

    free(hashTable);
    return 0;
}