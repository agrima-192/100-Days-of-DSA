#include <stdio.h>

int adj[20][20], vis[20], n;

int dfs(int v, int p) {
    vis[v] = 1;
    for (int i = 0; i < n; i++) {
        if (adj[v][i]) {
            if (!vis[i]) {
                if (dfs(i, v)) return 1;
            } else if (i != p) return 1;
        }
    }
    return 0;
}

int main() {
    n = 3;
    adj[0][1] = adj[1][0] = 1;
    adj[1][2] = adj[2][1] = 1;
    adj[2][0] = adj[0][2] = 1;

    for (int i = 0; i < n; i++) {
        if (!vis[i] && dfs(i, -1)) {
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}
