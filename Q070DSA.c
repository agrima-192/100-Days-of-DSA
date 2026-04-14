#include <stdio.h>
#include <limits.h>

struct Edge {
    int u, v, w;
};

void solve() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return;

    struct Edge edges[m];
    long long dist[n];

    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
    }
    dist[0] = 0;

    for (int i = 1; i <= n - 1; i++) {
        int updated = 0;
        for (int j = 0; j < m; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;
            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                updated = 1;
            }
        }
        if (!updated) break;
    }

    int hasNegativeCycle = 0;
    for (int i = 0; i < m; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;
        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            hasNegativeCycle = 1;
            break;
        }
    }

    if (hasNegativeCycle) {
        printf("NEGATIVE CYCLE\n");
    } else {
        for (int i = 0; i < n; i++) {
            if (dist[i] == INT_MAX) printf("INF ");
            else printf("%lld ", dist[i]);
        }
        printf("\n");
    }
}

int main() {
    solve();
    return 0;
}
