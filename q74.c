#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Candidate {
    char name[100];
    int count;
};

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    struct Candidate *votes = malloc(n * sizeof(struct Candidate));
    int uniqueCount = 0;

    for (int i = 0; i < n; i++) {
        char currentName[100];
        scanf("%s", currentName);

        int found = 0;
        for (int j = 0; j < uniqueCount; j++) {
            if (strcmp(votes[j].name, currentName) == 0) {
                votes[j].count++;
                found = 1;
                break;
            }
        }

        if (!found) {
            strcpy(votes[uniqueCount].name, currentName);
            votes[uniqueCount].count = 1;
            uniqueCount++;
        }
    }

    char winner[100];
    int maxVotes = -1;

    for (int i = 0; i < uniqueCount; i++) {
        if (votes[i].count > maxVotes) {
            maxVotes = votes[i].count;
            strcpy(winner, votes[i].name);
        } else if (votes[i].count == maxVotes) {
            if (strcmp(votes[i].name, winner) < 0) {
                strcpy(winner, votes[i].name);
            }
        }
    }

    printf("%s %d\n", winner, maxVotes);

    free(votes);
    return 0;
}