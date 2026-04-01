#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

int search(int arr[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == value) return i;
    }
    return -1;
}

struct Node* buildTree(int in[], int pre[], int inStart, int inEnd, int* preIndex) {
    if (inStart > inEnd) return NULL;

    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = pre[(*preIndex)++];
    node->left = node->right = NULL;

    if (inStart == inEnd) return node;

    int inIndex = search(in, inStart, inEnd, node->data);

    node->left = buildTree(in, pre, inStart, inIndex - 1, preIndex);
    node->right = buildTree(in, pre, inIndex + 1, inEnd, preIndex);

    return node;
}

void printPostOrder(struct Node* node) {
    if (node == NULL) return;
    printPostOrder(node->left);
    printPostOrder(node->right);
    printf("%d ", node->data);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int pre[n], in[n];
    for (int i = 0; i < n; i++) scanf("%d", &pre[i]);
    for (int i = 0; i < n; i++) scanf("%d", &in[i]);

    int preIndex = 0;
    struct Node* root = buildTree(in, pre, 0, n - 1, &preIndex);

    printPostOrder(root);
    printf("\n");

    return 0;
}
