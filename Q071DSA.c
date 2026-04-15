#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EMPTY -1

int main() {
    int m, n;
    if (scanf("%d %d", &m, &n) != 2) return 0;

    int *hashTable = (int *)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++) hashTable[i] = EMPTY;

    char command[10];
    int key;

    for (int j = 0; j < n; j++) {
        scanf("%s %d", command, &key);

        if (strcmp(command, "INSERT") == 0) {
            int i = 0;
            int h_k = key % m;
            while (i < m) {
                int index = (h_k + i * i) % m;
                if (hashTable[index] == EMPTY) {
                    hashTable[index] = key;
                    break;
                }
                i++;
            }
        } 
        else if (strcmp(command, "SEARCH") == 0) {
            int i = 0;
            int h_k = key % m;
            int found = 0;
            while (i < m) {
                int index = (h_k + i * i) % m;
                if (hashTable[index] == key) {
                    found = 1;
                    break;
                }
                if (hashTable[index] == EMPTY) break;
                i++;
            }
            if (found) printf("FOUND\n");
            else printf("NOT FOUND\n");
        }
    }

    free(hashTable);
    return 0;
}
