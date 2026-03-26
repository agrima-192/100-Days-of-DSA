#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int val) {
    if (val == -1) return NULL;
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

struct Node* findLCA(struct Node* root, int n1, int n2) {
    if (root == NULL || root->data == n1 || root->data == n2) {
        return root;
    }

    struct Node* left_lca = findLCA(root->left, n1, n2);
    struct Node* right_lca = findLCA(root->right, n1, n2);

    if (left_lca && right_lca) return root;

    return (left_lca != NULL) ? left_lca : right_lca;
}

int main() {
    int n, n1, n2;
    if (scanf("%d", &n) != 1) return 0;

    int *arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    scanf("%d %d", &n1, &n2);

    struct Node** nodes = (struct Node**)malloc(n * sizeof(struct Node*));
    for (int i = 0; i < n; i++) nodes[i] = newNode(arr[i]);

    int child = 1;
    for (int i = 0; i < n && child < n; i++) {
        if (nodes[i] != NULL) {
            nodes[i]->left = nodes[child++];
            if (child < n) nodes[i]->right = nodes[child++];
        }
    }

    struct Node* lca = findLCA(nodes[0], n1, n2);
    if (lca) printf("%d\n", lca->data);

    return 0;
}
