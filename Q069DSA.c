#include <stdio.h>
#include <limits.h>

#define V 9

void dijkstra(int g[V][V], int s) {
    int d[V], v[V] = {0}, i, j, m, u;
    for (i = 0; i < V; i++) d[i] = INT_MAX;
    d[s] = 0;

    for (i = 0; i < V; i++) {
        m = INT_MAX;
        for (j = 0; j < V; j++) if (!v[j] && d[j] <= m) m = d[u = j];
        v[u] = 1;
        for (j = 0; j < V; j++)
            if (!v[j] && g[u][j] && d[u] != INT_MAX && d[u] + g[u][j] < d[j])
                d[j] = d[u] + g[u][j];
    }
    for (i = 0; i < V; i++) printf("%d %d\n", i, d[i]);
}

int main() {
    int g[V][V] = {{0,4,0,0,0,0,0,8,0},{4,0,8,0,0,0,0,11,0},{0,8,0,7,0,4,0,0,2},{0,0,7,0,9,14,0,0,0},{0,0,0,9,0,10,0,0,0},{0,0,4,14,10,0,2,0,0},{0,0,0,0,0,2,0,1,6},{8,11,0,0,0,0,1,0,7},{0,0,2,0,0,0,6,7,0}};
    dijkstra(g, 0);
    return 0;
}
