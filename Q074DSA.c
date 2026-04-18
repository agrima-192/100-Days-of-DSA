#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char name[100];
    int count;
} Candidate;

int compareCandidates(const void *a, const void *b) {
    return strcmp(((Candidate *)a)->name, ((Candidate *)b)->name);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    char currentName[100];
    Candidate unique[n];
    int uniqueCount = 0;

    for (int i = 0; i < n; i++) {
        scanf("%s", currentName);
        
        int found = 0;
        for (int j = 0; j < uniqueCount; j++) {
            if (strcmp(unique[j].name, currentName) == 0) {
                unique[j].count++;
                found = 1;
                break;
            }
        }
        
        if (!found) {
            strcpy(unique[uniqueCount].name, currentName);
            unique[uniqueCount].count = 1;
            uniqueCount++;
        }
    }

    qsort(unique, uniqueCount, sizeof(Candidate), compareCandidates);

    int maxVotes = 0;
    int winnerIdx = 0;

    for (int i = 0; i < uniqueCount; i++) {
        if (unique[i].count > maxVotes) {
            maxVotes = unique[i].count;
            winnerIdx = i;
        }
    }

    printf("%s %d\n", unique[winnerIdx].name, unique[winnerIdx].count);

    return 0;
}
