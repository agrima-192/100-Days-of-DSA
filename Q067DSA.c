#include <stdio.h>

#define V 6

void dfs(int g[V][V], int u, int v[V], int s[V], int *t) {
    v[u] = 1;
    for (int i = 0; i < V; i++)
        if (g[u][i] && !v[i]) dfs(g, i, v, s, t);
    s[(*t)--] = u;
}

void topologicalSort(int g[V][V]) {
    int v[V] = {0}, s[V], t = V - 1;
    for (int i = 0; i < V; i++)
        if (!v[i]) dfs(g, i, v, s, &t);
    for (int i = 0; i < V; i++) printf("%d ", s[i]);
}

int main() {
    int g[V][V] = {
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 1, 0, 0, 0, 0},
        {1, 1, 0, 0, 0, 0},
        {1, 0, 1, 0, 0, 0}
    };
    topologicalSort(g);
    return 0;
}
