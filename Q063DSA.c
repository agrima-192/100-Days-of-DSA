#include <stdio.h>
#include <stdlib.h>

struct Node {
    int v;
    struct Node* next;
};

void DFS(int s, struct Node** adj, int* vis) {
    vis[s] = 1;
    printf("%d ", s);
    for (struct Node* t = adj[s]; t; t = t->next)
        if (!vis[t->v]) DFS(t->v, adj, vis);
}

void addEdge(struct Node** adj, int u, int v) {
    struct Node* n = malloc(sizeof(struct Node));
    n->v = v; n->next = adj[u]; adj[u] = n;
}

int main() {
    int n, s, e, u, v;
    scanf("%d %d", &n, &e);
    struct Node** adj = calloc(n, sizeof(struct Node*));
    int* vis = calloc(n, sizeof(int));

    for (int i = 0; i < e; i++) {
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }

    scanf("%d", &s);
    DFS(s, adj, vis);
    return 0;
}
