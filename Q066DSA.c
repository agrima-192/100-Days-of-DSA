#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int recStack[MAX];
int n, e;

bool isCyclicUtil(int v) {
    if (visited[v] == 0) {
        visited[v] = 1;
        recStack[v] = 1;

        for (int i = 0; i < n; i++) {
            if (adj[v][i]) {
                if (!visited[i] && isCyclicUtil(i))
                    return true;
                else if (recStack[i])
                    return true;
            }
        }
    }
    recStack[v] = 0;
    return false;
}

bool isCyclic() {
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        recStack[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i] && isCyclicUtil(i))
            return true;
    }
    return false;
}

int main() {
    if (scanf("%d %d", &n, &e) != 2) return 0;

    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }

    if (isCyclic())
        printf("YES\n");

    return 0;
}
