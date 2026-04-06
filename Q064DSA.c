#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void bfs(int n, int adj[MAX][MAX], int s) {
    int queue[MAX];
    int front = 0, rear = 0;
    int visited[MAX] = {0};

    queue[rear++] = s;
    visited[s] = 1;

    printf("BFS Traversal Order: ");

    while (front < rear) {
        int curr = queue[front++];
        printf("%d ", curr);

        for (int i = 0; i < n; i++) {
            if (adj[curr][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
}

int main() {
    int n, s;
    int adj[MAX][MAX];

    if (scanf("%d", &n) != 1) return 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (scanf("%d", &adj[i][j]) != 1) return 1;
        }
    }

    if (scanf("%d", &s) != 1) return 1;

    if (s >= 0 && s < n) {
        bfs(n, adj, s);
    }

    return 0;
}
