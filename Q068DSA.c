#include <stdio.h>

#define V 6

void kahn(int g[V][V]) {
    int in[V] = {0}, q[V], f = 0, r = 0, i, j, u;

    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            if (g[i][j]) in[j]++;

    for (i = 0; i < V; i++)
        if (!in[i]) q[r++] = i;

    while (f < r) {
        u = q[f++];
        printf("%d ", u);
        for (v = 0; v < V; v++) {
            if (g[u][v] && --in[v] == 0) q[r++] = v;
        }
    }
}

int main() {
    int g[V][V] = {
        {0,0,0,0,0,0}, {0,0,0,0,0,0}, {0,0,0,1,0,0},
        {0,1,0,0,0,0}, {1,1,0,0,0,0}, {1,0,1,0,0,0}
    };
    kahn(g);
    return 0;
}
